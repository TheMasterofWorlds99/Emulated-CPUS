#include <cstdint>

class CPU {
public:
  uint8_t Accumulator;
  uint8_t X_Reg;
  uint8_t Y_Reg;
  uint8_t SP;
  uint16_t PC;

  CPU(uint8_t Accumulator, uint8_t X_Reg, uint8_t Y_Reg, uint8_t SP, uint16_t PC) :
    Accumulator(Accumulator), X_Reg(X_Reg), Y_Reg(Y_Reg), SP(SP), PC(PC)
  {
  }


private:
};