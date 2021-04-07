from typing import List, Tuple

__all__ = ["Bitwise"]


class Bitwise:
    @staticmethod
    def get_signed_twos_complement(uint8: int, bits: int = 8) -> int:
        """Computes the signed twos-complement of an unsigned decimal.

        How it works:
        Checks for signed bit at most-significant bit, e.g. 10001111
        and computes for negative value if set.

        Typical usage example:
        get_signed_twos_complement(0) -> 0
        get_signed_twos_complement(255) -> -1
        get_signed_twos_complement(127) -> 127
        get_signed_twos_complement(128) -> -128

        Args:
            uint8 (int): unsigned decimal
            bits (int, optional): n-bit decimal. Defaults to 8.

        Returns:
            int: returns a twos-complement decimal
        """
        if (uint8 & (1 << (bits - 1))) != 0:  # if signed bit is set e.g. 8-bit: 128-255
            uint8 -= 1 << (uint8.bit_length())  # compute negative value
        return uint8  # return positive values

    @staticmethod
    def bitmask(bin16: int, bits: int) -> int:
        bitmask = (1 << bits) - 1
        return bin16 & bitmask

    @staticmethod
    def get_min_max_byte(bin16: int) -> Tuple[int, int]:
        """Wrapper function for fetching lower and upper bytes
        (or LSb and MSb respectively).

        Fetches LSb by bitwise right-shifting 8-bits and
        MSb by bitmasking the first 8-bits.

        Args:
            bin16 (int): 16-bit decimal

        Returns:
            Tuple[int, int]: [LSb, MSb]
        """
        return bin16 & 0xFF, bin16 >> 8

    @staticmethod
    def set_bit(bin16: int, offset: int) -> int:  # starts from 0
        mask = 1 << offset
        return bin16 | mask

    @staticmethod
    def clear_bit(bin16: int, offset: int) -> int:
        mask = ~(1 << offset)
        return bin16 & mask

    @staticmethod
    def toggle_bit(bin16: int, offset: int) -> int:
        mask = 1 << offset
        return bin16 ^ mask

    @staticmethod
    def clear_bits(bin16: int, offsets: List[int]) -> int:
        mask = int("00000000", 2)
        for offset in offsets:
            mask |= 1 << offset
        return bin16 & ~mask

    @staticmethod
    def set_bits(bin16: int, offsets: List[int]) -> int:
        mask = int("00000000", 2)
        for offset in offsets:
            mask |= 1 << offset
        return bin16 | mask

    @staticmethod
    def toggle_bits(bin16: int, offsets: List[int]) -> int:
        mask = int("00000000", 2)
        for offset in offsets:
            mask |= 1 << offset
        return bin16 ^ mask