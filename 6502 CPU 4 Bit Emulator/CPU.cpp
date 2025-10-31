#include "CPU.hpp"

Opcode CPU::fetchOpcode() {
  return static_cast<Opcode>(mem.Read_Byte(PC));
}

void CPU::executeOpcode(Opcode opcode) {
  switch (opcode) {
    case Opcode::LDA:
      //LDA helper function
    case Opcode::STA:
      //STA helper function
    case Opcode::ADD:
      //ADD helper function
    default:
      break;
  }
}

void CPU::step() {
  Opcode op = fetchOpcode();
  executeOpcode(op);
}