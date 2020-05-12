#ifndef BIRTHSORT_H
#define BIRTHSORT_H

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
class Birthsort;
}

class Birthsort : public QWidget
{
    Q_OBJECT

public:
    explicit Birthsort(QWidget *parent = nullptr);
    ~Birthsort();
signals:
    void backtomain();
private:
    Ui::Birthsort *ui;
};

#endif // BIRTHSORT_H
