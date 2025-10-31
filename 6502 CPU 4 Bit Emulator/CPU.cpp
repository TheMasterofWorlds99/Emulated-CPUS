#include "CPU.hpp"

#include <print>

//Let's ignore the really bad Read and Write functions
u8 CPU::Read_Byte(Bus& bus, u16 address) {
  u8(Bus:: * FuncPtr)(u16) = &Bus::Read_Byte;
  return (bus.*FuncPtr)(address);
}

void CPU::Write_Byte(Bus& bus, u16 address, u8 value) {
  void(Bus:: * FuncPtr)(u16, u8) = &Bus::Write_Byte;
  (bus.*FuncPtr)(address, value);
}

int CPU::fetchOpcode(Bus& bus) {
  return Read_Byte(bus, PC++);
}

void CPU::executeOpcode(int opcode, Bus& bus) {
  u8 value;
  //MASSIVE SWITCH STATEMENT
  switch (opcode) {
    //LDA (Load)
    case 0x00: //Immediate
      value = Read_Byte(bus, PC++);
      Accumulator = value;
      std::println("LDA Immediate: Loaded 0x{:X} into the Accumulator", value);
      break;
    //ADC
    case 0x01:
      value = Read_Byte(bus, PC++);
      Accumulator += value;
      std::println("ADC Immediate: Added 0x{:X} to the Accumulator", value);
      break;
    default:
      break;
  }
}

void CPU::step(Bus& bus) {
  int op = fetchOpcode(bus);
  executeOpcode(op, bus);
}