#ifndef CPUS_CPU_HPP
#define CPUS_CPU_HPP

#include <cstdint>
#include "types.hpp"

class CPU {
public:
  u8 Accumulator, X_Reg, Y_Reg;
  u8 SP;
  u16 PC;

  struct Status {
    u1 C : 1;
    u1 Z : 1;
    u1 I : 1;
    u1 D : 1;
    u1 V : 1;
    u1 N : 1;
  } SR{};

  CPU(void* bus_ctx, u8(*read_func)(void*, u16), void (*write_func)(void*, u16, u8));

  void* bus{};

  u8 (*Read_Byte)(void* ctx, u16 addr){};
  void (*Write_Byte)(void* ctx, u16 addr, u8 val){};

  int fetchOpcode();

  void executeOpcode(int opcode);
  void step();

private:
  void Set_ZN_Flags(u8 value) {
    SR.Z = (value == 0);
    SR.N = (value & 0x80) != 0;
  }

  u8 Fetch_Immediate() {
    return Read_Byte(bus, PC++);
  }

  u16 Addr_ZeroPage() {
    return Read_Byte(bus, PC++);
  }

  u16 Addr_Absolute() {
    u8 lo = Read_Byte(bus, PC++);
    u8 hi = Read_Byte(bus, PC++);

    return (hi << 8) | lo;
  }
};

#endif //CPUS_CPU_HPP