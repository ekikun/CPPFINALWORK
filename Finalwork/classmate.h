#ifndef CLASSMATE_H
#define CLASSMATE_H
#include<QString>
class Classmate
{
public:
    Classmate(QString n, int b, QString pn, QString em,QString sc):name(n),birthday(b),phonenum(pn),email(em),school(sc){}
    Classmate();
    ~Classmate(){}
    QString show_name();
    int show_birthday();
    QString show_phonenumber();
    QString show_email();
    QString show_school();
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
        school = newpart;
    }
private:
    QString name;
    int birthday;
    QString phonenum;
    QString email;
    QString school;
};
#endif // CLASSMATE_H
