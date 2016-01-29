#include "con_dialog.h"
#include "ui_con_dialog.h"
#include "mainwindow.h"

QVector <double>A1(4000),F1(4000);
int TimeElapsed = 0;
QVector<double> x2, y2;
QVector<double> xx(3000), yy(3000);
QTimer* playBackTimer = new QTimer;


con_Dialog::con_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::con_Dialog)
{
    ui->setupUi(this);

//    setGeometry(400,150, 600, 600);
//    ui->plot->xAxis->setRange(-1,1, Qt::AlignCenter);
//    ui->plot->yAxis->setRange(-1,1, Qt::AlignCenter);
//    ui->plot->replot();

//    ui->plot->addGraph();
//    ui->plot->graph(0)->setPen(QPen(Qt::blue));
//    //ui->plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
//    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
//    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

//{
//    QVector <double> x(22),y(100),r(4096);

//    double j = 0.1;
//    for(int i=0; i < 21; i++)
//    {
//        x[i] = j - 1.1;
//         qDebug()<<i<<x[i];
//         j = j + 0.1;
//    }

//    for(int i=0; i < 21; i++)
//    {
//        y[i] = qSqrt(1 - x[i]*x[i]);

//        if (i == 20) { y[20] = 0 ;}
//      // qDebug()<<i<<y[i];
////        double phi = ((i+30)/(double)(100))*M_PI;
////        x[i] = qSqrt(phi)*qCos(phi);
////        y[i] = qSqrt(phi)*qSin(phi);

//    }
//    x.resize(42);
//    for(int i=0; i < 21; i++)
//    {
//        y[21+i] = - qSqrt(1 - x[i]*x[i]);
////        double phi = ((i+30)/(double)(100))*M_PI;
////        x[i] = qSqrt(phi)*qCos(phi);
////        y[i] = qSqrt(phi)*qSin(phi);
//       x[21+i] = x[i];
//    }
//    //ui->plot->graph(0)->setData(x, y);
//    ui->plot->axisRect()->setupFullAxesBox(true);
//    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

//}


//    ui->plot->addGraph();
//    ui->plot->graph(1)->setPen(QPen(Qt::red));
//    ui->plot->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    qDebug()<<countRows;

   // QVector <double> xx(countRows),yy(countRows);
    QVector <double> Am(countRows),Faze(countRows);

    for (int i=0; i < 3000; i++)
   {
         Am[i] = qSqrt(pow(cosin[i],2)+pow(sinys[i],2));
         Faze[i] = -qAtan(sinys[i]/cosin[i]);
          //qDebug()<<"AM"<<Am[i];
           //qDebug()<<"Faz"<<Faze[i];

       if ( cosin[i] < 0 )   { Faze[i] = Faze[i] + M_PI;}

      // A1[i] = Am[i];
      // F1[i] = Faze[i];

   }





   // connect(&dataTimer, SIGNAL(timeout()), this, SLOT(circle()));

   // dataTimer.start(0); // Interval 0 means to refresh as fast as possible



    for(int i = 0; i < 3000; i++)
    {
      xx[i] = Am[i]*qCos(Faze[i]);
      yy[i] = Am[i]*qSin(Faze[i]);

    }

    ui->plot->addGraph();
    ui->plot->graph(0)->setData(xx, yy);
//    ui->plot->addGraph();
//    ui->plot->graph()->setData(xx,yy);
    ui->plot->xAxis->setRange(0,10);
    ui->plot->yAxis->setRange(0,10);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->plot->replot();

  //создание экземпляра таймера

    connect(playBackTimer, SIGNAL(timeout()), this, SLOT(PlaybackStep())); //привязка события к функции PlaybackStep()

    playBackTimer->start(1);


}


void con_Dialog::PlaybackStep()
{

    TimeElapsed+=1; // 50 - частота срабатывания таймера (в мс)
    qDebug()<<"TimeElaps"<<TimeElapsed;
    qDebug()<<"yy"<<yy[0];
        for(int i = 0; i < xx.size(); i++)
        {
                if(TimeElapsed >= xx[i])
                {
                    qDebug()<<"Yes";
                    x2.push_back(xx[i]);
                    y2.push_back(yy[i]);
                    xx.pop_front();
                    yy.pop_front();
                    i = 0; // если во временном промежутке несколько подходящих "точек", то после pop_front() мы можем
                    // упустить одну. i = 0 запускает заново цикл, чтобы ничего "не потерять"
                }


                ui->plot->graph(0)->setData(x2, y2);

          }

        if (xx.size() == 0) playBackTimer->stop();

        ui->plot->replot();



}








void con_Dialog ::circle()
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
  double secs = 0;
#else
   double secs = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
  // qDebug() << " sec" << secs;

#endif

    QVector <double> xx(countRows),yy(countRows);


    for (int i=0; i < 3000; ++i)
   {

        xx[i] = A1[i]*qCos(F1[i]);
        yy[i] = A1[i]*qSin(F1[i]);


   }

    //dataTimer.stop();

    ui->plot->graph(1)->setData(xx, yy);

    ui->plot->replot();

}



con_Dialog::~con_Dialog()
{
    delete ui;
}
