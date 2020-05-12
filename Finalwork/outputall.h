#ifndef OUTPUTALL_H
#define OUTPUTALL_H

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
namespace Ui {
class Outputall;
}

class Outputall : public QWidget
{
    Q_OBJECT

public:
    explicit Outputall(QWidget *parent = nullptr);
    ~Outputall();
    void outall();
signals:
    void backtomain();
private:
    Ui::Outputall *ui;
};

#endif // OUTPUTALL_H
