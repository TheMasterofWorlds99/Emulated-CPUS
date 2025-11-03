#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include "CPU.hpp"
#include "Bus.hpp"

#include <string>
#include <sstream>
#include <print>

class Emulator {
public:
  Emulator() : bus(), cpu(&bus, Bus::Read_Wrapper, Bus::Write_Wrapper)
  {
    std::println("Emulator Initialized and CPU is connected to Bus.");
  }

  void LoadProgram(const std::string& hex_string);
  void Run();

  void PrintAccumulator();
  void PrintMemoryValue(u16 address);
  void PrintStatus();

private:
  Bus bus;
  CPU cpu;
};

#endif //EMULATOR_HPP