#include "delepage.h"
#include "ui_delepage.h"
#include<QDebug>
Delepage::Delepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Delepage)
{
    ui->setupUi(this);
    setFixedSize(713,604);
    connect(ui->back,&QPushButton::clicked,this,[=](){
       emit backtomain();
    });
    connect(ui->b_friend,&QPushButton::clicked,this,[=](){
       QString getfriendname = ui->t_friend->toPlainText();
       QVector<Friend> vf;
       QFile ffriend("Friend.txt");
       ffriend.open(QIODevice::ReadOnly|QIODevice::Text);
       QTextStream out(&ffriend);
       int birthday, i ,flag;
       i= flag =0;
       QString name,phonenumber,email,konwplace, birthd,birth;
       while(!out.atEnd())
       {
           out>>name>>birthd>>phonenumber>>email>>konwplace;
           birthday = birthd.toInt();
           vf.push_back(Friend(name,birthday,phonenumber,email,konwplace));
       }
       vf.pop_back();
       for(i=0;i<vf.size();i++)
       {
           if(getfriendname==vf[i].show_name())
           {
               vf.erase(vf.begin()+i);
               flag = 1;
               break;
           }
       }
       if(flag)
       {
           ui->t_friend->clear();
           QMessageBox::information(this,"删除","删除成功！",QMessageBox::Ok);
       }
       ffriend.close();
       ffriend.open(QIODevice::WriteOnly|QIODevice::Text);
       QTextStream in(&ffriend);
       i=0;
       while(i<vf.size())
       {
           QString kplace = vf[i].show_knownplace().toUtf8();
           QString birth1 = QString::number(vf[i].show_birthday());
           if(birth1.size()==3)
           {
               birth1.insert(0,"0");
           }
           in<<vf[i].show_name()<<" "<<birth1<<" "<<vf[i].show_phonenumber()<<" "<<vf[i].show_email()<<" "<<kplace<<endl;
           i++;
       }
       ffriend.close();
    });
    connect(ui->b_classmate,&QPushButton::clicked,this,[=](){
        QString getclassmatename = ui->t_classmate->toPlainText();
        QVector<Classmate> cf;
        QFile fclassmate("Classmate.txt");
        fclassmate.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream out(&fclassmate);
        int birthday, i ,flag;
        i= flag =0;
        QString name,phonenumber,email,school, birthd,birth;
        while(!out.atEnd())
        {
            out>>name>>birthd>>phonenumber>>email>>school;
            birthday = birthd.toInt();
            cf.push_back(Classmate(name,birthday,phonenumber,email,school));
        }
        cf.pop_back();
        for(i=0;i<cf.size();i++)
        {
            if(getclassmatename==cf[i].show_name())
            {
                cf.erase(cf.begin()+i);
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            ui->t_classmate->clear();
            QMessageBox::information(this,"删除","删除成功！",QMessageBox::Ok);
        }
        fclassmate.close();
        fclassmate.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream in(&fclassmate);
        i=0;
        while(i<cf.size())
        {
            QString schools = cf[i].show_school().toUtf8();
            QString birth1 = QString::number(cf[i].show_birthday());
            if(birth1.size()==3)
            {
                birth1.insert(0,"0");
            }
            in<<cf[i].show_name()<<" "<<birth1<<" "<<cf[i].show_phonenumber()<<" "<<cf[i].show_email()<<" "<<schools<<endl;
            i++;
        }
        fclassmate.close();
    });
    connect(ui->b_relative,&QPushButton::clicked,this,[=](){
        QString getrelativename = ui->t_relative->toPlainText();
        QVector<Relative> rf;
        QFile frelative("Relative.txt");
        frelative.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream out(&frelative);
        int birthday, i ,flag;
        i= flag =0;
        QString name,phonenumber,email,address, birthd,birth;
        while(!out.atEnd())
        {
            out>>name>>birthd>>phonenumber>>email>>address;
            birthday = birthd.toInt();
            rf.push_back(Relative(name,birthday,phonenumber,email,address));
        }
        rf.pop_back();
        for(i=0;i<rf.size();i++)
        {
            if(getrelativename==rf[i].show_name())
            {
                rf.erase(rf.begin()+i);
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            ui->t_relative->clear();
            QMessageBox::information(this,"删除","删除成功！",QMessageBox::Ok);
        }
        frelative.close();
        frelative.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream in(&frelative);
        i=0;
        qDebug()<<rf.size();
        while(i<rf.size())
        {
            QString com = rf[i].show_address().toUtf8();
            QString birth1 = QString::number(rf[i].show_birthday());
            if(birth1.size()==3)
            {
                birth1.insert(0,"0");
            }
            in<<rf[i].show_name()<<" "<<birth1<<" "<<rf[i].show_phonenumber()<<" "<<rf[i].show_email()<<" "<<com<<endl;
            i++;
        }
        frelative.close();
    });
    connect(ui->b_workmate,&QPushButton::clicked,this,[=](){
        QString getworkmatename = ui->t_workmate->toPlainText();
        QVector<Workmate> wf;
        QFile fworkmate("Workmate.txt");
        fworkmate.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream out(&fworkmate);
        int birthday, i ,flag;
        i= flag =0;
        QString name,phonenumber,email,company, birthd,birth;
        while(!out.atEnd())
        {
            out>>name>>birthd>>phonenumber>>email>>company;
            birthday = birthd.toInt();
            wf.push_back(Workmate(name,birthday,phonenumber,email,company));
        }
        wf.pop_back();
        for(i=0;i<wf.size();i++)
        {
            if(getworkmatename==wf[i].show_name())
            {
                wf.erase(wf.begin()+i);
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            ui->t_workmate->clear();
            QMessageBox::information(this,"删除","删除成功！",QMessageBox::Ok);
        }
        fworkmate.close();
        fworkmate.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream in(&fworkmate);
        i=0;
        qDebug()<<wf.size();
        while(i<wf.size())
        {
            QString kplace = wf[i].show_company().toUtf8();
            QString birth1 = QString::number(wf[i].show_birthday());
            if(birth1.size()==3)
            {
                birth1.insert(0,"0");
            }
            in<<wf[i].show_name()<<" "<<birth1<<" "<<wf[i].show_phonenumber()<<" "<<wf[i].show_email()<<" "<<kplace<<endl;
            i++;
        }
        fworkmate.close();
    });
}

Delepage::~Delepage()
{
    delete ui;
}
