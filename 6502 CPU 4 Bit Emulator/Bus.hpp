#ifndef BUS_HPP
#define BUS_HPP

#include <array>
#include <memory>

#include "types.hpp"

constexpr int MAX_WRAM = 12 * 1024;
constexpr int MAX_VRAM = 12 * 1024;
constexpr int MAX_ROM = 256;

constexpr int MAX_MEMORY = MAX_WRAM + MAX_VRAM + MAX_ROM;

class Bus {
public:

  Bus() : WRAM(), VRAM(), ROM()
  {
    WRAM.fill(0x00);
    VRAM.fill(0x00);
  }

  [[nodiscard]] u8 Read_Byte(u16 address) const;
  void Write_Byte(u16 address, u8 value);

  void Reset_WRAM();
  void Reset_VRAM();

private:
  std::array<u8, MAX_WRAM> WRAM;
  std::array<u8, MAX_VRAM> VRAM;
  std::array<u8, MAX_ROM> ROM;
};

#endif // BUS_HPP