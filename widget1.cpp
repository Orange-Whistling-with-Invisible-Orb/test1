#include "widget1.h"
#include "ui_widget1.h"

Widget1::Widget1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget1)
{
    ui->setupUi(this);//ui界面特有代码

    //创建s和t对象
    this->s=new S();
    this->t=new T();


    //若t发出信号，s做处理（带参）
    void(T::*T_Signal2)(QString);//定义一个函数指针T_Signal，并指定参数表，消除二义性
    //函数有作用域，所有指针前要加T::
    T_Signal2=&T::H;

    void(S::*S_slot2)(QString);//定义一个函数指针T_slot，并指定参数表，消除二义性
    //函数有作用域，所有指针前要加S::
    S_slot2=&S::T;

    connect(t,T_Signal2,s,S_slot2);//因为无法区分是否带参，要先消除二义性！！

    //若t发出信号，s做处理（不带参）
    void(T::*T_Signal1)()=&T::H;
    void(S::*S_slot1)()=&S::T;
    connect(t,T_Signal1,s,S_slot1);//这里函数都不用加括号

    //先连接，再调用信号
    //调用触发信号按钮
    setWindowTitle("干饭时间");
    setFixedSize(600,400);

    QPushButton* eat1=new QPushButton("想吃。。。",this);
    eat1->resize(100,50);
    eat1->move(175,150);
    QPushButton* eat2=new QPushButton("想吃八级大狂风",this);
    eat2->resize(100,50);
    eat2->move(325,150);

    //连接信号和槽
    connect(eat1,&QPushButton::clicked,s,S_slot1);//记得消除二义性的槽函数地址
    disconnect(eat1,&QPushButton::clicked,s,S_slot1);//断开信号
    connect(eat1,&QPushButton::clicked,[=](){eat1->setText("想吃八级大狂风");(s->*S_slot1)();});

    //connect(eat2,&QPushButton::pressed,s,S_slot2);//为什么报错？
    connect(eat2, &QPushButton::clicked, [=]() {QString arg = "八级大狂风";(s->*S_slot2)(arg);});//lambda表达式
    //由于 S_slot1 是一个无参数的成员函数，你可以直接连接到 QPushButton::clicked 信号。对于带参数的成员函数 S_slot2，你需要使用 lambda 表达式来传递参数并调用函数。

    QPushButton* exit=new QPushButton("退出",this);
    exit->resize(100,50);
    exit->move(500,350);

    connect(exit,&QPushButton::clicked,[this](){Widget1::Timecoming1();this->close();});
    //lambda函数可以代替后两个
    //[]里要加“=”或者“this”才能找到this

}

//触发信号实现//写在构造函数外
void Widget1::Timecoming1()
{
    emit t->H();//调用信号格式//emit
}
void Widget1::Timecoming2()
    {
    emit t->H("八级大狂风");
}

Widget1::~Widget1()
{
    delete ui;
}

