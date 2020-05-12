#include "birthday.h"
#include "ui_birthday.h"
Birthday::Birthday(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Birthday)
{
    ui->setupUi(this);
    connect(ui->back,&QPushButton::clicked,this,[=](){
        ui->t_show->clear();
        emit backtomain();
        ui->t_date->clear();
        ui->t_weekday->clear();
    });
    connect(ui->yes_leap,&QRadioButton::clicked,this,[=](){
        is_leap =1; isnot_leap = 0;
    });
    connect(ui->no_leap,&QRadioButton::clicked,this,[=](){
       is_leap = 0; isnot_leap =1;
    });
    connect(ui->Search,&QPushButton::clicked,this,&Birthday::search);
}

Birthday::~Birthday()
{
    delete ui;
}

void Birthday::search()
{
    QString date = ui->t_date->toPlainText();
    QString day = ui->t_weekday->toPlainText();
    QFile ffriend("Friend.txt");
    QFile fclassmate("Classmate.txt");
    QFile fworkmate("Workmate.txt");
    QFile frelative("Relative.txt");
    QFile fbirthday("Happybirthday.txt");
    QVector<Friend> vf; QVector<Workmate> vw; QVector<Classmate> vc; QVector<Relative> vr;
    ffriend.open(QIODevice::ReadOnly|QIODevice::Text);
    fclassmate.open(QIODevice::ReadOnly|QIODevice::Text);
    fworkmate.open(QIODevice::ReadOnly|QIODevice::Text);
    frelative.open(QIODevice::ReadOnly|QIODevice::Text);
    fbirthday.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream outf(&ffriend);QTextStream outc(&fclassmate);QTextStream outw(&fworkmate);QTextStream outr(&frelative);
    QTextStream in(&fbirthday);
    int birthday, i;
    QString name,phonenumber,email,school, birthd,birth,company,knowplace,address,special;
    while (!outf.atEnd()) {
        outf>>name>>birthd>>phonenumber>>email>>knowplace;
        birthday = birthd.toInt();
        vf.push_back(Friend(name,birthday,phonenumber,email,knowplace));
    }
    while (!outc.atEnd()) {
        outc>>name>>birthd>>phonenumber>>email>>school;
        birthday = birthd.toInt();
        vc.push_back(Classmate(name,birthday,phonenumber,email,school));
    }
    while (!outr.atEnd()) {
        outr>>name>>birthd>>phonenumber>>email>>address;
        birthday = birthd.toInt();
        vr.push_back(Relative(name,birthday,phonenumber,email,address));
    }
    while(!outw.atEnd())
    {
        outw>>name>>birthd>>phonenumber>>email>>company;
        birthday = birthd.toInt();
        vw.push_back(Workmate(name,birthday,phonenumber,email,company));
    }
    vf.pop_back();vw.pop_back();vc.pop_back();vr.pop_back();
    for(i=0;i<vf.size();i++)
    {
        QString birth = QString::number(vf[i].show_birthday());
        if(birth.size()==3)
        {
            birth.insert(0,"0");
        }
        QString chinesepart = vf[i].show_knownplace().toUtf8();
       in<<vf[i].show_name()<<" "+birth<<" "+vf[i].show_phonenumber()<<" "<<vf[i].show_email()<<" "<<chinesepart<<"\n";
    }
    for(i=0;i<vc.size();i++)
    {
        QString birth = QString::number(vc[i].show_birthday());
        if(birth.size()==3)
        {
            birth.insert(0,"0");
        }
        QString chinesepart = vc[i].show_school().toUtf8();
        in<<vc[i].show_name()<<" "+birth<<" "+vc[i].show_phonenumber()<<" "<<vc[i].show_email()<<" "<<chinesepart<<"\n";
    }
    for(i=0;i<vw.size();i++)
    {
        QString birth = QString::number(vw[i].show_birthday());
        if(birth.size()==3)
        {
            birth.insert(0,"0");
        }
        QString chinesepart = vw[i].show_company().toUtf8();
       in<<vw[i].show_name()<<" "+birth<<" "+vw[i].show_phonenumber()<<" "<<vw[i].show_email()<<" "<<chinesepart<<"\n";
    }
    for(i=0;i<vr.size();i++)
    {
        QString birth = QString::number(vr[i].show_birthday());
        if(birth.size()==3)
        {
            birth.insert(0,"0");
        }
        QString chinesepart = vr[i].show_address().toUtf8();
      in<<vr[i].show_name()<<" "+birth<<" "+vr[i].show_phonenumber()<<" "<<vr[i].show_email()<<" "<<chinesepart<<"\n";
    }
    ffriend.close();fworkmate.close();fclassmate.close();frelative.close();fbirthday.close();
    fbirthday.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream outp(&fbirthday);
    QVector<People> vp;
    while (!outp.atEnd()) {
        outp>>name>>birthd>>phonenumber>>email>>special;
        birthday = birthd.toInt();
        vp.push_back(People(name,birthday,phonenumber,email,special));
    }
    vp.pop_back();
    fbirthday.close();
    QVector<Peoplus> vs;
    int day_int = day.toInt();
    if(date[0]=='0')
    {
        if(date[1]=='1'||date[1]=='3'||date[1]=='5'||date[1]=='7'||date[1]=='8'){
           QString dates = date.mid(2,2);
           int dates_int = dates.toInt();
           int date_int = date.toInt();
           if(dates_int>26)
           {
               int a = 31-dates_int;
               int max_date_int = date_int+100-dates_int+5-a;
               for(i=0;i<vp.size();i++)
               {
                   if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                   {
                       int pass;day_int = day.toInt();
                       if(vp[i].show_birth()>date_int+5)
                       {
                           pass = a + vp[i].show_birth()-(date_int+100-dates_int);
                       }
                       else pass = vp[i].show_birth()-date_int;
                       if(day_int+pass>7)
                       {
                           day_int = day_int+pass-7;
                       }
                       else day_int += pass;
                       vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                   }
               }
           }
           else if(dates_int<=26)
           {
               int max_date_int = date_int+5;
               for(i=0;i<vp.size();i++)
               {
                   if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                   {
                       int pass;day_int = day.toInt();
                       pass = vp[i].show_birth()-date_int;
                       if(day_int+pass>7)
                       {
                           day_int = day_int+pass-7;
                       }
                       else day_int += pass;
                       vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                   }
               }
           }
        }
        else if(date[1]=='4'||date[1]=='6'||date[1]=='9'){
           QString dates = date.mid(2,2);
           int dates_int = dates.toInt();
           int date_int = date.toInt();
           if(dates_int>25)
           {
               int a = 30-dates_int;
               int max_date_int = date_int+100-dates_int+5-a;
               for(i=0;i<vp.size();i++)
               {
                   if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                   {
                   int pass;day_int = day.toInt();
                   if(vp[i].show_birth()>date_int+5)
                   {
                       pass = a + vp[i].show_birth()+100-dates_int;
                   }
                   else pass = vp[i].show_birth()-date_int;
                   if(day_int+pass>7)
                   {
                       day_int = day_int+pass-7;
                   }
                   else day_int += pass;
                       vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                   }
               }
           }
           else if(dates_int<=25)
           {
               int max_date_int = date_int+5;
               for(i=0;i<vp.size();i++)
               {
                   if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                   {
                       int pass;day_int = day.toInt();
                       pass = vp[i].show_birth()-date_int;
                       if(day_int+pass>7)
                       {
                           day_int = day_int+pass-7;
                       }
                       else day_int += pass;
                       vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                   }
               }
           }
        }
        else if(date[1]=='2')
        {
            if(is_leap)
            {
                QString dates = date.mid(2,2);
                int dates_int = dates.toInt();
                int date_int = date.toInt();
                if(dates_int>24)
                {
                    int a = 29-dates_int;
                    int max_date_int = date_int+100-dates_int+5-a;
                    for(i=0;i<vp.size();i++)
                    {

                        if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                        {
                            int pass;day_int = day.toInt();
                            if(vp[i].show_birth()>date_int+5)
                            {
                                pass = a + vp[i].show_birth()-(date_int+100-dates_int);
                            }
                            else pass = vp[i].show_birth()-date_int;
                            if(day_int+pass>7)
                            {
                                day_int = day_int+pass-7;
                            }
                            else day_int += pass;
                            vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                        }
                    }
                }
                else if(dates_int<=24)
                {
                    int max_date_int = date_int+5;
                    for(i=0;i<vp.size();i++)
                    {
                        if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                        {
                            int pass;day_int = day.toInt();
                            pass = vp[i].show_birth()-date_int;
                            if(day_int+pass>7)
                            {
                                day_int = day_int+pass-7;
                            }
                            else day_int += pass;
                            vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                        }
                    }
                }
            }
                else if(isnot_leap)
                {
                    QString dates = date.mid(2,2);
                    int dates_int = dates.toInt();
                    int date_int = date.toInt();
                    if(dates_int>23)
                    {
                        int a = 28-dates_int;
                        int max_date_int = date_int+100-dates_int+5-a;
                        for(i=0;i<vp.size();i++)
                        {
                            if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                            {
                                int pass;day_int = day.toInt();
                                if(vp[i].show_birth()>date_int+5)
                                {
                                    pass = a + vp[i].show_birth()-(date_int+100-dates_int);
                                }
                                else pass = vp[i].show_birth()-date_int;
                                if(day_int+pass>7)
                                {
                                    day_int = day_int+pass-7;
                                }
                                else day_int += pass;
                                vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                            }
                        }
                    }
                    else if(dates_int<=23)
                    {
                        int max_date_int = date_int+5;
                        for(i=0;i<vp.size();i++)
                        {
                            if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                            {
                                int pass;day_int = day.toInt();
                                pass = vp[i].show_birth()-date_int;
                                if(day_int+pass>7)
                                {
                                    day_int = day_int+pass-7;
                                }
                                else day_int += pass;
                                vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                            }
                        }
                    }
                }
            }
        }
    else if(date[0]=='1')
    {
        if(date[1]=='0')
        {
            QString dates = date.mid(2,2);
            int dates_int = dates.toInt();
            int date_int = date.toInt();
            if(dates_int>26)
            {
                int a = 31-dates_int;
                int max_date_int = date_int+100-dates_int+5-a;
                for(i=0;i<vp.size();i++)
                {

                    if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                    {
                        int pass;day_int = day.toInt();
                        if(vp[i].show_birth()>date_int+5)
                        {
                            pass = a + vp[i].show_birth()-(date_int+100-dates_int);
                        }
                        else pass = vp[i].show_birth()-date_int;
                        if(day_int+pass>7)
                        {
                            day_int = day_int+pass-7;
                        }
                        else day_int += pass;
                        vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                    }
                }
            }
            else if(dates_int<=26)
            {
                int max_date_int = date_int+5;
                for(i=0;i<vp.size();i++)
                {
                    if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                    {
                        int pass;day_int = day.toInt();
                        pass = vp[i].show_birth()-date_int;
                        if(day_int+pass>7)
                        {
                            day_int = day_int+pass-7;
                        }
                        else day_int += pass;
                        vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                    }
                }
            }
        }
        else if(date[1]=='1')
        {
            QString dates = date.mid(2,2);
            int dates_int = dates.toInt();
            int date_int = date.toInt();
            if(dates_int>25)
            {
                int a = 30-dates_int;
                int max_date_int = date_int+100-dates_int+5-a;
                for(i=0;i<vp.size();i++)
                {
                    if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                    {
                        int pass;day_int = day.toInt();
                        if(vp[i].show_birth()>date_int+5)
                        {
                            pass = a + vp[i].show_birth()-(date_int+100-dates_int);
                        }
                        else pass = vp[i].show_birth()-date_int;
                        if(day_int+pass>7)
                        {
                            day_int = day_int+pass-7;
                        }
                        else day_int += pass;
                        vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                    }
                }
            }
            else if(dates_int<=25)
            {
                int max_date_int = date_int+5;
                for(i=0;i<vp.size();i++)
                {
                    if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                    {
                        int pass;day_int = day.toInt();
                        pass = vp[i].show_birth()-date_int;
                        if(day_int+pass>7)
                        {
                            day_int = day_int+pass-7;
                        }
                        else day_int += pass;
                        vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                    }
                }
            }
        }
        else if(date[1]=='2')
        {
            QString dates = date.mid(2,2);
            int dates_int = dates.toInt();
            int date_int = date.toInt();
            if(dates_int<=26)
             {
              int max_date_int = date_int+5;
              for(i=0;i<vp.size();i++)
               {
                  if(vp[i].show_birth()>date_int&&vp[i].show_birth()<=max_date_int)
                   {
                      int pass;day_int = day.toInt();
                      pass = vp[i].show_birth()-date_int;
                      if(day_int+pass>7)
                      {
                          day_int = day_int+pass-7;
                      }
                      else day_int += pass;
                     vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                   }
                }
              }
            else if(dates_int>26)
            {
                int a = 31-dates_int;
                int b =5-a;
                for(i=0;i<vp.size();i++)
                {
                    if((vp[i].show_birth()>date_int&&vp[i].show_birth()<=1231)||(vp[i].show_birth()<=100+b))
                    {
                        if(vp[i].show_birth()>=1227)
                        {
                            int pass = vp[i].show_birth()-date_int;day_int = day.toInt();
                            if(day_int+pass>7)
                            {
                                day_int = day_int+pass-7;
                            }
                            else day_int+=pass;
                         }
                        else if(vp[i].show_birth()<200)
                        {
                            int pass = vp[i].show_birth()-100+a;day_int = day.toInt();
                            if(day_int+pass>7)
                            {
                                day_int = day_int+pass-7;
                            }
                            else day_int+=pass;
                        }
                         vs.push_back(Peoplus(vp[i].show_name(),vp[i].show_birth(),vp[i].show_phonenumber(),vp[i].show_email(),vp[i].show_specialinfomation(),day_int));
                    }
                }
            }
        }
    }
    fbirthday.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream inb(&fbirthday);
    for(i=0;i<vs.size();i++)
    {
        QString birth = QString::number(vs[i].show_birth());
        QString weekday = vs[i].show_birthdayweekday().toUtf8();
        if(birth.size()==3)
        {
            birth.insert(0,"0");
        }
        QString chinesepart = vs[i].show_specialinfomation().toUtf8();
      inb<<vs[i].show_name()<<" "+birth<<" "+vs[i].show_phonenumber()<<" "<<vs[i].show_email()<<" "<<chinesepart<<" "<<weekday<<"\n";
    }
    fbirthday.close();
    fbirthday.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream outb(&fbirthday);
    ui->t_show->setText(outb.readAll());
    fbirthday.close();
    QString femailname = "Birthdayemail0.txt";
    char ii = 'a';
    for(i=0;i<vs.size();i++)
    {
        femailname.replace(13,1,ii);
        QFile bemail(femailname);
        bemail.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream fout(&bemail);
        QString words = "       祝贺生日快乐，身体健康";
        QString Myname = "                                                     梁伟西";
        words = words.toUtf8();
        Myname = Myname.toUtf8();
        fout<<vs[i].show_name()<<":\n"<<words<<"\n"<<Myname<<endl;
        bemail.close();
        ii++;
    }
}
