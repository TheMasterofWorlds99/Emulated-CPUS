#ifndef CPUS_CPU_HPP
#define CPUS_CPU_HPP

#include <cstdint>
#include "Bus.hpp"

class CPU {
public:
  u8 Accumulator, X_Reg, Y_Reg;
  u8 SP;
  u16 PC;

  struct Status {
    bool C : 1;
    bool Z : 1;
    bool I : 1;
    bool D : 1;
    bool V : 1;
    bool N : 1;
  } SR{};

  CPU(u8 Accumulator, u8 X_Reg, u8 Y_Reg, u8 SP, u16 PC) :
    Accumulator(Accumulator), X_Reg(X_Reg), Y_Reg(Y_Reg), SP(SP), PC(PC)
  {
  }

  void* bus{};

  u8 (*Read_Byte)(void* ctx, u16 addr){};
  void (*Write_Byte)(void* ctx, u16 addr, u8 val){};

  int fetchOpcode();

  void executeOpcode(int opcode);
  void step();

  void cpu_init(void* bus_ctx, u8 (*read_func)(void*, u16), void (*write_func)(void*, u16, u8));
};

#endif //CPUS_CPU_HPP