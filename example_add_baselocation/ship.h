#ifndef SHIP_H
#define SHIP_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class ship : public QObject, public QGraphicsItem
{
    Q_OBJECT
    qreal cource;
    qint64 ticks;
    QPointF pose;
    qint8 velocity;
public:
    explicit ship(QObject *parent = nullptr);
    ~ship();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void addTick();
    void setPosition(QPointF pnt);
    void setCource(qreal angle);
    void setVelocity(qint8 vel);
public slots:
    void slotShip();

signals:
    void updateScene();
};

#endif // SHIP_H
