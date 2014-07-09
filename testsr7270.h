#ifndef TESTSR7270_H
#define TESTSR7270_H

#include <QMainWindow>
#include "sr7270.h"

namespace Ui {
class TestSR7270;
}

class TestSR7270 : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestSR7270(QWidget *parent = 0);
    ~TestSR7270();

private slots:
    void settingWidgetChanged();
    void on_writeCommandButton_clicked();

private:
    Ui::TestSR7270 *ui;
    SR7270 lockin;
};

#endif // TESTSR7270_H
