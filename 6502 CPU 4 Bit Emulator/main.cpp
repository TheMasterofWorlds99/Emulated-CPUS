#include "CPU.hpp"
#include "Bus.hpp"

#include <print>

//Test of the Memory System
int main()
{
	CPU cpu = { 0, 0, 0, 0, 0x0000 };
	Bus bus;

	cpu.Write_Byte(bus, 0x00, 0x00); //LDA
	cpu.Write_Byte(bus, 0x01, 0x20); //32
	cpu.Write_Byte(bus, 0x02, 0x01); //ADC
	cpu.Write_Byte(bus, 0x03, 0x4A); //74

	for (int i = 0; i < 2; i++) {
		cpu.step(bus);
	}

	std::println("Accumulator: 0x{:02X}", cpu.Accumulator);

	return 0;
}