#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>      //Базовая часть класса widget
#include <QVBoxLayout> //Вертикальная панель
#include <QHBoxLayout> //Горизонтальная панель
#include <QLabel>       //Метка или подпись
#include <QLineEdit>    //Тестовое поле
#include <QPushButton>  //Кнопка
#include <QListWidget>  //Список
#include <QChart>       //График
#include <QLineSeries> //Линия графика
#include <QChartView>   //Визуализатор графика
class Widget : public QWidget
{
    Q_OBJECT
    QVBoxLayout * vPanelControls;
    QVBoxLayout * vPanelList;
    QVBoxLayout * vPanelGraph;
    QHBoxLayout * hPanel;
    QLabel * lblBgn;
    QLabel * lblIter;
    QLabel * lblFnh;
    QPushButton * buttonTabulate;
    QPushButton * buttonGraph;
    QPushButton * buttonQuit;
    QLineEdit * txtBoxBgn;
    QLineEdit * txtBoxIter;
    QLineEdit * txtBoxFnh;
    QListWidget *listBox;
    QtCharts::QChartView *graphView;
    QtCharts::QLineSeries *series;
    QString *res;
    int counter{0};
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void clickButtonTabulate();
    void clickButtonGraph();
    void clickButtonQuit();
};
#endif // WIDGET_H
