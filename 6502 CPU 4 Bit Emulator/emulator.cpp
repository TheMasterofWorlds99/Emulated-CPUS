#include "emulator.hpp"

#include <iostream>

void Emulator::LoadProgram(const std::string& hex_string) {
   std::stringstream ss(hex_string);
   std::string hex_byte;
   u16 address = 0x0000;

   while (ss >> hex_byte) {
    u8 byte = static_cast<u8>(std::stoul(hex_byte, nullptr, 16));
    bus.Write_Byte(address, byte);
    address++;
  }
  std::println("Program loaded into memory.");
}

void Emulator::Run() {
  while (true) {
    cpu.step();

    if (cpu.PC >= 0x06) {
      break;
    }
  }
}

void Emulator::PrintAccumulator() {
  std::println("Current Value in the Accumulator: 0x{:02X}", cpu.Accumulator);
}

void Emulator::PrintMemoryValue(u16 address) {
  u8 value = bus.Read_Byte(address);
  std::println("Value at memory address 0x{:02X} is 0x{:02X}", address, value);
}