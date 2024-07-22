#include <stdio.h>
#include "cpu/cpu.h"
#include "mem/memory.h"

int main() {
	writeToMemory(0x1000, NOP);

	initCPU(0x1000);
	stepCPU();

	return 0;
}