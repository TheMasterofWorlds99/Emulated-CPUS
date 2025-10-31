#include "memory.hpp"
#include <print>

uint8_t Memory::Read_Byte(u16 address) const {
  if (address >= MAX_MEMORY)
  {
    std::println("Invalid Address. Attempting to Access Data at {}", address);
    return 0;
  }

  return (*mem)[address];
}

void Memory::Write_Byte(u16 address, u8 value) const {
  if (address >= MAX_MEMORY)
  {
    std::println("Invalid Address. Attempting to Access Data at {}", address);
    return;
  }

  (*mem)[address] = value;
}

void Memory::Reset() const {
  mem->fill(0x00);
}
