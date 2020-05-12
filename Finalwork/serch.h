#ifndef SERCH_H
#define SERCH_H

#include <QWidget>
#include<QString>
#include<QVector>
#include<QFile>
#include<QTextStream>
#include<friend.h>
#include<workmate.h>
#include<classmate.h>
#include<relative.h>
namespace Ui {
class Serch;
}

class Serch : public QWidget
{
    Q_OBJECT

public:
    explicit Serch(QWidget *parent = nullptr);
    ~Serch();
signals:
    void backtomain();
private:
    Ui::Serch *ui;
    void fsearch();
};

#endif // SERCH_H
