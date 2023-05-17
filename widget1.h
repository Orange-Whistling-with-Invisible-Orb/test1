#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>
#include"s.h"
#include"t.h"
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget1; }
QT_END_NAMESPACE

class Widget1 : public QWidget
{
    Q_OBJECT

public:
    Widget1(QWidget *parent = nullptr);
    ~Widget1();

private:
    Ui::Widget1 *ui;

    //创建s和t对象
    T* t;
    S* s;
    //若t发出信号，s做处理
    void Timecoming1();
    void Timecoming2();
};
#endif // WIDGET1_H
