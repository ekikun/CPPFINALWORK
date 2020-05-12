#include "namesort.h"
#include "ui_namesort.h"
#include<QDebug>
Namesort::Namesort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Namesort)
{
    ui->setupUi(this);
    setFixedSize(713,604);
    connect(ui->back,&QPushButton::clicked,this,[=](){
       emit backtomain();
    });
    connect(ui->output,&QPushButton::clicked,this,[=](){
        QFile ffriend("Friend.txt");
        QFile fclassmate("Classmate.txt");
        QFile fworkmate("Workmate.txt");
        QFile frelative("Relative.txt");
        QFile ftotal("Totalname.txt");
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
            if(birth.size()==3)
            {
                birth.insert(0,"0");
            }
           in<<vf[i].show_name()<<" "+birth<<" "+vf[i].show_phonenumber()<<" "<<vf[i].show_email()<<" "<<chinesepart<<"\n";
        }
        for(i=0;i<vc.size();i++)
        {
            QString birth = QString::number(vc[i].show_birthday());
            QString chinesepart = vc[i].show_school().toUtf8();
            if(birth.size()==3)
            {
                birth.insert(0,"0");
            }
            in<<vc[i].show_name()<<" "+birth<<" "+vc[i].show_phonenumber()<<" "<<vc[i].show_email()<<" "<<chinesepart<<"\n";
        }
        for(i=0;i<vw.size();i++)
        {
            QString birth = QString::number(vw[i].show_birthday());
            QString chinesepart = vw[i].show_company().toUtf8();
            if(birth.size()==3)
            {
                birth.insert(0,"0");
            }
           in<<vw[i].show_name()<<" "+birth<<" "+vw[i].show_phonenumber()<<" "<<vw[i].show_email()<<" "<<chinesepart<<"\n";
        }
        for(i=0;i<vr.size();i++)
        {
            QString birth = QString::number(vr[i].show_birthday());
            QString chinesepart = vr[i].show_address().toUtf8();
            if(birth.size()==3)
            {
                birth.insert(0,"0");
            }
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
        int j;
        People temp;
        for(i=0;i<vp.size()-1;i++)
        {
            for(j=0;j<vp.size()-i-1;j++)
            {
                if(vp[j].show_name()>vp[j+1].show_name())
                {
                    temp = vp[j];
                    vp[j] = vp[j+1];
                    vp[j+1] = temp;
                }
            }
        }
        ftotal.close();
        ftotal.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream inp(&ftotal);
        for(i=0;i<vp.size();i++)
        {
            QString birth = QString::number(vp[i].show_birth());
            QString chinesepart = vp[i].show_specialinfomation().toUtf8();
            if(birth.size()==3)
            {
                birth.insert(0,"0");
            }
          inp<<vp[i].show_name()<<" "+birth<<" "+vp[i].show_phonenumber()<<" "<<vp[i].show_email()<<" "<<chinesepart<<"\n";
        }
        ftotal.close();
        ftotal.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream out(&ftotal);
        ui->textEdit->setText(out.readAll());
        ftotal.close();
    });
    connect(ui->clear,&QPushButton::clicked,this,[=](){
        ui->textEdit->clear();
        QFile ftotal("Totalname.txt");
        ftotal.open(QIODevice::WriteOnly|QIODevice::Truncate);
        ftotal.close();
    });

}

Namesort::~Namesort()
{
    delete ui;
}
