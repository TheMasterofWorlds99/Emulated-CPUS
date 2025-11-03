#include "emulator.hpp"

//Test of the Emulator System
int main()
{
	Emulator emulator;

	//LDA (Immediate) -> 0xF9
	//ADC (Absolute) -> 0x02 and 0x00 to make 0x0002
	//STA (Zero Page) -> 0x7F
	//BRK == 0x00
	std::string program = "A9 49 6D 02 00 85 7F";

	emulator.LoadProgram(program);

	emulator.Run();

	emulator.PrintAccumulator();
	emulator.PrintMemoryValue(0x7F);

	return 0;
}