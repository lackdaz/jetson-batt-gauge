#include <stdio.h>
#include <iostream>
#include "battery.hpp"
#include "jetsonbatt_error.hpp"
#include "registers.hpp"

#include "i2c/i2c.h"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include <boost/format.hpp>

#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>
#include <ostream>

#include <typeinfo>

struct Data {
  double value;

  template <class Archive>
  void serialize(Archive& ar, const unsigned int) {
    ar& value;
  }
  friend std::ostream& operator<<(std::ostream& os, const Data& dt);
};

// std::ostream& operator<<(std::ostream& os, const Data& dt) {
//   os << dt.mo << '/' << dt.da << '/' << dt.yr;
//   return os;
// }

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
  short int bus = 8;
  char bus_name[32];
  memset(bus_name, 0, sizeof(bus_name));

  if (snprintf(bus_name, sizeof(bus_name), "/dev/i2c-%u\n", bus) < 0) {
    fprintf(stderr, "Format i2c bus name error!");
    ERROR << "Format i2c bus name error";
    exit(-3);
  }

  INFO << boost::format("test %s") % bus_name;

  /* Open i2c bus /dev/i2c-0 */
  if ((bus = i2c_open("/dev/i2c-8")) == -1) {
    /* Error process */
    ERROR << "channel does not exist";
  } else {
    INFO << "opened bus";
  }

  I2CDevice device;
  memset(&device, 0, sizeof(device));  // sets array to zeros

  device.bus = bus;       /* Bus 0 */
  device.addr = 0x36;     /* Slave address is 0x36, 7-bit */
  device.iaddr_bytes = 1; /* Device internal address is 1 byte */
  device.page_bytes = 16; /* Device are capable of 16 bytes per page */

  uint8_t register_address = 0x1c;  // state of charge

  unsigned char buffer[8];
  ssize_t size = sizeof(buffer);
  memset(buffer, 0, sizeof(buffer));

  //   unsigned int arr[5] = {0x05, 0x04, 0xAA, 0x0F, 0x0D};

  /* From i2c 0x0 address read 256 bytes data to buffer */
  if ((i2c_read(&device, register_address, buffer, size)) != size) {
    /* Error process */
    ERROR << "i2c channel read error";
  } else {
    DEBUG << "Read data: " << boost::format("%s") % buffer;

    print_i2c_data(buffer, sizeof(buffer));

    DEBUG << boost::format("3rd byte (ascii): %02d") % (int)buffer[2];
    DEBUG << boost::format("3rd byte (ascii): %02d") % (int)buffer[2];
    DEBUG << boost::format("3rd byte (hex): 0x%02x") % (int)buffer[2];
    DEBUG << boost::format("4th byte (hex): 0x%02x") % (int)buffer[3];
  }

  // char buffer[2];
  // ssize_t size = sizeof(buffer);
  // memset(buffer, 0, sizeof(buffer));
  // Data data = {0};

  i2c_close(bus);

  return 0;
}
