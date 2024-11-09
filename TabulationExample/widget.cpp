#include "widget.h"
#include <QValueAxis>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    {
        vPanelControls = new QVBoxLayout();
        hPanel = new QHBoxLayout();
        lblBgn = new QLabel("Начало табулирования");
        vPanelControls->addWidget(lblBgn);
        txtBoxBgn = new QLineEdit();
        vPanelControls->addWidget(txtBoxBgn);
        lblIter = new QLabel("Шаг табулирования");
        vPanelControls->addWidget(lblIter);
        txtBoxIter = new QLineEdit();
        vPanelControls->addWidget(txtBoxIter);
        lblFnh = new QLabel("Конец табулирования");
        vPanelControls->addWidget(lblFnh);
        txtBoxFnh = new QLineEdit();
        vPanelControls->addWidget(txtBoxFnh);
        buttonTabulate = new QPushButton();
        buttonTabulate->setText("Табулировать");
        vPanelControls->addWidget(buttonTabulate);
        buttonGraph = new QPushButton();
        buttonGraph->setText("График");
        vPanelControls->addWidget(buttonGraph);
        buttonQuit = new QPushButton();
        buttonQuit->setText("Выход");
        vPanelControls->addWidget(buttonQuit);
        hPanel->addLayout(vPanelControls);
        //**********************************
        vPanelList = new QVBoxLayout();
        listBox = new QListWidget();
        listBox->setMinimumWidth(200);
        vPanelList->addWidget(listBox);
        hPanel->addLayout(vPanelList);
        //**********************************
        vPanelGraph = new QVBoxLayout();
        graphView = new QtCharts::QChartView();
        graphView->setMinimumWidth(600);
        vPanelGraph->addWidget(graphView);
        graphView->setVisible(false);
        hPanel->addLayout(vPanelGraph);
        //**********************************
        setLayout(hPanel);
        series = new QtCharts::QLineSeries();
    }
    connect(buttonTabulate,&QPushButton::clicked,this,&Widget::clickButtonTabulate);
    connect(buttonGraph,&QPushButton::clicked,this,&Widget::clickButtonGraph);
    connect(buttonQuit,&QPushButton::clicked,this,&Widget::clickButtonQuit);
}

Widget::~Widget()
{
}

void Widget::clickButtonTabulate()
{
    double sVal= txtBoxBgn->text().toDouble();
    double cVal = txtBoxIter->text().toDouble();
    double fVal = txtBoxFnh->text().toDouble();
    listBox->addItem(QString("X \t Y=2*x+3"));
    double x = sVal;
    do
    {
        double y = 2*x+3;
        *series << QPointF(x,y);
        QString note = QString::number(x)+"\t"+ QString::number(y);
        listBox->addItem(note);
        x+=cVal;
    }while(x < fVal);
}

void Widget::clickButtonQuit()
{
    this->close();
}

void Widget::clickButtonGraph()
{
    QtCharts::QChart *graph= new QtCharts::QChart();
    graph->addSeries(series);
    graph->legend()->hide();
    QtCharts::QValueAxis *xAxis = new QtCharts::QValueAxis();
    xAxis->setTitleText("x");
    xAxis->setTickCount(1);
    graph->addAxis(xAxis,Qt::AlignBottom);
    series->attachAxis(xAxis);
    QtCharts::QValueAxis *yAxis = new QtCharts::QValueAxis();
    yAxis->setTitleText("y");
    yAxis->setTickCount(1);
    graph->addAxis(yAxis,Qt::AlignLeft);
    series->attachAxis(yAxis);
    graphView->setChart(graph);
    graphView->setVisible(true);
}
