/* Copyright (C) 2021 Seth Loh
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE.mit file for details.
 */

#include "battery.hpp"

namespace {
  //   std::string hello_world();
}

namespace jetsonbatt {
  battery::battery() {
    I2CDevice device;
    device.bus = 8;      // bus 8
    device.addr = 0x36;  // i2c address
    device.iaddr_bytes = 1;
    device.page_bytes = 16;

    DEBUG << "inside constructor";
  }
  battery::~battery() { DEBUG << "inside destructor"; }
  char battery::query(uint8_t hex) {}
  void battery::get_minmax_current() {}
}  // namespace jetsonbatt

namespace {

  //   memset(&device, 0, sizeof(device));  // sets array to zeros

  //   device.bus = bus;       /* Bus 0 */
  //   device.addr = 0x36;     /* Slave address is 0x36, 7-bit */
  //   device.iaddr_bytes = 1; /* Device internal address is 1 byte */
  //   device.page_bytes = 16; /* Device are capable of 16 bytes per page */

  //   uint8_t register_address = 0x1c;  // state of charge

  //   unsigned char buffer[8];
  //   ssize_t size = sizeof(buffer);
  //   memset(buffer, 0, sizeof(buffer));

  //   unsigned int arr[5] = {0x05, 0x04, 0xAA, 0x0F, 0x0D};

  /* From i2c 0x0 address read 256 bytes data to buffer */
  //   if ((i2c_read(&device, register_address, buffer, size)) != size) {
  //     /* Error process */
  //     ERROR << "i2c channel read error";
  //   } else {
  //     DEBUG << "Read data: " << boost::format("%s") % buffer;
  //   std::string hello_world() {
  //     DEBUG << "this is a debug";
  //     ERROR << "this is an error";
  //     INFO << "this is an info";
  //     WARNING << "this is a warning";
  //     return "hello world";
  //   }
}  // namespace