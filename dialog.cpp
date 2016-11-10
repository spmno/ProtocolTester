#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include "../Log/MXLog.h"

#define PORT "/dev/ttyUSB0"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendButtonClicked()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::sendButtonClicked()
{
    MXLOG->info("send button clicked ");
    MXLOG->info(111);
}
