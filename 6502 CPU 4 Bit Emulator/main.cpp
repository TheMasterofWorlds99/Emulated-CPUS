#include "emulator.hpp"

//Test of the Emulator System
int main()
{
	Emulator emulator;

	//LDA (Immediate) -> 0xF9
	//SBC (Immediate) -> 0xF2
	//STA (Zero Page) -> 0x7F
	//BRK == 0x00
	std::string program = "A9 49 E9 F2 85 7F";

	emulator.LoadProgram(program);

	emulator.Run();

	emulator.PrintAccumulator();
	emulator.PrintMemoryValue(0x7F);
	emulator.PrintStatus();

	return 0;
}