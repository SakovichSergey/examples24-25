#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QSize wSz(1280,720);
    this->resize(wSz);
    this->setFixedSize(wSz);

    grView = new QGraphicsView();
    layout = new QHBoxLayout();
    layout->addWidget(grView);
    scene = new QGraphicsScene();
    grView->setScene(scene);
    grView->setRenderHint(QPainter::Antialiasing);
    grView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    grView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(-360,-360,700,700);
    this->setLayout(layout);
    shp = new ship();
    warshp = new ship();
    scene->addItem(shp);
    shp->setPos(-360,0);
    stPnt = shp->pos();
    gTimer = new QTimer();
    gTimer->setInterval(100);
    connect(gTimer, &QTimer::timeout, shp, &ship::slotShip);
    connect(shp, &ship::updateScene, this, &Widget::updateScene);
    connect(warshp, &ship::updateScene, this, &Widget::updateScene2);
    gTimer->start(100);
}

Widget::~Widget()
{
}

void Widget::updateScene()
{
    QPointF tmpPoint = shp->scenePos();
    shp->addTick();
    shp->setVelocity(5);
    shp->setCource(0);
    scene->addLine(QLineF(stPnt, tmpPoint), QPen(Qt::black));
    stPnt=tmpPoint;
    scene->update();
}

void Widget::updateScene2()
{
    QPointF tmpPoint = shp->scenePos();
    shp->addTick();
    shp->setVelocity(10);
    shp->setPosition(QPointF(0,0));
    //shp->setCource(3.14);
    scene->addLine(QLineF(stPnt, tmpPoint), QPen(Qt::black));
    stPnt=tmpPoint;
    scene->update();
}

