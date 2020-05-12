#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<addpage.h>
#include<serch.h>
#include<delepage.h>
#include<modifypage.h>
#include<outputall.h>
#include<namesort.h>
#include<birthsort.h>
#include<birthtotal.h>
#include<birthday.h>
#include<help.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
     Help * pageh ;
     addpage * page1;
     Serch * page2;
     Delepage * page3;
     Modifypage * page4;
     Outputall * page5;
     Namesort * page6;
     Birthsort * page7;
     Birthtotal *page8;
     Birthday *page9;
};
#endif // MAINWINDOW_H
