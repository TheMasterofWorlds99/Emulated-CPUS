#include "CPU.hpp"
#include "Bus.hpp"

#include <print>

//Test of the Memory System
int main()
{
	Bus bus;

	u16 Address = 0x50AA;

	bus.Write_Byte(Address, 0xAA);

	u8 x = bus.Read_Byte(Address);

	std::println("Byte Value at Address 0x{:X} is 0x{:X}", Address, x);
	return 0;
}