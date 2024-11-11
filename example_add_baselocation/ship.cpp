#include "ship.h"
#include <QDebug>
#include <QtMath>

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

void ship::setPosition(QPointF pnt)
{
    pose = pnt;
}

void ship::setCource(qreal angle)
{
    cource = angle;
}

void ship::setVelocity(qint8 vel)
{
    velocity = vel;
}

void ship::slotShip()
{
    pose =  this->pos();
    qDebug() << " tick ="<< ticks<< "\t coord: x=" << pose.x()
             << "\t y=" << pose.y() <<"\n";

    /*pose.setX((velocity/10)*cos(cource));
    pose.setY((velocity/10)*sin(cource));
    setRotation(359);
    setPos(mapToParent(pose));*/
   if( cource >= 0 && cource < 360){
        cource += 10;
        setRotation(cource);
        //setPos(mapToParent(0,5));
    }
   else
   {
       cource = 0;
   }

}
