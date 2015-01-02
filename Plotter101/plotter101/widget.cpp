#include "widget.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFrame>
#include <QRect>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    QVector<double> data_x(101), data_y(101);
    timer.start();
    init_port();
    init_line_plot();

    QHBoxLayout *layout = new QHBoxLayout (this);
    layout->setContentsMargins(5,5,5,5);
    layout->addWidget(plot);

    x_position = 0;

    connect(serial, SIGNAL(readyRead()), this, SLOT(receive()));

}

Widget::~Widget()
{
    serial->close();
}

void Widget::init_port()
{
    QTextStream out(stdout);
    QString portname = "COM4";
    serial = new QSerialPort(portname);
    if (!serial->open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this, "port error", "cannot open port");
    }

    serial->setBaudRate(BAUD_115200);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    out <<"port opened"<<endl<<endl;
}

void Widget::init_line_plot()
{
    plot = new QCustomPlot (this);

    plot->addGraph();
    plot->setMinimumSize(500,250);
    plot->xAxis->setLabel("t [s]");
    plot->yAxis->setLabel("V [mV]");

//    plot->graph(0)->setLineWidth(1);
//    plot->graph(0)->setFrameStyle(QFrame::Box | QFrame::Plain);
}

void Widget::receive()
{
    // recieves data as ASCII string
    int datalength = 1000;
    char data [1000];
    int bytesRead = serial->readLine(data, datalength);
    data[bytesRead]='\0';


    QTextStream out(stdout);
    out << data << endl;
    addDataPoint(atof(data));
}

void Widget::addDataPoint(double datapoint)
{
    if (x_position>150)data_x.pop_front();
    double ms = timer.elapsed();
    data_x.push_back((double)ms/1000);
    x_position++;
    if (x_position>150) data_y.pop_front();
    data_y.push_back(datapoint);
    plot->graph(0)->setData(data_x,data_y);
    plot->graph(0)->rescaleAxes();
    plot->replot();
}
