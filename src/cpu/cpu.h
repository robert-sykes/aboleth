#include <stdio.h>
#include <stdbool.h>
#include "cpu/instructions.h"
#include "cpu/registers.h"
#include "mem/memory.h"

void executeInstruction(abInstruction instruction);

void initCPU(uint16_t startAddr);
void stepCPU();

bool cpuHasHalted();