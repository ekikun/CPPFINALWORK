#ifndef MODIFYPAGE_H
#define MODIFYPAGE_H

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
class Modifypage;
}

class Modifypage : public QWidget
{
    Q_OBJECT

public:
    explicit Modifypage(QWidget *parent = nullptr);
    ~Modifypage();
    void modify_friend();
    void modify_classmate();
    void modify_workmate();
    void modify_relative();
signals:
    void  backtomain();
private:
    Ui::Modifypage *ui;
};

#endif // MODIFYPAGE_H
