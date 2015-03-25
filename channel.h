/*
 * channel.h
 *
 *  Created on: Mar 22, 2015
 *      Author: chris
 */

#ifndef CHANNEL_H_
#define CHANNEL_H_

#include <systemc>
#include "interface.h"

class Channel : public sc_core::sc_module,  public Interface {
 public:
  Channel(const sc_core::sc_module_name& module_name);
  void write_bit(bool bit);
  bool read_bit();

 private:
  sc_core::sc_signal<bool> bit_;
};

#endif /* CHANNEL_H_ */
