#include "ship.h"
#include <QDebug>
#include <QtMath>

ship::ship(QObject *parent):QObject(parent), QGraphicsItem()
{
    cource = 0;
    setRotation(cource);
    ticks=0;
    angle = 0;
    setTransformOriginPoint(0,35);
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

void ship::setVelocity(qreal vel)
{
    velocity = vel;
}

void ship::slotShip()
{
    pose =  this->pos();
    qDebug() << " tick ="<< ticks<< "\t coord: x=" << pose.x()
             << "\t y=" << pose.y() << "\t cource =" << cource <<"\n";

    auto vel = 0.0000001;
    pose.setX(vel*cos(cource)-vel*sin(cource));
    pose.setY(vel*sin(cource)+vel*cos(cource));


    angle += 1;
    setRotation(angle);
    setPos(mapToParent(pose));
}
