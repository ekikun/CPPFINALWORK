#ifndef WORKMATE_H
#define WORKMATE_H
#include<QString>

class Workmate
{
public:
    Workmate(QString n, int b, QString pn, QString em,QString cy):name(n),birthday(b),phonenum(pn),email(em),company(cy){}
    Workmate();
    ~Workmate(){}
    QString show_name();
    int show_birthday();
    QString show_phonenumber();
    QString show_email();
    QString show_company();
    void modify_phonenumber(QString newnumber)
    {
        phonenum = newnumber;
    }
    void modify_email(QString newemail)
    {
        email = newemail;
    }
    void modify_particularinf(QString newpart)
    {
        company = newpart;
    }
private:
    QString name;
    int birthday;
    QString phonenum;
    QString email;
    QString company;
};

#endif // WORKMATE_H
