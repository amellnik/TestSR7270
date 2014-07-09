#include "testsr7270.h"
#include "ui_testsr7270.h"
#include "sr7270.h"

TestSR7270::TestSR7270(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestSR7270)
{
    ui->setupUi(this);

    //When either the IP or the port are changed, run this function
    connect(ui->ipAddressEdit, SIGNAL(editingFinished()),this,SLOT(settingWidgetChanged()));
    connect(ui->portNumberBox, SIGNAL(editingFinished()),this,SLOT(settingWidgetChanged()));

    //Call it once to fill in values
    settingWidgetChanged();
}

TestSR7270::~TestSR7270()
{
    delete ui;
}

void TestSR7270::on_writeCommandButton_clicked()
{
    lockin.send_command(ui->commandEdit->text()); //Send the command to the lockin
    ui->responseEdit->setPlainText(lockin.read_response()); //Read the response and fill it in the box
}

void TestSR7270::settingWidgetChanged()
{
    //Change the settings for the host
    lockin.setup(ui->ipAddressEdit->text(),ui->portNumberBox->value());
}
