#include "CPU.hpp"
#include "memory.hpp"

#include <print>

//Test of the Memory System
int main()
{
	Memory memory;

	memory.Write_Byte(0xA61, static_cast<u8>(Opcode::ADC));
	memory.Write_Byte(0xA62, 194 - 19 * 0.5 / 1);

	u8 x = memory.Read_Byte(0xA61);
	u8 y = memory.Read_Byte(0xA62);
	u8 z = memory.Read_Byte(0xA23);

	std::println("{}, {}, {}", x, y, z);
	return 0;
}