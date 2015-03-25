/*
 * channel.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: chris
 */

#include "channel.h"

Channel::Channel(const sc_core::sc_module_name& module_name)
    : sc_core::sc_module(module_name)
{

}

void Channel::write_bit(bool bit) {
  bit_.write(bit);
}

bool Channel::read_bit() {
  return bit_.read();
}
