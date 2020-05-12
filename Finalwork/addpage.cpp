#include "addpage.h"
#include "ui_addpage.h"
#include<QFile>
#include<iostream>
#include<QString>
#include<QTextStream>
#include<QMessageBox>
#include<QFileInfo>
addpage::addpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addpage)
{
    ui->setupUi(this);
    setFixedSize(713,604);
    connect(ui->back,&QPushButton::clicked,this,[=](){
       emit backtomain();
    });
    connect(ui->b_friend,&QPushButton::clicked,this,[=](){
        QFileInfo ffile("Friend.txt");
        QFile filefriend("Friend.txt");
        QTextStream out(&filefriend);
        if(ffile.isFile())
        {
            filefriend.open(QIODevice::Text|QIODevice::Append);
        }
        else
        {
            filefriend.open(QIODevice::WriteOnly|QIODevice::Text);
        }
        out<<ui->t_friend->toPlainText();
        ui->t_friend->clear();
        QMessageBox::information(this,"保存","保存成功",QMessageBox::Ok);
        filefriend.close();
    });
    connect(ui->b_classmate,&QPushButton::clicked,this,[=](){
        QFileInfo cfile("Classmate.txt");
        QFile fileclassmate("Classmate.txt");
        QTextStream out(&fileclassmate);
        if(cfile.isFile())
        {
            fileclassmate.open(QIODevice::Text|QIODevice::Append);
        }
        else
        {
            fileclassmate.open(QIODevice::WriteOnly|QIODevice::Text);
        }
        out<<ui->t_classmate->toPlainText();
        ui->t_classmate->clear();
        QMessageBox::information(this,"保存","保存成功",QMessageBox::Ok);
        fileclassmate.close();
    });
    connect(ui->b_workmate,&QPushButton::clicked,this,[=](){
        QFileInfo wfile("Workmate.txt");
        QFile fileworkmate("Workmate.txt");
        QTextStream out(&fileworkmate);
        if(wfile.isFile())
        {
            fileworkmate.open(QIODevice::Text|QIODevice::Append);
        }
        else
        {
            fileworkmate.open(QIODevice::WriteOnly|QIODevice::Text);
        }
        out<<ui->t_workmate->toPlainText();
        ui->t_workmate->clear();
        QMessageBox::information(this,"保存","保存成功",QMessageBox::Ok);
        fileworkmate.close();
    });
    connect(ui->b_relative,&QPushButton::clicked,this,[=](){
        QFileInfo rfile("Relative.txt");
        QFile filerelative("Relative.txt");
        QTextStream out(&filerelative);
        if(rfile.isFile())
        {
            filerelative.open(QIODevice::Text|QIODevice::Append);
        }
        else
        {
            filerelative.open(QIODevice::WriteOnly|QIODevice::Text);
        }
        out<<ui->t_relative->toPlainText();
        ui->t_relative->clear();
        QMessageBox::information(this,"保存","保存成功",QMessageBox::Ok);
        filerelative.close();
    });
}

addpage::~addpage()
{
    delete ui;
}
