#include "friend.h"

Friend::Friend(QString n, int b, QString pn, QString em,QString np)
{
    name = n;
    birthday = b;
    phonenum = pn;
    email = em;
    knowplace = np;
}
QString Friend::show_name()
{
    return name;
}
int Friend::show_birthday()
{
    return birthday;
}
QString Friend::show_phonenumber(){
    return phonenum;
}
QString Friend::show_email()
{
    return email;
}
QString Friend::show_knownplace()
{
    return knowplace;
}
