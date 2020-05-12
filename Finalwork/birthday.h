#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include <QWidget>
#include<QFile>
#include<QVector>
#include<QString>
#include<QMessageBox>
#include<friend.h>
#include<classmate.h>
#include<workmate.h>
#include<relative.h>
#include<QTextStream>
#include<people.h>
#include<peoplus.h>
namespace Ui {
class Birthday;
}

class Birthday : public QWidget
{
    Q_OBJECT

public:
    explicit Birthday(QWidget *parent = nullptr);
    ~Birthday();
    void search();
signals:
    void backtomain();
private:
    Ui::Birthday *ui;
    int is_leap;
    int isnot_leap;
};

#endif // BIRTHDAY_H
