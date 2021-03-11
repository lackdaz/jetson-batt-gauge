// def get_voltage(x: int) -> float:  # 0.2mV
//     return x * (VOLTAGE_RES / 16) * NUMBER_CELLS

// def get_minmax_voltage(x: int) -> float:  # 0.2mV
//     return x * 0.02 * NUMBER_CELLS

// # minmax res- > 0.4mV / rsense -> 5 mohms
// def get_minmax_current(x: int) -> float:
//     return x * 0.4 / RSENSE

// def get_current(x: int) -> float:  # res -> 40mV, rsense -> 5 mohms
//     return x * CURRENT_RES / RSENSE

// def get_temp(x: int) -> float:  # reading only upper byte for 1°C res
//     return x >> 8

// def get_time(x: int) -> float:  # convert to minutes
//     return x * TIME_RES / 60.0

// def get_cycles(x: int) -> float:  # convert to cycles for 1% res
//     return x / 100.0

void get_voltage(int x) {}