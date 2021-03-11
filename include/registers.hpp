#pragma once

namespace jetsonbatt::registers {
const unsigned int status = 0x00;
const unsigned int current = 0x0A;
}  // namespace jetsonbatt::registers

// _registers_d = {
//     "status": 0x00,
//     "current": 0x0A,
//     "avg_current": 0x0B,
//     "minmax_current": 0x1C,
//     "avg_temp": 0x16,
//     "voltage": 0x09,
//     "minmaxvoltage": 0x1B,
//     "state_of_charge": 0x06,
//     "cycles": 0x17,
//     "time_to_empty": 0x11,
//     "config2": 0xBB,
// }

// serial_addresses = [
//     0xDF,  # this is a free address, shows 0x00
//     0xD4,
//     0xD5,
//     0xD9,
//     0xDA,
//     0xDC,
//     0xDD,
//     0xDE,
// ]