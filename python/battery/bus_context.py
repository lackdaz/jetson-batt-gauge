__all__ = ["open_i2c_bus", "formatted_headers"]

import busio
from adafruit_bus_device.i2c_device import I2CDevice
from time import perf_counter
from contextlib import contextmanager
import sys

from .pin import SCL, SDA
from .formatting import bcolors

execution_time = 0.00


def print_last_execution_time(func: str):
    print(f"{func} execution time: {execution_time * 1000:.3f} ms")


def print_function_header(func: str):
    print(bcolors.WARNING + "==" + func + "==" + bcolors.ENDC)


@contextmanager
def open_i2c_bus(address: int, benchmark: bool = False):
    i2c = busio.I2C(SCL, SDA)
    device = I2CDevice(i2c, address, probe=False)
    try:
        if benchmark:
            time1 = perf_counter()
        yield device
    except IOError:
        raise IOError("Is battery connected?")
    finally:
        i2c.deinit()
        if benchmark:
            time2 = perf_counter()
            execution_time = time2 - time1


@contextmanager
def formatted_headers(func: str, benchmark: bool = False):
    try:
        print_function_header(func)
        yield
    finally:
        if benchmark:
            print_last_execution_time(func)
