#include "CPU.hpp"

#include <print>

int CPU::fetchOpcode() {
  return Read_Byte(bus, PC++);
}

void CPU::executeOpcode(int opcode) {
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

void CPU::step() {
  int op = fetchOpcode();
  executeOpcode(op);
}

void CPU::cpu_init(void *bus_ctx, u8 (*read_func)(void *, u16), void (*write_func)(void *, u16, u8)) {
  this->Accumulator = this->X_Reg = this->Y_Reg = 0;
  this->SP = 0x00;
  this->PC = 0x0000;
  this->SR = { 0, 0, 0, 0, 0, 0 }; // Initialize status register

  this->bus = bus_ctx;
  this->Read_Byte = read_func;
  this->Write_Byte = write_func;
}