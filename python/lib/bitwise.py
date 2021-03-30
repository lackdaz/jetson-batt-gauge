from typing import List

__all__ = [
    "set_bit",
    "clear_bit",
    "toggle_bit",
    "clear_bits",
    "set_bits",
    "toggle_bits",
]


def set_bit(bin16: int, offset: int) -> int:  # starts from 0
    mask = 1 << offset
    return bin16 | mask


def clear_bit(bin16: int, offset: int) -> int:
    mask = ~(1 << offset)
    return bin16 & mask


def toggle_bit(bin16: int, offset: int) -> int:
    mask = 1 << offset
    return bin16 ^ mask


def clear_bits(bin16: int, offsets: List[int]) -> int:
    mask = int("00000000", 2)
    for offset in offsets:
        mask |= 1 << offset
    return bin16 & ~mask


def set_bits(bin16: int, offsets: List[int]) -> int:
    mask = int("00000000", 2)
    for offset in offsets:
        mask |= 1 << offset
    return bin16 | mask


def toggle_bits(bin16: int, offsets: List[int]) -> int:
    mask = int("00000000", 2)
    for offset in offsets:
        mask |= 1 << offset
    return bin16 ^ mask