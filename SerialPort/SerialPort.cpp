/*
 * SerialPort.cpp
 *
 *  Created on: 2016年11月10日
 *      Author: sunqp
 */

#include "SerialPort.h"
#include "../Log/MXLog.h"

#define PORT "/dev/ttyUSB0"

SerialPort::SerialPort() : serialport(serial_io_service)
{
	// TODO Auto-generated constructor stub
}

SerialPort::~SerialPort() {
	// TODO Auto-generated destructor stub
}

bool SerialPort::open() {
	asio::error_code ec;
	serialport.open(PORT, ec);
	if (ec) {
		MXLOG->error(ec.message());
		return false;
	}
	serialport.set_option(asio::serial_port::baud_rate(38400));
	serialport.set_option(asio::serial_port::flow_control());
	serialport.set_option(asio::serial_port::parity());
	serialport.set_option(asio::serial_port::stop_bits());
	serialport.set_option(asio::serial_port::character_size(8));
	char buf[]="hello";
	int write_number = serialport.write_some(asio::buffer(buf),ec);
	if (ec) {
		MXLOG->error(ec.message());
	}
    MXLOG->info("write number = {}", write_number);
	return true;
}
