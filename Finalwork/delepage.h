#ifndef DELEPAGE_H
#define DELEPAGE_H

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
class Delepage;
}

class Delepage : public QWidget
{
    Q_OBJECT

public:
    explicit Delepage(QWidget *parent = nullptr);
    ~Delepage();
signals:
    void backtomain();
private:
    Ui::Delepage *ui;
};

#endif // DELEPAGE_H
