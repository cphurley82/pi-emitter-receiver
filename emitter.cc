/*
 * emitter.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: chris
 */

#include "emitter.h"

Emitter::Emitter(const sc_core::sc_module_name& module_name)
    : sc_core::sc_module(module_name)
    , data_(0xdeadbeef)
{
  SC_HAS_PROCESS(Emitter);
  SC_THREAD(EmitStuff);
    sensitive << clk_in_.neg();
//    dont_initialize();

}

void Emitter::EmitStuff() {
  while(true){

    bool write_bit = data_ & 1;
    std::cout << "write_bit=" << write_bit << std::endl;
    output_port_->write_bit(write_bit);
    data_ = data_ >> 1;
    if(data_ == 0) {
      data_ = 0xdeadbeef;
      sc_core::sc_stop();
    }
    wait();
  }
}
