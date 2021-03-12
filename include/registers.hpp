#pragma once

namespace jetsonbatt::registers {
const unsigned short int status = 0x00;
const unsigned short int current = 0x0A;
const unsigned int avg_current = 0x0B;
const unsigned int minmax_current = 0x1C;
const unsigned int avg_temp = 0x16;
const unsigned int voltage = 0x09;
const unsigned int minmax_voltage = 0x1B;
const unsigned int state_of_charge = 0x06;
const unsigned int cycles = 0x17;
const unsigned int time_to_empty = 0x11;
const unsigned int config2 = 0xBB;

}  // namespace jetsonbatt::registers
