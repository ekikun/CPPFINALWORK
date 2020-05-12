#include "outputall.h"
#include "ui_outputall.h"
Outputall::Outputall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Outputall)
{
    ui->setupUi(this);
    setFixedSize(724,680);
    connect(ui->back,&QPushButton::clicked,this,[=](){
        emit backtomain();
    });
    connect(ui->output,&QPushButton::clicked,this,&Outputall::outall);
    connect(ui->clear,&QPushButton::clicked,this,[=](){
       ui->textEdit->clear();
       QFile ftotal("Total.txt");
       ftotal.open(QIODevice::WriteOnly|QIODevice::Truncate);
       ftotal.close();
    });
}

Outputall::~Outputall()
{
    delete ui;
}

void Outputall::outall()
{
    QFile ffriend("Friend.txt");
    QFile fclassmate("Classmate.txt");
    QFile fworkmate("Workmate.txt");
    QFile frelative("Relative.txt");
    QFile ftotal("Total.txt");
    QVector<Friend> vf; QVector<Workmate> vw; QVector<Classmate> vc; QVector<Relative> vr;
    ffriend.open(QIODevice::ReadOnly|QIODevice::Text);
    fclassmate.open(QIODevice::ReadOnly|QIODevice::Text);
    fworkmate.open(QIODevice::ReadOnly|QIODevice::Text);
    frelative.open(QIODevice::ReadOnly|QIODevice::Text);
    ftotal.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream outf(&ffriend);QTextStream outc(&fclassmate);QTextStream outw(&fworkmate);QTextStream outr(&frelative);
    QTextStream in(&ftotal);
    int birthday, i;
    QString name,phonenumber,email,school, birthd,birth,company,knowplace,address;
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
       in<<vf[i].show_name()<<" "+birth<<" "+vf[i].show_phonenumber()<<" "<<vf[i].show_email()<<"\n";
    }
    for(i=0;i<vc.size();i++)
    {
        QString birth = QString::number(vc[i].show_birthday());
        if(birth.size()==3)
        {
            birth.insert(0,"0");
        }
        in<<vc[i].show_name()<<" "+birth<<" "+vc[i].show_phonenumber()<<" "<<vc[i].show_email()<<"\n";
    }
    for(i=0;i<vw.size();i++)
    {
        QString birth = QString::number(vw[i].show_birthday());
        if(birth.size()==3)
        {
            birth.insert(0,"0");
        }
       in<<vw[i].show_name()<<" "+birth<<" "+vw[i].show_phonenumber()<<" "<<vw[i].show_email()<<"\n";
    }
    for(i=0;i<vr.size();i++)
    {
        QString birth = QString::number(vr[i].show_birthday());
        if(birth.size()==3)
        {
            birth.insert(0,"0");
        }
      in<<vr[i].show_name()<<" "+birth<<" "+vr[i].show_phonenumber()<<" "<<vr[i].show_email()<<"\n";
    }
    ftotal.close();
    ftotal.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream out_t(&ftotal);
    ui->textEdit->setText(out_t.readAll());
    ffriend.close();fworkmate.close();fclassmate.close();frelative.close();ftotal.close();
}
