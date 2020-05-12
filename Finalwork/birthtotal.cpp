#include "birthtotal.h"
#include "ui_birthtotal.h"
#include<QTimer>
Birthtotal::Birthtotal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Birthtotal)
{
    ui->setupUi(this);
    setFixedSize(530,535);
    connect(ui->back,&QPushButton::clicked,this,[=](){
       emit backtomain();
        QTimer::singleShot(300,this,[=](){
            ui->t_1->clear();
            ui->t_2->clear();
            ui->t_3->clear();
            ui->t_4->clear();
            ui->t_5->clear();
            ui->t_6->clear();
            ui->t_7->clear();
            ui->t_8->clear();
            ui->t_9->clear();
            ui->t_10->clear();
            ui->t_11->clear();
            ui->t_12->clear();
        });
       QFile ftotal("Totalcount.txt");
       ftotal.open(QIODevice::WriteOnly|QIODevice::Truncate);
       ftotal.close();
    });
    connect(ui->Start,&QPushButton::clicked,this,&Birthtotal::count);
}

Birthtotal::~Birthtotal()
{
    delete ui;
}


void Birthtotal::count()
{
    QFile ffriend("Friend.txt");
    QFile fclassmate("Classmate.txt");
    QFile fworkmate("Workmate.txt");
    QFile frelative("Relative.txt");
    QFile ftotal("Totalcount.txt");
    QVector<Friend> vf; QVector<Workmate> vw; QVector<Classmate> vc; QVector<Relative> vr;
    ffriend.open(QIODevice::ReadOnly|QIODevice::Text);
    fclassmate.open(QIODevice::ReadOnly|QIODevice::Text);
    fworkmate.open(QIODevice::ReadOnly|QIODevice::Text);
    frelative.open(QIODevice::ReadOnly|QIODevice::Text);
    ftotal.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream outf(&ffriend);QTextStream outc(&fclassmate);QTextStream outw(&fworkmate);QTextStream outr(&frelative);
    QTextStream in(&ftotal);
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
        QString chinesepart = vf[i].show_knownplace().toUtf8();
       in<<vf[i].show_name()<<" "+birth<<" "+vf[i].show_phonenumber()<<" "<<vf[i].show_email()<<" "<<chinesepart<<"\n";
    }
    for(i=0;i<vc.size();i++)
    {
        QString birth = QString::number(vc[i].show_birthday());
        QString chinesepart = vc[i].show_school().toUtf8();
        in<<vc[i].show_name()<<" "+birth<<" "+vc[i].show_phonenumber()<<" "<<vc[i].show_email()<<" "<<chinesepart<<"\n";
    }
    for(i=0;i<vw.size();i++)
    {
        QString birth = QString::number(vw[i].show_birthday());
        QString chinesepart = vw[i].show_company().toUtf8();
       in<<vw[i].show_name()<<" "+birth<<" "+vw[i].show_phonenumber()<<" "<<vw[i].show_email()<<" "<<chinesepart<<"\n";
    }
    for(i=0;i<vr.size();i++)
    {
        QString birth = QString::number(vr[i].show_birthday());
        QString chinesepart = vr[i].show_address().toUtf8();
      in<<vr[i].show_name()<<" "+birth<<" "+vr[i].show_phonenumber()<<" "<<vr[i].show_email()<<" "<<chinesepart<<"\n";
    }
    ffriend.close();fworkmate.close();fclassmate.close();frelative.close();ftotal.close();
    ftotal.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream outp(&ftotal);
    QVector<People> vp;
    while (!outp.atEnd()) {
        outp>>name>>birthd>>phonenumber>>email>>special;
        birthday = birthd.toInt();
        vp.push_back(People(name,birthday,phonenumber,email,special));
    }
    vp.pop_back();
    int jan, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec;
    jan=feb=mar=apr=may=jun=jul=aug=sept=oct=nov=dec=0;
    for(i=0;i<vp.size();i++)
    {
        birth = QString::number(vp[i].show_birth());
        if(birth.size()==3)
        {
            if(birth[0]=='1')
            {
                jan++;
            }
            else if(birth[0]=='2')
            {
                feb++;
            }
            else if(birth[0]=='3')
            {
                mar++;
            }
            else if(birth[0]=='4')
            {
                apr++;
            }
            else if(birth[0]=='5')
            {
                may++;
            }
            else if(birth[0]=='6')
            {
                jun++;
            }
            else if(birth[0]=='7')
            {
                jul++;
            }
            else if(birth[0]=='8')
            {
                aug++;
            }
            else if(birth[0]=='9')
            {
                sept++;
            }
        }
        else if(birth.size()==4)
        {
            if(birth[1]=='0')
            {
                oct++;
            }
            else if(birth[1]=='1')
            {
                nov++;
            }
            else if(birth[1]=='2')
            {
                dec++;
            }
        }
    }
    ui->t_1->setText(QString::number(jan));
    ui->t_2->setText(QString::number(feb));
    ui->t_3->setText(QString::number(mar));
    ui->t_4->setText(QString::number(apr));
    ui->t_5->setText(QString::number(may));
    ui->t_6->setText(QString::number(jun));
    ui->t_7->setText(QString::number(jul));
    ui->t_8->setText(QString::number(aug));
    ui->t_9->setText(QString::number(sept));
    ui->t_10->setText(QString::number(oct));
    ui->t_11->setText(QString::number(nov));
    ui->t_12->setText(QString::number(dec));
    jan=feb=mar=apr=may=jun=jul=aug=sept=oct=nov=dec=0;
}
