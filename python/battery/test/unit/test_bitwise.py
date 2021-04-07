from battery import Bitwise
import pytest


def test_bin8():
    result = Bitwise.get_signed_twos_complement(0)
    assert result == 0
    result = Bitwise.get_signed_twos_complement(255)
    assert result == -1
    result = Bitwise.get_signed_twos_complement(127)
    assert result == 127
    result = Bitwise.get_signed_twos_complement(128)
    assert result == -128


def test_bin16():
    result = Bitwise.get_signed_twos_complement(0x0000, bits=16)
    assert result == 0
    result = Bitwise.get_signed_twos_complement(0xFFFF, bits=16)
    assert result == -1
    result = Bitwise.get_signed_twos_complement(0x7FFF, bits=16)
    assert result == 32767
    result = Bitwise.get_signed_twos_complement(0x8000, bits=16)
    assert result == -32768
