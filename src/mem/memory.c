#include "mem/memory.h"

uint8_t _memory[0x10000]; // 64KB memory

void writeToMemory(uint8_t address, uint8_t value) {
	_memory[address] = value;
}

void writeByteArrayToMemory(const uint8_t* data, size_t size) {
	for (size_t i = 0; i < size; i++) {
		_memory[i] = data[i];
	}
}

uint8_t readFromMemory(uint8_t address) {
	return _memory[address];
}