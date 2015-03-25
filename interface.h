/*
 * interface.h
 *
 *  Created on: Mar 22, 2015
 *      Author: chris
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <systemc>

class EmitterInterface : public sc_core::sc_interface {
 public:
  virtual void write_bit(bool bit) = 0;

};

class ReceiverInterface : virtual public sc_core::sc_interface {
 public:
  virtual bool read_bit() = 0;
};

class Interface : public EmitterInterface, public ReceiverInterface {
};

#endif /* INTERFACE_H_ */
