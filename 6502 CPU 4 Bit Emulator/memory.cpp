#include "memory.hpp"
#include <print>

uint8_t Memory::Read_Byte(uint16_t address) {
  if (address < 0x00 || address >= MAX_MEMORY)
  {
    std::println("Invalid Address. Attempting to Access Data at {}", address);
  }

  return mem[address];
}

void Memory::Write_Byte(uint16_t address, uint8_t value) {
  if (address < 0x00 || address >= MAX_MEMORY)
  {
    std::println("Invalid Address. Attempting to Access Data at {}", address);
  }

  mem[address] = value;
}

void Memory::Reset() {
  std::fill(mem.begin(), mem.end(), 0x00);
}