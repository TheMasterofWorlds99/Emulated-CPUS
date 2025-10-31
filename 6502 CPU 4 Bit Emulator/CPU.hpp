#ifndef CPUS_CPU_HPP
#define CPUS_CPU_HPP

#include <cstdint>
#include <functional>

#include "Bus.hpp"
#include "types.hpp"

class CPU {
public:
  u8 Accumulator, X_Reg, Y_Reg;
  u8 SP;
  u16 PC;

  CPU(u8 Accumulator, u8 X_Reg, u8 Y_Reg, u8 SP, u16 PC) :
    Accumulator(Accumulator), X_Reg(X_Reg), Y_Reg(Y_Reg), SP(SP), PC(PC)
  {
  }

  u8 Read_Byte(Bus& bus, u16 address);
  void Write_Byte(Bus& bus, u16 address, u8 value);

  int fetchOpcode(Bus& bus);

  void executeOpcode(int opcode, Bus& bus);
  void step(Bus& bus);
};

#endif //CPUS_CPU_HPP