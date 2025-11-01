#include "emulator.hpp"

#include <print>

//Test of the Memory System
int main()
{
	Emulator emulator;

	//LDA 0xA9
	//ADC 0x42
	//STA 0x7F
	std::string program = "00 A9 02 42 01 7F";

	emulator.LoadProgram(program);

	emulator.Run();

	emulator.PrintAccumulator();
	emulator.PrintMemoryValue(0x7F);

	return 0;
}