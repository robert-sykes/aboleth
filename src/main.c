#include <stdio.h>
#include "cpu/cpu.h"
#include "rom/rom.h"
#include "mem/memory.h"

int main() {
	initCPU(0x100);

	loadROM("roms/cpu_instrs.gb");
	//writeToMemory(0x100, 0x01);
	//writeToMemory(0x101, 0x34);
	//writeToMemory(0x102, 0x12);

	while (!cpuHasHalted()) {
		stepCPU();
	}

	return 0;
}