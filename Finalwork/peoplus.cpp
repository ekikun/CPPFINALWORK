#include "peoplus.h"

Peoplus::Peoplus(QString n, int b, QString p, QString e,QString s, int set):People(n,b,p,e,s)
{
    set_weekday = set;
    if(set_weekday==1)
    {
       birthweekday = "星期一";
    }
    else if(set_weekday==2)
    {
         birthweekday = "星期二";
    }
    else if(set_weekday==3)
    {
         birthweekday = "星期三";
    }
    else if(set_weekday==4)
    {
         birthweekday = "星期四";
    }
    else if(set_weekday==5)
    {
        birthweekday = "星期五";
    }
    else if(set_weekday==6)
    {
        birthweekday = "星期六";
    }
    else if(set_weekday==7)
    {
        birthweekday = "星期天";
    }
}


QString Peoplus::show_birthdayweekday()
{
    return birthweekday;
}
