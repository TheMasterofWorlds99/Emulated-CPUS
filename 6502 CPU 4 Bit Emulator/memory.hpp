#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <array>
#include <memory>

#include "types.hpp"

constexpr int MAX_MEMORY = 64 * 1024;

class Memory {
public:

  Memory() : mem(std::make_unique<std::array<u8, MAX_MEMORY>>())
  {
    mem->fill(0x00);
  }

  [[nodiscard]] u8 Read_Byte(u16 address) const;
  void Write_Byte(u16 address, u8 value) const;

  void Reset() const;
private:
  std::unique_ptr<std::array<u8, MAX_MEMORY>> mem;
};

#endif // MEMORY_HPP