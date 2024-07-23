#include <stdio.h>
#include "cpu/cpu.h"
#include "rom/rom.h"
#include "mem/memory.h"

int main() {
	initCPU(0x100);

	loadROM("roms/cpu_instrs.gb");

	while (!cpuHasHalted()) {
		stepCPU();
	}

	return 0;
}