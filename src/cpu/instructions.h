#include <stdint.h>
#include <stdbool.h>

typedef enum {
	NOP = 0x00,
	LD_BC = 0x01
} abOpcode;

typedef struct {
	abOpcode opcode;
	const char* alias;
} abInstruction;

bool isValidInstruction(uint8_t opcode);
abInstruction* findInstruction(uint8_t opcode);