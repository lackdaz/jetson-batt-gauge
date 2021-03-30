__all__ = ["Battery"]

import sys
import struct
from time import sleep
from typing import Optional, List

from .conversion import *
from .registers import register
from .bitwise import *
from .bus_context import *


class Battery:
    address: int = 0x36
    charge_level: Optional[float] = None
    avg_current: Optional[float] = None
    status: List[int] = [] * 10
    spot_current: Optional[float] = None
    avg_temp: Optional[float] = None
    cycles: Optional[float] = None
    time_remaining: Optional[float] = None
    serial_number: Optional[int] = None
    voltage: Optional[float] = None

    @classmethod
    def init(cls, address: int = 0x36):
        with open_i2c_bus(cls.address) as device:
            pass

    @classmethod
    def check_charge(cls, debug: bool = False):
        addr = bytearray(1)
        addr[0] = register.state_of_charge
        buffer = bytearray(8)
        with open_i2c_bus(cls.address, benchmark=debug) as device:
            device.write_then_readinto(addr, buffer)
            print(buffer)
            cls.charge_level = (
                struct.unpack_from("@H", buffer)[0] >> 8
            )  # just read upper byte
        if debug:
            with formatted_headers("charge_level", benchmark=True):
                print(f"battery level: {cls.charge_level:.2f}%")
        return cls.charge_level

    @classmethod
    def check_voltage(cls, debug: bool = False):
        addr = bytearray(1)
        addr[0] = register.voltage
        buffer = bytearray(8)
        with open_i2c_bus(cls.address, benchmark=debug) as device:
            device.write_then_readinto(addr, buffer)
            register_value = struct.unpack_from("<H", buffer)[0]
            cls.voltage = get_voltage(register_value)
        if debug:
            with formatted_headers("voltage", benchmark=True):
                print(f"voltage: {cls.voltage:.2f}V")
        return cls.charge_level

    @classmethod
    def check_avg_current(cls, debug=False):
        addr = bytearray(1)
        addr[0] = register.avg_current
        buffer = bytearray(8)
        with open_i2c_bus(cls.address, benchmark=debug) as device:
            device.write_then_readinto(addr, buffer)
            register_value = struct.unpack_from("<h", buffer)[0]
            cls.avg_current = get_current(register_value)
        if debug:
            with formatted_headers("avg_current", benchmark=True):
                print(f"avg current: {cls.avg_current:.2f}A")
        return cls.avg_current

    @classmethod
    def check_minmax_current(cls, debug=False):
        addr = bytearray(1)
        addr[0] = register.minmax_current
        buffer = bytearray(8)
        with open_i2c_bus(cls.address, benchmark=debug) as device:
            device.write_then_readinto(addr, buffer)
            register_values = struct.unpack_from("@bb", buffer)
            min_current, max_current = map(get_minmax_current, register_values)
        if debug:
            with formatted_headers("minmax_current", benchmark=True):
                print(f"min {min_current:.2f}A max {max_current:.2f}A")

    @classmethod
    def check_spot_current(cls, debug=False):
        addr = bytearray(1)
        addr[0] = register.current
        buffer = bytearray(8)
        with open_i2c_bus(cls.address, benchmark=debug) as device:
            device.write_then_readinto(addr, buffer)
            register_value = struct.unpack_from("@h", buffer)[0]
            cls.current = get_current(register_value)
        if debug:
            with formatted_headers("spot_current", benchmark=True):
                print(f"Spot current: {cls.current:.2f}A")
        return cls.spot_current

    @classmethod
    def check_avg_temp(cls, debug=False):
        addr = bytearray(1)
        addr[0] = register.avg_temp
        buffer = bytearray(8)
        with open_i2c_bus(cls.address, benchmark=debug) as device:
            device.write_then_readinto(addr, buffer)
            register_value = struct.unpack_from("<h", buffer)[0]
            cls.avg_temp = get_temp(register_value)
        if debug:
            with formatted_headers("avg_temp", benchmark=True):
                print(f"avg_temp: {cls.avg_temp:.1f}°C")
        return cls.avg_temp

    @classmethod
    def is_charging(cls, debug=False) -> bool:
        current = cls.check_avg_current()
        return current > -0.1

    @classmethod
    def check_status(cls, debug=False):
        addr = bytearray(1)
        addr[0] = register.status
        buffer = bytearray(8)
        with open_i2c_bus(cls.address, benchmark=debug) as device:
            device.write_then_readinto(addr, buffer)
            bin16 = struct.unpack_from("<H", buffer)[0]
            if debug:
                with formatted_headers("status", benchmark=True):
                    print(f'status: {format(bin16, "016b")}')

    @classmethod
    def check_cycles(cls, debug: bool = False):
        addr = bytearray(1)
        addr[0] = register.cycles
        buffer = bytearray(8)
        with open_i2c_bus(cls.address, benchmark=debug) as device:
            device.write_then_readinto(addr, buffer)
            register_value = struct.unpack_from("<H", buffer)[0]  # just read upper byte
            cls.cycles = get_cycles(register_value)
        if debug:
            with formatted_headers("charge cycles", benchmark=True):
                print(f"total charge cycles: {cls.cycles:.2f}")
        return cls.cycles

    @classmethod
    def check_time_remaining(cls, debug: bool = False):
        addr = bytearray(1)
        addr[0] = register.time_to_empty
        buffer = bytearray(8)
        with open_i2c_bus(cls.address, benchmark=debug) as device:
            device.write_then_readinto(addr, buffer)
            register_value = struct.unpack_from("<H", buffer)[0]
            cls.time_remaining = get_time(register_value)
        if debug:
            with formatted_headers("time remaining", benchmark=True):
                print(f"time_remaining: {cls.time_remaining:.2f}m")
        return cls.time_remaining

    @classmethod
    def list_all(cls):
        cls.check_charge(debug=True)
        cls.check_avg_current(debug=True)
        cls.check_minmax_current(debug=True)
        cls.check_spot_current(debug=True)
        cls.check_avg_temp(debug=True)
