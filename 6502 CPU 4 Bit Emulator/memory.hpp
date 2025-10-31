#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <array>
#include <print>
#include <memory>

#include "types.hpp"

constexpr int MAX_MEMORY = 64 * 1024;

class Memory {
public:

  Memory() : mem(std::make_unique<std::array<u8, MAX_MEMORY>>())
  {
    mem->fill(0x00);
  }

  uint8_t Read_Byte(u16 address);
  void Write_Byte(u16 address, u8 value);

  void Reset();
private:
  std::unique_ptr<std::array<u8, MAX_MEMORY>> mem;
};

#endif // MEMORY_HPP