#include <stdio.h>
#include <iostream>
#include "registers.hpp"

int main() {
  printf("Hello there %#04x.\n", jetsonbatt::registers::current);
  std::cout << "1) size of namespace variable:              "
            << sizeof(jetsonbatt::registers::current) << "\n";
  return 0;
}
