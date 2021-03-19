#include <stdio.h>
#include <iostream>
#include "battery.hpp"
#include "jetsonbatt_error.hpp"
#include "registers.hpp"

#include "i2c/i2c.h"

int main() {
  // printf("Hello there %#04x.\n", jetsonbatt::registers::current);
  // std::cout << "1) size of namespace variable:              "
  //           << sizeof(jetsonbatt::registers::current) << "\n";
  // battery::hello_world();

  int bus;
  /* Open i2c bus /dev/i2c-0 */
  if ((bus = i2c_open("/dev/i2c-8")) == -1) {
    DEBUG << "hello";
  }

  I2CDevice device;
  memset(&device, 0, sizeof(device));

  /* 24C04 */
  device.bus = bus;       /* Bus 0 */
  device.addr = 0x68;     /* Slave address is 0x50, 7-bit */
  device.iaddr_bytes = 1; /* Device internal address is 1 byte */
  device.page_bytes = 16; /* Device are capable of 16 bytes per page */

  unsigned char buffer[256];
  ssize_t size = sizeof(buffer);
  memset(buffer, 0, sizeof(buffer));

  /* From i2c 0x0 address read 256 bytes data to buffer */
  if ((i2c_read(&device, 0x1, buffer, size)) != size) {
    ERROR << "don't know what went wrong";
    /* Error process */
  }

  i2c_close(bus);

  INFO << printf("%s", buffer);
  return 0;
}
