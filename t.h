#ifndef T_QOBJECT_H
#define T_QOBJECT_H

#include <QObject>

class T : public QObject
{
    Q_OBJECT
public:
    explicit T(QObject *parent = nullptr);

signals:
    //写自定义信号
    //返回值void，只需声明不需实现
    //可有参，可重载
    void H();
    void H(QString FoodName);//QString
    //警告：QPushButton::clicked 信号是一个无参数的信号，因此它不能直接连接到有参数的成员函数

};

#endif // T_QOBJECT_H
