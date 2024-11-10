#include "ship.h"
#include <QDebug>

ship::ship(QObject *parent):QObject(parent), QGraphicsItem()
{
    cource = 0;
    ticks=0;
}

ship::~ship()
{

}

QRectF ship::boundingRect() const
{
    return QRectF(-20,-20,45,75);
}

void ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    emit updateScene();
    QPolygon polygon;
    polygon << QPoint(20,25) << QPoint(20,70) << QPoint(-20,70)
            << QPoint(-20,25) << QPoint(0,0);
    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);
    painter->setPen(Qt::DashLine);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void ship::addTick()
{
    ticks++;
}

void ship::slotShip()
{
    QPointF gCrd = this->pos();
    qDebug() << " tick ="<< ticks<< "\t coord: x=" << gCrd.x()
             << "\t y=" << gCrd.y() <<"\n";

    /*int k = 10;
   if( cource >= 0 && cource < 360){
        cource += k;
        setRotation(cource);
        setPos(mapToParent(0,-5));
    }
   else
   {
       k--;
       cource = 0;
   }*/

}
