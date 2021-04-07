#!/usr/bin/env python3

import sys

if sys.version_info.major < 3:
    print("You need to run this on Python 3")
    sys.exit(-1)

from typing import Optional, List, NamedTuple

from battery import *


def main():
    # Battery.init()
    Battery.check_charge(debug=True)
    # Battery.check_voltage(debug=True)
    # Battery.check_minmax_voltage(debug=True)

    Battery.check_avg_current(debug=True)
    Battery.check_minmax_current(debug=True)
    # Battery.check_spot_current(debug=True)

    # Battery.check_avg_temp(debug=True)

    # Battery.check_cycles(debug=True)
    # Battery.check_time_remaining(debug=True)
    # Battery.check_status(debug=True)


if __name__ == "__main__":
    main()
