#ifndef NAMESORT_H
#define NAMESORT_H

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
class Namesort;
}

class Namesort : public QWidget
{
    Q_OBJECT

public:
    explicit Namesort(QWidget *parent = nullptr);
    ~Namesort();
signals:
    void backtomain();
private:
    Ui::Namesort *ui;
};

#endif // NAMESORT_H
