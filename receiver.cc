/*
 * receiver.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: chris
 */

#include "receiver.h"

Receiver::Receiver(const sc_core::sc_module_name& module_name)
    : sc_core::sc_module(module_name)
{
  SC_HAS_PROCESS(Receiver);
  SC_METHOD(ReceiveStuff);
//    dont_initialize();
    sensitive << clk_in_.pos();

}

void Receiver::ReceiveStuff() {
//  while(true){
    auto read_bit = input_port_->read_bit();
    std::cout << "read_bit=" << read_bit << std::endl;
//    wait();
//  }
}
