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

    if (cpu.SR.B == true) {
      break;
    }
  }
}

void Emulator::PrintAccumulator() {
  if (cpu.SR.B == true) {
    return;
  }

  std::println("Current Value in the Accumulator: 0x{:02X}", cpu.Accumulator);
}

void Emulator::PrintMemoryValue(u16 address) {
  u8 value = bus.Read_Byte(address);
  std::println("Value at memory address 0x{:02X} is 0x{:02X}", address, value);
}

void Emulator::PrintStatus() {
  std::println("Status Break: {}", static_cast<int>(cpu.SR.B));
  std::println("Status Zero: {}", static_cast<int>(cpu.SR.Z));
  std::println("Status Interrupt Disable: {}", static_cast<int>(cpu.SR.I));
  std::println("Status Decimal: {}", static_cast<int>(cpu.SR.D));
  std::println("Status Overflow: {}", static_cast<int>(cpu.SR.V));
  std::println("Status Carry: {}", static_cast<int>(cpu.SR.C));
  std::println("Status Negative: {}", static_cast<int>(cpu.SR.N));
}
