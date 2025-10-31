#ifndef CPUS_CPU_HPP
#define CPUS_CPU_HPP

#include <cstdint>
#include "memory.hpp"

enum class Opcode : u8 {
  LDA = 0xA9,
  STA = 0x8D,
  ADC = 0x69
};

class CPU {
public:
  u8 Accumulator, X_Reg, Y_Reg;
  u8 SP;
  u16 PC;

  CPU(u8 Accumulator, u8 X_Reg, u8 Y_Reg, u8 SP, u16 PC) :
    Accumulator(Accumulator), X_Reg(X_Reg), Y_Reg(Y_Reg), SP(SP), PC(PC)
  {
  }

  Opcode fetchOpcode();

  void executeOpcode(Opcode opcode);
  void step();

private:
  Memory mem;
};

#endif //CPUS_CPU_HPP