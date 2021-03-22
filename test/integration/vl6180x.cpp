#include <stdio.h>
#include <iostream>
#include "battery.hpp"
#include "jetsonbatt_error.hpp"
#include "registers.hpp"

#include "i2c/i2c.h"

void print_i2c_data(const unsigned char* data, size_t len) {
  size_t i = 0;

  for (i = 0; i < len; i++) {
    if (i % 16 == 0) {
      fprintf(stdout, "\n");
    }

    fprintf(stdout, "%02x ", data[i]);
  }

  fprintf(stdout, "\n");
}

int main() {
  // printf("Hello there %#04x.\n", jetsonbatt::registers::current);
  // std::cout << "1) size of namespace variable:              "
  //           << sizeof(jetsonbatt::registers::current) << "\n";
  // battery::hello_world();

  int bus_num = 8;
  char bus_name[32];
  memset(bus_name, 0, sizeof(bus_name));

  // formats bus name, return -1 when encoding error, must return < n-1
  if (snprintf(bus_name, sizeof(bus_name), "/dev/i2c-%u", bus_num) < 0) {
    fprintf(stderr, "Format i2c bus name error!\n");
    exit(-3);
  }

  // INFO << printf("%s", bus_name);

  /* Open i2c bus /dev/i2c-0 */
  // if ((bus_num = i2c_open("/dev/i2c-8")) == -1) {
  //   /* Error process */
  //   ERROR << "channel does not exist";
  // } else {
  //   INFO << "opened bus";
  // }

  I2CDevice device;
  memset(&device, 0, sizeof(device));  // sets array to zeros

  /* 24C04 */
  device.bus = bus_num;   /* Bus 0 */
  device.addr = 0x29;     /* Slave address is 0x50, 7-bit */
  device.iaddr_bytes = 2; /* Device internal address is 1 byte */
  device.page_bytes = 16; /* Device are capable of 16 bytes per page */

  unsigned char buffer[256];
  ssize_t size = sizeof(buffer);
  memset(buffer, 0, sizeof(buffer));

  /* From i2c 0x0 address read 256 bytes data to buffer */
  if ((i2c_read(&device, 0x0016, buffer, size)) != size) {
    ERROR << "don't know what went wrong";
    /* Error process */
  } else {
    INFO << printf("%s", buffer);
  }

  // clear 0x016 bit to 0
  // ssize_t i2c_ioctl_write(const I2CDevice *device, unsigned int iaddr, const
  // void *buf, size_t len);
  // if (i2c_ioctl_write(&device, 0x0016, 0x00, size) != -1) {
  // }

  i2c_close(bus_num);

  return 0;
}
