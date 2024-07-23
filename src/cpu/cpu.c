#include "cpu/cpu.h"

abRegisters _registers = {0};

void executeInstruction(abInstruction instruction) {
	switch (instruction) {
	case NOP:
		_registers.PC += 1;
		break;
	}
}

void initCPU(uint16_t startAddr) {
	_registers.PC = startAddr;
}

void stepCPU() {
	uint8_t opcode = readFromMemory(_registers.PC);
	executeInstruction(opcode);

	printf("Value: 0x%04X\n", _registers.PC);
}

bool cpuHasHalted() {
	return _registers.PC >= 0xFFFF;
}