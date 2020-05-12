#ifndef PEOPLE_H
#define PEOPLE_H

#include<QString>
class People
{
public:
    People();
    People(QString n, int b, QString p, QString e,QString s)
    {
        name = n; birthday = b; phonenum = p; email = e ;specialinf = s;
    }
    QString show_name(){return name;}
    QString show_phonenumber(){return phonenum;}
    QString show_email(){return email;}
    QString show_specialinfomation(){return specialinf;}
    int show_birth(){return birthday;}
private:
    QString name;
    int birthday;
    QString phonenum;
    QString email;
    QString specialinf;
};

#endif // PEOPLE_H
