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
public:
    explicit ship(QObject *parent = nullptr);
    ~ship();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void addTick();
public slots:
    void slotShip();

signals:
    void updateScene();
};

#endif // SHIP_H
