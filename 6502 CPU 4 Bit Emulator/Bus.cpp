#include "Bus.hpp"
#include <print>
#include <format>

u8 Bus::Read_Byte(u16 address) const {
  if (address > MAX_MEMORY) {
    std::println("Invalid Address! Attempting to Read Address: {:X}", address);
    return 0;
  }

  if (address < MAX_WRAM) {
    return WRAM.at(address);
  }
  else if (address > MAX_WRAM && address < MAX_WRAM + MAX_VRAM) {
    address -= MAX_WRAM;
    return VRAM.at(address);
  }
  else if (address > MAX_WRAM + MAX_VRAM && address < MAX_WRAM + MAX_VRAM + MAX_ROM) {
    address -= (MAX_WRAM + MAX_VRAM);
    return ROM.at(address);
  }
  else {
    std::println("Address Not Found in any memory device! Attempting to Read Address: {:X}", address);
    return 0;
  }
}

void Bus::Write_Byte(u16 address, u8 value) {
  if (address > MAX_MEMORY) {
    std::println("Invalid Address! Attempting to Access Write Address: {:X}", address);
    return;
  }

  if (address < MAX_WRAM) {
    WRAM.at(address) = value;
  }
  else if (address > MAX_WRAM && address < MAX_WRAM + MAX_VRAM) {
    address -= MAX_WRAM;
    VRAM.at(address) = value;
  }
  else if (address > MAX_WRAM + MAX_VRAM && address < MAX_WRAM + MAX_VRAM + MAX_ROM) {
    address -= (MAX_WRAM + MAX_VRAM);
    std::println("Attempting to Write Read Only Memory, Attempting to Write the ROM Address: {:X}", address);
  }
  else {
    std::println("Address Not Found in any memory device! Attempting to Write to Address: {:X}", address);
    return;
  }
}

void Bus::Reset_WRAM() {
  WRAM.fill(0x00);
}

void Bus::Reset_VRAM() {
  VRAM.fill(0x00);
}