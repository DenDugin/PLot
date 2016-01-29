#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QMouseEvent>
//#include  "mainwindow.cpp"
#include "../../qcustomplot.h"
#include <QDebug>
#include <QVector>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

  QVector<double> Ticks;  // вектор с шагом в 30 градусов
  int i = -24000;
  while(i<=24000) {

      Ticks  << i ;
      i+=1000;

  }
  ui->plot->xAxis->setAutoTicks(false); // выключаем автоматические отсчеты
  ui->plot->xAxis->setTickVector(Ticks);  // задаем созданный нами вектор
  ui->plot->yAxis->setLabel("дБ");
  ui->plot->xAxis->setLabel("Гц");


  ui->plot->xAxis->setRange(-3000,3000, Qt::AlignCenter);
  ui->plot->yAxis->setRange(-80, 0   , Qt::AlignCenter);
  ui->plot->replot();

 ui->plot->addGraph();
 ui->plot->graph(0)->setPen(QPen(Qt::blue));
 ui->plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
 //ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
 //ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

 QVector <double> x(4096),y(4096);


 for(int i=0; i < 4096; i++)
 {
  x[i] = -24000+48000/4096*i;
  y[i] = FFT[i];
  //qDebug()<<x[i];
  //qDebug()<<y[i];
 }


 ui->plot->graph(0)->setData(x, y);
 ui->plot->axisRect()->setupFullAxesBox(true);
 ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::Width(int Gran, QVector<double> &yy,int i)   // Gran = -50
{
     double db50_1,db50_2;
    for (int i=0; i <2048; i++)
    {
        if (yy[i]> Gran && yy[i-1] < Gran)  { db50_1 = i ;
                            //qDebug()<<"db_50"<<db50_1;
                             break;}
    }

    for (int i=4096; i > 2048; i--)
    {
      if (yy[i]< Gran && yy[i-1] > Gran)  { db50_2 = i ;
                                                break;  }
    }
  ui->plot->addGraph();
  ui->plot->graph(i)->setPen(QPen(Qt::blue,5));
  //ui->plot->graph(i)->setBrush(QBrush(QColor(0, 0, 255, 20)));
  ui->plot->graph(i)->setLineStyle(QCPGraph::lsNone);
  ui->plot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

  QVector <double> x_50(db50_2 - db50_1),y_50(db50_2 - db50_1);
    for ( int i = 0; i <(db50_2 - db50_1); i++ )
    {
    x_50[i] =1500 -24000 + 48000/4096*(db50_1 + i);
    y_50[i] =  Gran;
    }
    ui->plot->graph(i)->setData(x_50, y_50);


    //ui->plot->plotLayout()->insertRow(0);
    //ui->plot->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui->plot, tr("Ширина при %1 Гц = %2 ").arg(Gran).arg(48000/4096*(db50_2 - db50_1))));



    ui->plot->legend->setVisible(true);
    ui->plot->legend->setFont(QFont("Helvetica",9));
    ui->plot->graph(i)->setName(tr("Ширина при %1 Дб = %2 ").arg(Gran).arg(48000/4096*(db50_2 - db50_1)));
    ui->plot->legend->removeItem(ui->plot->legend->itemCount()-4);


}


void Dialog::on_pushButton_clicked()
{

    ui->plot->clearGraphs();
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::red));
    ui->plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    QVector <double> x1(4096), y1(4096);

       for (int i=0; i <2048; i++)
       {

           x1[i] =1500 -24000+48000/4096*i;
           y1[i] = FFT[ 2048 + i ];

       }

       for (int i=2048; i <4096; i++)
       {

           x1[i] =1500 -24000+48000/4096*i;
           y1[i] = FFT[i-2048];

       }

       ui->plot->graph(0)->setData(x1, y1);
       ui->plot->replot();



       Width(-50,y1,1);

       Width(-40,y1,2);

       Width(-30,y1,3);





}
