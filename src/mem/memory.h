#include <stdint.h>
#include <stdio.h>

void writeToMemory(uint8_t address, uint8_t value);
void writeByteArrayToMemory(const uint8_t* data, size_t size);
uint8_t readFromMemory(uint8_t address);