#include "new_dialog.h"
#include "ui_new_dialog.h"
#include "mainwindow.h"
#include "../../qcustomplot.h"
#include "QLabel"


new_Dialog::new_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_Dialog)
{
    ui->setupUi(this);
    QVector<double> Ticks;  // вектор с шагом в 30 градусов
    int i = 0;
    while(i<=4000) {

        Ticks  << i ;
        i+=100;

    }
    ui->plot->xAxis->setAutoTicks(false); // выключаем автоматические отсчеты
    ui->plot->xAxis->setTickVector(Ticks);  // задаем созданный нами вектор

    ui->plot_2->xAxis->setAutoTicks(false); // выключаем автоматические отсчеты
    ui->plot_2->xAxis->setTickVector(Ticks);  // задаем созданный нами вектор


    ui->plot->xAxis->setRange(0, 500, Qt::AlignCenter);
    ui->plot->yAxis->setRange(-80, 0   , Qt::AlignCenter);
    ui->plot->replot();

    ui->plot_2->xAxis->setRange(0, 500, Qt::AlignCenter);
    ui->plot_2->yAxis->setRange(-80, 0   , Qt::AlignCenter);
    ui->plot_2->replot();

    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->plot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    QCPGraph *graph = ui->plot->addGraph();
    QCPGraph *graph1 = ui->plot_2->addGraph();

    int n = 3830;
    QVector<double> x(n), y(n);
    for ( i=0; i<n; ++i)
    {
      x[i] = i;// /(double)(n-1)*34 - 17;
      y[i] = cosin[i];//qCos(cosin[i]); //(cos(qAcos(First[i]) + phase)); // qExp(-x[i]*x[i]/20.0)*qSin(k*x[i]+phase);
    }

    graph->setData(x, y);
    graph->setPen(QPen(Qt::blue));
    graph->rescaleKeyAxis();
    ui->plot->yAxis->setRange(-1.45, 1.65);
    ui->plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);

    QCPItemText *textLabel = new QCPItemText(ui->plot);
    ui->plot->addItem(textLabel);
    textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
    textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel->position->setCoords(0.5, 0);
    textLabel->setText("Re");
    textLabel->setFont(QFont(font().family(), 16));
    textLabel->setPen(QPen(Qt::black));





   QVector <double> xx(n),yy(n);

   for ( i=0; i<n; ++i)
   {
     xx[i] = i;// /(double)(n-1)*34 - 17;
     yy[i] = sinys[i];//qCos(cosin[i]); //(cos(qAcos(First[i]) + phase)); // qExp(-x[i]*x[i]/20.0)*qSin(k*x[i]+phase);
   }

   graph1->setData(xx, yy);
   graph1->setPen(QPen(Qt::blue));
   graph1->rescaleKeyAxis();
   ui->plot_2->yAxis->setRange(-1.45, 1.65);
   ui->plot_2->xAxis->grid()->setZeroLinePen(Qt::NoPen);

   QCPItemText *textLabel2 = new QCPItemText(ui->plot_2);
   ui->plot_2->addItem(textLabel2);
   textLabel2->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
   textLabel2->position->setType(QCPItemPosition::ptAxisRectRatio);
   textLabel2->position->setCoords(0.5, 0);
   textLabel2->setText("Im");
   textLabel2->setFont(QFont(font().family(), 16));
   textLabel2->setPen(QPen(Qt::black));




}

new_Dialog::~new_Dialog()
{
    delete ui;
}
