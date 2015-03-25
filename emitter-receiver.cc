/*
 * emitter-receiver.cc
 *
 *  Created on: Mar 22, 2015
 *      Author: chris
 */

#include <systemc>
#include "emitter.h"
#include "receiver.h"
#include "channel.h"

SC_MODULE(EmitterReceiverTop) {
  SC_CTOR(EmitterReceiverTop)
      : emitter_("emitter_")
      , receiver_("receiver_")
      , channel_("channel_")
      , clk_("clk_", 10, sc_core::SC_NS, 0.5)
  {
    SC_HAS_PROCESS(EmitterReceiverTop);
    //bind emitter to channel
    emitter_.output_port_.bind(channel_);
    emitter_.clk_in_.bind(clk_);

    //bind receiver to channel
    receiver_.input_port_.bind(channel_);
    receiver_.clk_in_.bind(clk_);
  }

  Emitter emitter_;
  Receiver receiver_;
  Channel channel_;
  sc_core::sc_clock clk_;
};

int sc_main(int argc, char* argv[]) {
  EmitterReceiverTop ("EmitterReceiverTop");

  sc_core::sc_start();
  return(0);
}
