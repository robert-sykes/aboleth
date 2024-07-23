#include "rom/rom.h"

void loadROM(const char* filename) {
	FILE* rom = fopen(filename, "rb");

	if (!rom) {
		perror("Failed to open ROM file.");
	}

	uint8_t buffer[0x10000] = { 0 };
	size_t data = fread(buffer, sizeof(uint8_t), 0x10000, rom);

	if (data == 0) {
		perror("Failed to read ROM file");
		fclose(rom);
		return 1;
	}

	writeByteArrayToMemory(buffer, data);
	printf("Loaded %zu bytes from ROM\n", data);

	fclose(rom);
}