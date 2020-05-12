#ifndef FRIEND_H
#define FRIEND_H
#include<QString>

class Friend
{
public:
    Friend(QString n, int b, QString pn, QString em,QString np);
    Friend();
    ~Friend(){
        birthday = 0;
    }
    QString show_name();
    int show_birthday();
    QString show_phonenumber();
    QString show_email();
    QString show_knownplace();
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
        knowplace = newpart;
    }
private:
    QString name;
    int birthday;
    QString phonenum;
    QString email;
    QString knowplace;
};

#endif // FRIEND_H
