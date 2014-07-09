#ifndef SR7270_H
#define SR7270_H
#include <QtWidgets>
#include <QtNetwork/QtNetwork>
#include <QtCore>

class SR7270
{
public:
    SR7270();
    QString ip_address;
    int port;
    QHostAddress host;
    QTcpSocket *socket;
    void setup(QString this_ip, int this_port);
    void send_command(QString command);

    QString read_response();
};

#endif // SR7270_H
