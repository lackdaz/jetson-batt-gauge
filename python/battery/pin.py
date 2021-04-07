__all__ = [
    "Board",
    "SDA",
    "SCL",
    "D13",
    "D19",
    "D21",
    "D22",
    "D23",
    "D24",
    "D32",
    "D33",
    "D27",
]

from enum import Enum


class Board(Enum):
    def __repr__(self):
        return self.value

    def __str__(self):
        return str(self.value)

    SDA: str = "DP_AUX_CH3_N"
    SCL: str = "DP_AUX_CH3_P"


SDA: str = Board.SDA.value
SCL: str = Board.SCL.value
