#include "happybirthday.h"
#include "ui_happybirthday.h"

Happybirthday::Happybirthday(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Happybirthday)
{
    ui->setupUi(this);
}

Happybirthday::~Happybirthday()
{
    delete ui;
}
