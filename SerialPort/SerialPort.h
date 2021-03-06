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
    static bool open();
    static asio::serial_port& GetSerialPort() { return serialport; }
    static void run() { serial_io_service.run(); }
private:
    static asio::io_service serial_io_service;
    static asio::serial_port serialport;
};

#endif /* SERIALPORT_H_ */
