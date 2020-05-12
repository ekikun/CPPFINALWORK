#ifndef FRIENDS_H
#define FRIENDS_H

#include<QObject>
#include<QString>
class friends:public QObject
{
    Q_OBJECT
public:
    friends();
private:
    QString name;
    QString known_place;
};

#endif // FRIENDS_H
