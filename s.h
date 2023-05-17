#ifndef S_H
#define S_H

#include <QObject>//直接继承QObject

class S : public QObject
{
    Q_OBJECT
public:
    explicit S(QObject *parent = nullptr);

public slots://也可以写到pulic下
    //返回void,需要声明，需要实现
    //可有参，可重载
    void T();
    void T(QString FoddName);

signals:

};

#endif // S_H
