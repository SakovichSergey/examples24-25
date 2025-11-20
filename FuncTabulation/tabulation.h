#ifndef TABULATION_H
#define TABULATION_H

#include <QObject>

class tabulation : public QObject
{
    Q_OBJECT
public:
    explicit tabulation(QObject *parent = nullptr);

    QString strCalc;

signals:
    void tabDate(QString);
public slots:
    Q_INVOKABLE void button1_Clicked(QString str);
    void button3_Clicked();
};

#endif // TABULATION_H
