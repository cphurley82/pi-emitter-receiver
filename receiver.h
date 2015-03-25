/*
 * receiver.h
 *
 *  Created on: Mar 22, 2015
 *      Author: chris
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include <systemc>
#include "interface.h"

class Receiver : public sc_core::sc_module {
 public:
  Receiver(const sc_core::sc_module_name& module_name);
  sc_core::sc_in<bool> clk_in_;
  sc_core::sc_port<ReceiverInterface> input_port_;
 private:
  void ReceiveStuff();
};

#endif /* RECEIVER_H_ */
