#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QTimer>
#include "ship.h"

class Widget : public QWidget
{
    Q_OBJECT

    QHBoxLayout *layout;
    QGraphicsView *grView;
    QGraphicsScene *scene;
    QTimer *gTimer;
    ship* shp;
    ship* warshp;
    QPointF stPnt;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
 public slots:
    void updateScene();
    void updateScene2();

};
#endif // WIDGET_H
