__all__ = ["register", "serial_addresses"]

from collections import namedtuple
from typing import NamedTuple

_registers_d = {
    "status": 0x00,
    "current": 0x0A,
    "avg_current": 0x0B,
    "minmax_current": 0x1C,
    "avg_temp": 0x16,
    "voltage": 0x09,
    "minmaxvoltage": 0x1B,
    "state_of_charge": 0x06,
    "cycles": 0x17,
    "time_to_empty": 0x11,
    "config2": 0xBB,
}


serial_addresses = [
    0xDF,  # this is a free address, shows 0x00
    0xD4,
    0xD5,
    0xD9,
    0xDA,
    0xDC,
    0xDD,
    0xDE,
]


class Register(NamedTuple):
    status: int = -1
    current: int = -1
    avg_current: int = -1
    minmax_current: int = -1
    avg_temp: int = -1
    voltage: int = -1
    minmaxvoltage: int = -1
    state_of_charge: int = -1
    cycles: int = -1
    time_to_empty: int = -1
    config2: int = -1


register = Register(**_registers_d)
