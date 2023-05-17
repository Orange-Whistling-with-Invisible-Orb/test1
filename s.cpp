#include "s.h"
#include<qdebug.h>

S::S(QObject *parent)
    : QObject{parent}
{

}

void S::T()
{
    qDebug()<<"请你吃";
}

void S::T(QString FoddName)
{
    qDebug()<<"请你吃："<<FoddName.toUtf8().data();
    //.toUtf8()把QString转成QByteArray类型
    //.data()把QByteArray转成*char类型
    //查表QByteArray
}
