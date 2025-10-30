#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <array>
#include <print>
#include <memory>

constexpr int MAX_MEMORY = 64 * 1024;

class Memory {
public:

  Memory() :
    memory(std::make_unique<std::array<uint8_t, 65536>>()),
    mem(*memory)
  {
  }

  uint8_t Read_Byte(uint16_t address);
  void Write_Byte(uint16_t address, uint8_t value);

  void Reset();
private:
  std::unique_ptr<std::array<uint8_t, MAX_MEMORY>> memory = std::make_unique<std::array<uint8_t, MAX_MEMORY>>();
  std::array<uint8_t, 65536>& mem;
};

#endif // MEMORY_HPP