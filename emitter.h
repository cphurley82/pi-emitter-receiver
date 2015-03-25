/*
 * emitter.h
 *
 *  Created on: Mar 22, 2015
 *      Author: chris
 */

#ifndef EMITTER_H_
#define EMITTER_H_
#include "interface.h"

#include <systemc>

class Emitter : public sc_core::sc_module {
 public:
  Emitter(const sc_core::sc_module_name& module_name);
  sc_core::sc_in<bool> clk_in_;
  sc_core::sc_port<EmitterInterface> output_port_;
 private:
  void EmitStuff();
  int data_;
};

#endif /* EMITTER_H_ */
