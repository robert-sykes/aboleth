#include "cpu/cpu.h"

abRegisters _registers = {0};

void executeInstruction(abInstruction* instruction) {
	if (instruction != NULL) {
		switch (instruction->opcode) {
		case NOP:
			_registers.PC += 1;
			break;

		case LD_BC:
			uint8_t lowByte = readFromMemory(_registers.PC + 1);
			uint8_t highByte = readFromMemory(_registers.PC + 2);

			_registers.BC = (highByte << 8) | lowByte;

			_registers.PC += 3; // Move past the instruction opcode and data/operands.
			break;

		default:
			printf("Unhandled Hex: %s\n", instruction->alias);
			break;
		}
	}
}

void initCPU(uint16_t startAddr) {
	_registers.PC = startAddr;
}

void stepCPU() {
	uint8_t opcode = readFromMemory(_registers.PC);
	executeInstruction(findInstruction(_registers.PC));
}

bool cpuHasHalted() {
	return _registers.PC >= 0xFFFF;
}