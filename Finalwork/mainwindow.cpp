#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPaintDevice>
#include<QTimer>
#include<QAction>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionhelpwin,&QAction::triggered,this,[=](){
      pageh =new Help;
       pageh->show();
    });
    addpage *page1 = new addpage;
    connect(ui->add,&QPushButton::clicked,this,[=]()
    {
        QTimer::singleShot(300,this,[=](){
            this->hide();
            page1->show();
        });
    });
    connect(page1,&addpage::backtomain,this,[=](){
        QTimer::singleShot(300,page1,[=](){
             page1->hide();
             this->show();
        });
    });
     page2 = new Serch;
    connect(ui->search,&QPushButton::clicked,this,[=](){
        QTimer::singleShot(300,this,[=](){
            this->hide();
            page2->show();
        });
    });
    connect(page2,&Serch::backtomain,this,[=](){
        QTimer::singleShot(300,page1,[=](){
             page2->hide();
             this->show();
        });
    });
    page3 = new Delepage;
    connect(ui->delete_2,&QPushButton::clicked,this,[=](){
        QTimer::singleShot(300,this,[=](){
            this->hide();
            page3->show();
        });
    });
    connect(page3,&Delepage::backtomain,this,[=](){
        QTimer::singleShot(300,page1,[=](){
             page3->hide();
             this->show();
    });
});
     page4= new Modifypage;
    connect(ui->modify,&QPushButton::clicked,this,[=](){
        QTimer::singleShot(300,page1,[=](){
             this->hide();
             page4->show();
    });
    });
    connect(page4,&Modifypage::backtomain,this,[=](){
        QTimer::singleShot(300,page1,[=](){
             page4->hide();
             this->show();
    });
    });
    page5 = new Outputall;
   connect(ui->allout,&QPushButton::clicked,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            this->hide();
            page5->show();
   });
   });
   connect(page5,&Outputall::backtomain,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            page5->hide();
            this->show();
   });
   });
    page6 =new Namesort;
   connect(ui->namesort,&QPushButton::clicked,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            this->hide();
            page6->show();
   });
   });
   connect(page6,&Namesort::backtomain,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            page6->hide();
            this->show();
   });
   });
    page7 = new Birthsort;
   connect(ui->birthsort,&QPushButton::clicked,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            this->hide();
            page7->show();
   });
   });
   connect(page7,&Birthsort::backtomain,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            page7->hide();
            this->show();
   });
   });
   page8 = new Birthtotal;
   connect(ui->month,&QPushButton::clicked,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            this->hide();
            page8->show();
   });
   });
   connect(page8,&Birthtotal::backtomain,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            page8->hide();
            this->show();
   });
   });
   page9 = new Birthday;
   connect(ui->birthday,&QPushButton::clicked,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            this->hide();
            page9->show();
   });
   });
   connect(page9,&Birthday::backtomain,this,[=](){
       QTimer::singleShot(300,page1,[=](){
            page9->hide();
            this->show();
   });
   });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete page1;
    delete page2;
    delete page3;
    delete page4;
    delete page5;
    delete page6;
    delete page7;
    delete page8;
    delete page9;
    delete pageh;
}

