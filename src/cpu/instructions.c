#include "cpu/instructions.h"

abInstruction _validInstructions[] = {
	{ NOP, "NOP" },
	{ LD_BC, "LD BC, n16" }
};

size_t _numInstructions = sizeof(_validInstructions) / sizeof(_validInstructions[0]);

bool isValidInstruction(uint8_t opcode) {

	for (size_t i = 0; i < _numInstructions; ++i) {
		if (_validInstructions[i].opcode == opcode) {
			return true;
		}
	}

	return false;
}

abInstruction* findInstruction(uint8_t opcode) {
	for (size_t i = 0; i < _numInstructions; ++i) {
		if (_validInstructions[i].opcode == opcode) {
			return &_validInstructions[i];
		}
	}

	return NULL;
}