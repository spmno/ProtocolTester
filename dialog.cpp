#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <thread>
#include "../Log/MXLog.h"
#include "protocolpackage.h"

#define PORT "/dev/ttyUSB0"

void read_process();

constexpr char hexmap[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

std::string HexStr(unsigned char *data, int len)
{
  std::string s(len * 2, ' ');
  for (int i = 0; i < len; ++i) {
    s[2 * i]     = hexmap[(data[i] & 0xF0) >> 4];
    s[2 * i + 1] = hexmap[data[i] & 0x0F];
  }
  return s;
}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendButtonClicked()));
    std::thread read_thread(read_process);
    read_thread.detach();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::sendButtonClicked()
{
    MXLOG->info("send button clicked ");
    MXLOG->info(111);
    asio::serial_port& serialport = SerialPort::GetSerialPort();
    asio::error_code ec;
    ProtocolPackage<0x09, 5> drive_info_package = { 50, 40, 0, 0, 0 };
    int write_number = serialport.write_some(asio::buffer(drive_info_package.GetBuffer(), 5+6),ec);
    if (ec) {
        MXLOG->error(ec.message());
    }
    MXLOG->info("write number = {}", write_number);
}

void read_process()
{
    asio::serial_port& serialport = SerialPort::GetSerialPort();
    unsigned char buffer[512];
    asio::error_code ec;
    int read_length = 0;
    while(true) {
        MXLOG->info("before read");
        read_length = serialport.read_some(asio::buffer(buffer), ec);
        if (ec) {
            MXLOG->error(ec.message());
        }
        std::string read_data = HexStr(buffer, read_length);
        MXLOG->info("after read, length = {}, data = {}", read_length, read_data.c_str());
    }
}
