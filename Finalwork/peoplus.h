#ifndef PEOPLUS_H
#define PEOPLUS_H

#include<people.h>
#include<QString>
class Peoplus:public People
{
public:
    Peoplus();
    Peoplus(QString n, int b, QString p, QString e,QString s, int set);

    QString show_birthdayweekday();
private:
    QString birthweekday;
    int set_weekday;
};

#endif // PEOPLUS_H
