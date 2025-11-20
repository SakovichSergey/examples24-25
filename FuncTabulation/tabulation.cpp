#include "tabulation.h"
#include <QCoreApplication>
tabulation::tabulation(QObject *parent)
    : QObject{parent}
{}

void tabulation::button1_Clicked(QString str)
{
    auto strList = str.split(" ");
    double start = strList.at(0).toDouble();
    double step = strList.at(1).toDouble();
    double fin = strList.at(2).toDouble();
    auto it=start;

    strCalc="";
    while(it<=fin)
    {
        strCalc +="x="+QString::number(it)+
                   " y="+QString::number(3*it+2)+"\n";

        it+=step;
    }
    emit tabDate(strCalc);
}

void tabulation::button3_Clicked()
{
    QCoreApplication::quit();
}
