#include <stdio.h>
#include <iostream>
#include "registers.hpp"

int main() {
  printf("Hello there %#04x.\n", jetsonbatt::registers::current);
  return 0;
}