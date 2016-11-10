/*
 * SerialPort.h
 *
 *  Created on: 2016年11月10日
 *      Author: sunqp
 */

#ifndef SERIALPORT_H_
#define SERIALPORT_H_

#include <asio.hpp>

class SerialPort {
public:
	SerialPort();
	virtual ~SerialPort();
	bool open();
	void run() { serial_io_service.run(); }
private:
	asio::io_service serial_io_service;
	asio::serial_port serialport;
};

#endif /* SERIALPORT_H_ */
