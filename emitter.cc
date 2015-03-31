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
  SC_METHOD(EmitStuff);
    sensitive << clk_in_.pos();
    dont_initialize();

}

void Emitter::EmitStuff() {
    bool write_bit = data_ & 1;
//    std::cout << "data_=" << data_ << std::endl;
    std::cout << "write_bit=" << write_bit << std::endl;
    output_port_->write_bit(write_bit);
    data_ = data_ >> 1;
    if(data_ == 0) {
      sc_core::sc_stop();
    }
}
