#include "modifypage.h"
#include "ui_modifypage.h"
#include<QDebug>
Modifypage::Modifypage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modifypage)
{
    ui->setupUi(this);
    setFixedSize(712,639);
    connect(ui->back,&QPushButton::clicked,this,[=](){
       emit backtomain();
    });
    connect(ui->b_friend,&QPushButton::clicked,this,&Modifypage::modify_friend);
    connect(ui->b_relative,&QPushButton::clicked,this,&Modifypage::modify_relative);
    connect(ui->b_workmate,&QPushButton::clicked,this,&Modifypage::modify_workmate);
    connect(ui->b_classmate,&QPushButton::clicked,this,&Modifypage::modify_classmate);
}

Modifypage::~Modifypage()
{
    delete ui;
}

void Modifypage::modify_friend()
{
    QFile ffriend("Friend.txt");
    ffriend.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream out(&ffriend);
    QVector<Friend> vf;
    int birthday, i ,flag;
    i= flag =0;
    QString name,phonenumber,email,school, birthd,birth;
    while(!out.atEnd())
    {
        out>>name>>birthd>>phonenumber>>email>>school;
        birthday = birthd.toInt();
        vf.push_back(Friend(name,birthday,phonenumber,email,school));
    }
    vf.pop_back();
    QString getfriendname = ui->f_t_name->toPlainText();
    for(i=0;i<vf.size();i++)
    {
        if(getfriendname==vf[i].show_name())
        {
            if(ui->f__t_phonenum->toPlainText()!="")
            {
                QString newphonenumber = ui->f__t_phonenum->toPlainText();
                vf[i].modify_phonenumber(newphonenumber);
            }
            if(ui->f_t_email->toPlainText()!="")
            {
                QString newemail = ui->f_t_email->toPlainText();
                vf[i].modify_email(newemail);
            }
            if(ui->f_t_kplace->toPlainText()!="")
            {
                QString newkplace = ui->f_t_kplace->toPlainText();
                vf[i].modify_particularinf(newkplace);
            }
            flag = 1;
            break;
        }
    }
    ffriend.close();
    ffriend.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream in(&ffriend);
    i=0;
    while (i<vf.size()) {
        QString kplace = vf[i].show_knownplace().toUtf8();
        QString birth1 = QString::number(vf[i].show_birthday());
        if(birth1.size()==3)
        {
            birth1.insert(0,"0");
        }
        in<<vf[i].show_name()<<" "<<birth1<<" "<<vf[i].show_phonenumber()<<" "<<vf[i].show_email()<<" "<<kplace<<endl;
        i++;
    }
    ui->f_t_name->clear();
    ui->f_t_email->clear();
    ui->f__t_phonenum->clear();
    ui->f_t_kplace->clear();
    if(flag)
    {
        QMessageBox::information(this,"修改","修改成功！",QMessageBox::Ok);
    }
    ffriend.close();
}

void Modifypage::modify_workmate()
{
    QFile fworkmate("Workmate.txt");
    fworkmate.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream out(&fworkmate);
    QVector<Workmate> vw;
    int birthday, i ,flag;
    i= flag =0;
    QString name,phonenumber,email,company, birthd,birth;
    while(!out.atEnd())
    {
        out>>name>>birthd>>phonenumber>>email>>company;
        birthday = birthd.toInt();
        vw.push_back(Workmate(name,birthday,phonenumber,email,company));
    }
    vw.pop_back();
    QString getworkmatename = ui->w_t_name->toPlainText();
    for(i=0;i<vw.size();i++)
    {
        if(getworkmatename==vw[i].show_name())
        {
            if(ui->w_t_phonenum->toPlainText()!="")
            {
                QString newphonenumber = ui->w_t_phonenum->toPlainText();
                vw[i].modify_phonenumber(newphonenumber);
            }
            if(ui->w_t_email->toPlainText()!="")
            {
                QString newemail = ui->w_t_email->toPlainText();
                vw[i].modify_email(newemail);
            }
            if(ui->w_t_company->toPlainText()!="")
            {
                QString newkplace = ui->w_t_company->toPlainText();
                vw[i].modify_particularinf(newkplace);
            }
            flag = 1;
            break;
        }
    }
    fworkmate.close();
    fworkmate.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream in(&fworkmate);
    i=0;
    while (i<vw.size()) {
        QString kplace = vw[i].show_company().toUtf8();
        QString birth1 = QString::number(vw[i].show_birthday());
        if(birth1.size()==3)
        {
            birth1.insert(0,"0");
        }
        in<<vw[i].show_name()<<" "<<birth1<<" "<<vw[i].show_phonenumber()<<" "<<vw[i].show_email()<<" "<<kplace<<endl;
        i++;
    }
    ui->w_t_name->clear();
    ui->w_t_email->clear();
    ui->w_t_phonenum->clear();
    ui->w_t_company->clear();
    if(flag)
    {
        QMessageBox::information(this,"修改","修改成功！",QMessageBox::Ok);
    }

    fworkmate.close();
}


void Modifypage::modify_classmate()
{
    QFile fclassmate("Classmate.txt");
    fclassmate.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream out(&fclassmate);
    QVector<Classmate> vc;
    int birthday, i ,flag;
    i= flag =0;
    QString name,phonenumber,email,school, birthd,birth;
    while(!out.atEnd())
    {
        out>>name>>birthd>>phonenumber>>email>>school;
        birthday = birthd.toInt();
        vc.push_back(Classmate(name,birthday,phonenumber,email,school));
    }
    vc.pop_back();
    QString getworkmatename = ui->c_t_name->toPlainText();
    for(i=0;i<vc.size();i++)
    {
        if(getworkmatename==vc[i].show_name())
        {
            if(ui->c_t_phonenum->toPlainText()!="")
            {
                QString newphonenumber = ui->c_t_phonenum->toPlainText();
                vc[i].modify_phonenumber(newphonenumber);
            }
            if(ui->c_t_email->toPlainText()!="")
            {
                QString newemail = ui->c_t_email->toPlainText();
                vc[i].modify_email(newemail);
            }
            if(ui->c_t_school->toPlainText()!="")
            {
                QString newkplace = ui->c_t_school->toPlainText();
                vc[i].modify_particularinf(newkplace);
            }
            flag = 1;
            break;
        }
    }
    fclassmate.close();
    fclassmate.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream in(&fclassmate);
    i=0;
    while (i<vc.size()) {
        QString kplace = vc[i].show_school().toUtf8();
        QString birth1 = QString::number(vc[i].show_birthday());
        if(birth1.size()==3)
        {
            birth1.insert(0,"0");
        }
        in<<vc[i].show_name()<<" "<<birth1<<" "<<vc[i].show_phonenumber()<<" "<<vc[i].show_email()<<" "<<kplace<<endl;
        i++;
    }
    ui->c_t_name->clear();
    ui->c_t_email->clear();
    ui->c_t_phonenum->clear();
    ui->c_t_school->clear();
    if(flag)
    {
        QMessageBox::information(this,"修改","修改成功！",QMessageBox::Ok);
    }
    fclassmate.close();
}

void Modifypage::modify_relative()
{
    QFile frelative("Relative.txt");
    frelative.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream out(&frelative);
    QVector<Relative> vr;
    int birthday, i ,flag;
    i= flag =0;
    QString name,phonenumber,email,address, birthd,birth;
    while(!out.atEnd())
    {
        out>>name>>birthd>>phonenumber>>email>>address;
        birthday = birthd.toInt();
        vr.push_back(Relative(name,birthday,phonenumber,email,address));
    }
    vr.pop_back();
    QString getrelativename = ui->r_t_name->toPlainText();
    for(i=0;i<vr.size();i++)
    {
        if(getrelativename==vr[i].show_name())
        {
            if(ui->r_t_phonenum->toPlainText()!="")
            {
                QString newphonenumber = ui->r_t_phonenum->toPlainText();
                vr[i].modify_phonenumber(newphonenumber);
            }
            if(ui->w_t_email->toPlainText()!="")
            {
                QString newemail = ui->r_t_email->toPlainText();
                vr[i].modify_email(newemail);
            }
            if(ui->r_t_address->toPlainText()!="")
            {
                QString newkplace = ui->r_t_address->toPlainText();
                vr[i].modify_particularinf(newkplace);
            }
            flag = 1;
            break;
        }
    }
    frelative.close();
    frelative.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream in(&frelative);
    i=0;
    while (i<vr.size()) {
        QString kplace = vr[i].show_address().toUtf8();
        QString birth1 = QString::number(vr[i].show_birthday());
        if(birth1.size()==3)
        {
            birth1.insert(0,"0");
        }
        in<<vr[i].show_name()<<" "<<birth1<<" "<<vr[i].show_phonenumber()<<" "<<vr[i].show_email()<<" "<<kplace<<endl;
        i++;
    }
    ui->r_t_name->clear();
    ui->r_t_email->clear();
    ui->r_t_phonenum->clear();
    ui->r_t_address->clear();
    if(flag)
    {
        QMessageBox::information(this,"修改","修改成功！",QMessageBox::Ok);
    }
    frelative.close();
}
