#include "serch.h"
#include "ui_serch.h"
#include<QMessageBox>
#include<QDebug>
#include<QTimer>
Serch::Serch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Serch)
{
    ui->setupUi(this);
    setFixedSize(713,604);
    connect(ui->back,&QPushButton::clicked,this,[=](){
       emit backtomain();
       ui->t_friend->clear();
       ui->t_relative->clear();
       ui->t_classmate->clear();
       ui->t_workmate->clear();
    });
    connect(ui->b_friend,&QPushButton::clicked,this,&Serch::fsearch);
    connect(ui->b_workmate,&QPushButton::clicked,this,[=](){
        QString getname = ui->t_workmate->toPlainText();
        QFile wfile("Workmate.txt");
        wfile.open(QIODevice::ReadOnly|QIODevice::Text);
        QVector<Workmate> wf;
        QTextStream out(&wfile);
        int birthday, i ,flag;
        i= flag =0;
        QString name,phonenumber,email,company, birthd,birth;
        while(!out.atEnd())
        {
            out>>name>>birthd>>phonenumber>>email>>company;
            birthday = birthd.toInt();
            wf.push_back(Workmate(name,birthday,phonenumber,email,company));
        }
        wfile.close();
        while (i<wf.size()) {
            if(getname==wf[i].show_name())
            {
               birth = QString::number(wf[i].show_birthday());
               int k =birth.size();
               if(k==4)
               {
                   birth.insert(2,'.');
               }
               else if(k==3)
               {
                   birth.insert(1,'.');
               }
               QString inf = wf[i].show_name()+" "+birth+" "+wf[i].show_phonenumber()+" "+wf[i].show_email()+" "+wf[i].show_company();
               ui->t_workmate->setText(inf);
               flag = 1;
               break;
            }
            i++;
        }
        if (!flag)
        {
            ui->t_workmate->setText("找不到！");
        }
    });
    connect(ui->b_classmate,&QPushButton::clicked,this,[=](){
        QString getname = ui->t_classmate->toPlainText();
        QFile cfile("Classmate.txt");
        cfile.open(QIODevice::ReadOnly|QIODevice::Text);
        QVector<Classmate> cf;
        QTextStream out(&cfile);
        int birthday, i ,flag;
        i= flag =0;
        QString name,phonenumber,email,school, birthd,birth;
        while(!out.atEnd())
        {
            out>>name>>birthd>>phonenumber>>email>>school;
            birthday = birthd.toInt();
            cf.push_back(Classmate(name,birthday,phonenumber,email,school));
        }
        cfile.close();
        while (i<cf.size()) {
            if(getname==cf[i].show_name())
            {
               birth = QString::number(cf[i].show_birthday());
               int k =birth.size();
               if(k==4)
               {
                   birth.insert(2,'.');
               }
               else if(k==3)
               {
                   birth.insert(1,'.');
               }
               QString inf = cf[i].show_name()+" "+birth+" "+cf[i].show_phonenumber()+" "+cf[i].show_email()+" "+cf[i].show_school();
               ui->t_classmate->setText(inf);
               flag = 1;
               break;
            }
            i++;
        }
        if (!flag)
        {
            ui->t_classmate->setText("找不到！");
        }
    });
    connect(ui->b_relative,&QPushButton::clicked,this,[=](){
        QString getname = ui->t_relative->toPlainText();
        QFile rfile("Relative.txt");
        rfile.open(QIODevice::ReadOnly|QIODevice::Text);
        QVector<Relative> rf;
        QTextStream out(&rfile);
        int birthday, i ,flag;
        i= flag =0;
        QString name,phonenumber,email,call, birth,birthd;
        while(!out.atEnd())
        {
            out>>name>>birthd>>phonenumber>>email>>call;
            birthday=birthd.toInt();
            rf.push_back(Relative(name,birthday,phonenumber,email,call));
        }
        rfile.close();
        while (i<rf.size()) {
            if(getname==rf[i].show_name())
            {
               birth = QString::number(rf[i].show_birthday());
               int k =birth.size();
               if(k==4)
               {
                   birth.insert(2,'.');
               }
               else if(k==3)
               {
                   birth.insert(1,'.');
               }
               QString inf = rf[i].show_name()+" "+birth+" "+rf[i].show_phonenumber()+" "+rf[i].show_email()+" "+rf[i].show_address();
               ui->t_relative->setText(inf);
               flag = 1;
               break;
            }
            i++;
        }
        if (!flag)
        {
            ui->t_relative->setText("找不到！");
        }
    });
}

Serch::~Serch()
{
    delete ui;
}

void Serch::fsearch()
{
    QString getname = ui->t_friend->toPlainText();
    QFile ffile("Friend.txt");
    ffile.open(QIODevice::ReadOnly|QIODevice::Text);
    QVector<Friend> vf;
    QTextStream out(&ffile);
    int birthday, i ,flag;
    i= flag =0;
    QString name,phonenumber,email,knownplace, birthd,birth;
    while(!out.atEnd())
    {
        out>>name>>birthd>>phonenumber>>email>>knownplace;
        birthday=birthd.toInt();
        vf.push_back(Friend(name,birthday,phonenumber,email,knownplace));
    }
    ffile.close();
    while (i<vf.size()) {
        if(getname==vf[i].show_name())
        {
           birth = QString::number(vf[i].show_birthday());
           int k =birth.size();
           if(k==4)
           {
               birth.insert(2,'.');
           }
           else if(k==3)
           {
               birth.insert(1,'.');
           }
           QString inf = vf[i].show_name()+" "+birth+" "+vf[i].show_phonenumber()+" "+vf[i].show_email()+" "+vf[i].show_knownplace();
           qDebug()<<inf;
           ui->t_friend->setText(inf);
           flag = 1;
           break;
        }
        i++;
    }
    if (!flag)
    {
        ui->t_friend->setText("找不到！");
    }
}
