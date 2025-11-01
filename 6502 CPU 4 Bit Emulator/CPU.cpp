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
    case 0xA9: //Immediate
      Accumulator = Fetch_Immediate();
      Set_ZN_Flags(Accumulator);
      break;

    case 0xA5: //Zero Page
      Accumulator = Read_Byte(bus, Addr_ZeroPage());
      Set_ZN_Flags(Accumulator);
      break;

    case 0xAD: //Absolute
      Accumulator = Read_Byte(bus, Addr_Absolute());
      Set_ZN_Flags(Accumulator);
      break;

    //STA
    case 0x85: //Zero Page
      Write_Byte(bus, Addr_ZeroPage(), Accumulator);
      break;

    case 0x8D: //Absolute
      Write_Byte(bus, Addr_Absolute(), Accumulator);
      break;

    //ADC
    case 0x69: //Immediate
    {
      value = Fetch_Immediate();
      u16 sum = Accumulator + value + SR.C;

      SR.C = (sum > 0xFF);
      SR.V = (~(Accumulator ^ value) & (Accumulator ^ sum) & 0x80) != 0;

      Accumulator = static_cast<u8>(sum);
      Set_ZN_Flags(Accumulator);
    }
      break;

    case 0x65: //Zero Page
    {
      value = Read_Byte(bus, Addr_ZeroPage());
      u16 sum = Accumulator + value + SR.C;

      SR.C = (sum > 0xFF);
      SR.V = (~(Accumulator ^ value) & (Accumulator ^ sum) & 0x80) != 0;

      Accumulator = static_cast<u8>(sum);
      Set_ZN_Flags(Accumulator);
    }
      break;

    case 0x6D: //Absolute
    {
      value = Read_Byte(bus, Addr_Absolute());
      u16 sum = Accumulator + value + SR.C;

      SR.C = (sum > 0xFF);
      SR.V = (~(Accumulator ^ value) & (Accumulator ^ sum) & 0x80) != 0;

      Accumulator = static_cast<u8>(sum);
      Set_ZN_Flags(Accumulator);
    }
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