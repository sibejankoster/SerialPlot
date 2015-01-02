#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QVector>
#include <QtSerialPort/QSerialPort>
#include "../qcustomplot.h"
#include <QTimer>

// namespace Ui voor de hele class 'Widget'
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void addDataPoint(double point);
    int x_position;
    QVector<double> data_x, data_y;

public slots:
    void receive();

signals:
    //no need as QSerial implements own signal readyRead()
private:
    void init_line_plot();
    void init_port();
    QSerialPort *serial;
    QElapsedTimer timer;
    QCustomPlot *plot;
};

#endif // WIDGET_H
