#pragma once

namespace jetsonbatt::parameters {
const unsigned int RSENSE = 5;            // mohms
const float CURRENT_RES = 1.5625 / 1000;  // 1.5625uA -> mA
const float VOLTAGE_RES = 1.25 / 1000;    // 1.25mV
const float TIME_RES = 5.625;             // can't remember what this is
const unsigned int NUMBER_CELLS = 4;
}  // namespace jetsonbatt::parameters
