#include "CPU.hpp"

#include <print>

int CPU::fetchOpcode() {
  return Read_Byte(bus, PC++);
}

void CPU::executeOpcode(int opcode) {
  u8 value;
  //MASSIVE SWITCH STATEMENT
  switch (opcode) {
    //LDA
    case 0x00: //Immediate
      value = Read_Byte(bus, PC++);
      Accumulator = value;
      Set_ZN_Flags(Accumulator);
      std::println("LDA Immediate: Loaded 0x{:02X} into the Accumulator", value);
      break;
    //STA
    case 0x01:
      value = Read_Byte(bus, PC++);
      Write_Byte(bus, value, Accumulator);
      std::println("STA Zero Page: Stored Accumulator (0x{:02X}) at address 0x{:02X}", Accumulator, value);
      break;
    //ADC
    case 0x02:
      value = Read_Byte(bus, PC++);
      Accumulator += value;
      Set_ZN_Flags(Accumulator);
      std::println("ADC Immediate: Added 0x{:02X} to the Accumulator", value);
      break;

    default:
      break;
  }
}

void CPU::step() {
  int op = fetchOpcode();
  executeOpcode(op);
}

CPU::CPU(void* bus_ctx, u8(*read_func)(void*, u16), void (*write_func)(void*, u16, u8)) {
  this->Accumulator = this->X_Reg = this->Y_Reg = 0;
  this->SP = 0xFD; // Stack usually starts high
  this->PC = 0x0000;
  this->SR = { 0 }; // Initialize status register

  this->bus = bus_ctx;
  this->Read_Byte = read_func;
  this->Write_Byte = write_func;
}