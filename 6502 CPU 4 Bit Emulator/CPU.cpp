#include "CPU.hpp"

#include <print>

u8 CPU::fetchOpcode() {
  return Read_Byte(bus, PC++);
}

void CPU::executeOpcode(u8 opcode) {
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

    //SBC
    case 0xE9: //Immediate
    {
      value = Fetch_Immediate();
      u16 difference = Accumulator - value - (1 - SR.C);

      SR.C = (difference > 0xFF);
      SR.V = (~(Accumulator ^ value) & (Accumulator ^ difference) & 0x80) != 0;

      Accumulator = static_cast<u8>(difference);
      Set_ZN_Flags(Accumulator);
    }
      break;

    case 0xE5: //Zero Page
    {
      value = Read_Byte(bus, Addr_ZeroPage());
      u16 difference = Accumulator - value - (1 - SR.C);

      SR.C = (difference > 0xFF);
      SR.V = (~(Accumulator ^ value) & (Accumulator ^ difference) & 0x80) != 0;

      Accumulator = static_cast<u8>(difference);
      Set_ZN_Flags(Accumulator);
    }
      break;

    case 0xED: //Absolute
    {
      value = Read_Byte(bus, Addr_Absolute());
      u16 difference = Accumulator - value - (1 - SR.C);

      SR.C = (difference > 0xFF);
      SR.V = (~(Accumulator ^ value) & (Accumulator ^ difference) & 0x80) != 0;

      Accumulator = static_cast<u8>(difference);
      Set_ZN_Flags(Accumulator);
    }
      break;

    //Break
    case 0x00:
      SR.B = true;
      break;

    default:
      std::println("ERR: Unknown Opcode: 0x{:02X} at PC 0x{:02X}", opcode, PC - 1);
      SR.B = true;
      break;
  }
}

void CPU::step() {
  u8 op = fetchOpcode();
  executeOpcode(op);
}

CPU::CPU(void* bus_ctx, u8(*read_func)(void*, u16), void (*write_func)(void*, u16, u8)) {
  this->Accumulator = this->X_Reg = this->Y_Reg = 0;
  this->SP = 0xFD; // Stack usually starts high
  this->PC = 0x0000;
  this->SR = { false }; // Initialize status register

  this->bus = bus_ctx;
  this->Read_Byte = read_func;
  this->Write_Byte = write_func;
}