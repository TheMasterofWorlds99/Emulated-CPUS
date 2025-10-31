#include "memory.hpp"

//Test of the Memory System
int main()
{
	Memory memory;

	memory.Write_Byte(0xA61, 145 - 12);
	memory.Write_Byte(0xA60, 937 / 817); //Rounds to 1

	u8 x = memory.Read_Byte(0xA61);
	u8 y = memory.Read_Byte(0xA60);
	u8 z = memory.Read_Byte(0xA23);

	std::println("{}, {}, {}", x, y, z);
	return 0;
}