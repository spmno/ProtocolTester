#include "dialog.h"
#include <QApplication>
#include "SerialPort/SerialPort.h"
#include "Log/MXLog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MXLog::Init();
    SerialPort serial_port;
    serial_port.open();
    Dialog w;
    w.show();

    return a.exec();
}
