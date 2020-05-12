#ifndef RELATIVES_H
#define RELATIVES_H

#include<QObject>
#include<QString>
class relatives:public QObject
{
     Q_OBJECT
public:
    relatives();
private:
    QString name;
    QString called;
};

#endif // RELATIVES_H
