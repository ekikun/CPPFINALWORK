#ifndef BIRTHTOTAL_H
#define BIRTHTOTAL_H

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
namespace Ui {
class Birthtotal;
}

class Birthtotal : public QWidget
{
    Q_OBJECT

public:
    explicit Birthtotal(QWidget *parent = nullptr);
    ~Birthtotal();
    void count();
signals:
    void backtomain();
private:
    Ui::Birthtotal *ui;
};

#endif // BIRTHTOTAL_H
