#include "CPU.hpp"

int CPU::fetchOpcode() {
  //TODO
  return 0;
}

void CPU::executeOpcode(int opcode) {
  //MASSIVE SWITCH STATEMENT
  switch (opcode) {
    //LDA
    case 0x00:
      break;
      //TODO
    case 0x01:
      break;
    default:
      break;
      //TODO
  }
}

void CPU::step() {
  int op = fetchOpcode();
  executeOpcode(op);
}