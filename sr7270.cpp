#include "sr7270.h"
#include <QtWidgets>
#include <QtNetwork/QtNetwork>
#include <QtCore>

SR7270::SR7270()
{
}

void SR7270::setup(QString this_ip, int this_port) {
    ip_address = this_ip;
    port = this_port;
    socket = new QTcpSocket(0);
    host.setAddress(ip_address);
}

void SR7270::send_command(QString command)
{
    socket->connectToHost(host,port,QTcpSocket::ReadWrite); // Connect to the host
    QByteArray buffer; // Make a QByteArray to hold the command we want to send
    buffer.append(command);
    socket->waitForConnected(20); // Wait until we are actually connected, up to 20 ms
    socket->write(buffer); // Write to the internal socket buffer
    socket->flush(); // Send it on its merry way
}

QString SR7270::read_response()
{
    QString response = "No response given";
    socket->waitForReadyRead(20); //Wait for the internal socket buffer to be filled with the response
    while (socket->canReadLine()) // In case there are multiple lines, like if we ask for several measurements
    {
        QByteArray ba = socket->readLine();
        if(strcmp(ba.constData(), "\0")!=0) // If not a blank response
        {
            response.clear();
            response.append(ba);
        }
    }
    socket->disconnectFromHost(); // Make sure to hang up when the exchange is complete
    return response;
}
