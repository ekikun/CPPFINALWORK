#ifndef RELATIVE_H
#define RELATIVE_H
#include<QString>

class Relative
{
public:
    Relative(QString n, int b, QString pn, QString em,QString ca):name(n),birthday(b),phonenum(pn),email(em),call(ca){}
    Relative();
    ~Relative(){}
    QString show_name();
    int show_birthday();
    QString show_phonenumber();
    QString show_email();
    QString show_address();
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
        call = newpart;
    }
private:
    QString name;
    int birthday;
    QString phonenum;
    QString email;
    QString call;

};

#endif // RELATIVE_H
