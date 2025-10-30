#include "memory.hpp"

//Test of the Memory System
int main()
{
	Memory memory;

	memory.Write_Byte(0xA61, 0b1101011);
	memory.Write_Byte(0xA60, 0xAA);

	auto x = memory.Read_Byte(0xA61);
	auto y = memory.Read_Byte(0xA60);
	auto z = memory.Read_Byte(0xA23);

	std::println("{}, {}, {}", x, y, z);
	return 0;
}