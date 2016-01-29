#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ActiveQt/QAxObject>
#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxBase>
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include "dialog.h"
#include "con_dialog.h"
#include "new_dialog.h"
#include "QMessageBox"
#include <QFileDialog>
const double TwoPi = 6.283185307179586;
const int W = 500;


// f1b  10101001 100 bot,100 Hrc
int countRows;
QVector<double> xl(10000);
QVector<double>xlcos(3840);
double cosin [4096];
double sinys [4096];
//double xlcos [3840] = {};
QVector<double>xlsin(3840);
int z = 1;
int i;
double phase = 0;
QVector <double> First(4096);
QVector <double> Second(4096);
//double Second [4096] = {};
double FFT [4096] = {};
double P = 2;
int N = 4096;
int F = 4096;
QVector <double> Rez(4096);

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->h_Slider, SLOT(setValue(int)));
  connect(ui->h_Slider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));


  ui->spinBox->setRange(0, 10);
  ui->h_Slider->setRange(0, 10);




//  for (int i = 0; i <= 4095;i++)
//  {
//      First[i] = cos((TwoPi*i*2048/48000));
//      //qDebug()<<First[i];
//  };




//  int N = 4096;
//  int F = 4096;


//ReadXL();   // 1
//setupItemDemo(ui->plot); // Oscilograf  2
//ExamplSlot();

//FFTAnalysis(xlcos,Second,N,F);
      //setupSimpleItemDemo(ui->plot);
      //mousePressEvent(this);

     //setupPlot();    //

  ui->verticalScrollBar->setRange(-500, 500);

  connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));
  connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(vertScrollBarChanged(int)));
  connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
  connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));
  
  QVector<double> Ticks;  // вектор с шагом в 30 градусов
  int i = 0;
  while(i<=4000) {

      Ticks  << i ;
      i+=100;
  }
  ui->plot->xAxis->setAutoTicks(false); // выключаем автоматические отсчеты
  ui->plot->xAxis->setTickVector(Ticks);  // задаем созданный нами вектор

  ui->plot->xAxis->setRange(0, 500, Qt::AlignCenter);
  ui->plot->yAxis->setRange(-80, 0   , Qt::AlignCenter);
  ui->plot->replot();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow ::ReadXL()
{
    QAxWidget excel("Excel.Application");
    QAxObject * workbooks = excel.querySubObject("WorkBooks");
    workbooks->dynamicCall("Open (const QString&)",QString("D:\\Den\\MyGaf\\qcustomplot\\examples\\scrollbar-axis-range-control\\Exc.xls"));
    QAxObject *workbook = excel.querySubObject("ActiveWorkBook");
    QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
    QString ss;

    //QAxObject* worksheet = workbook->querySubObject("UsedRange");

    QAxObject* usedRange = worksheet->querySubObject("UsedRange");
    QAxObject* rows = usedRange->querySubObject("Rows");
    countRows = rows->property("Count").toInt();
    qDebug() << " Число строк " << countRows;

    for (int i = 1; i < countRows; i++)      // 3840
    {
     QAxObject* cell = worksheet->querySubObject("Cells(QVariant,QVariant)", i, 1);  // строка, столбец
     QVariant vv = cell->property("Value");

     ss = vv.toString() ;
         //bits[i-1] = ss.toDouble();
     xl[i] = ss.toDouble();
     //qDebug() << xl[i];
    }
    excel.dynamicCall("Quit (void)");

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   if (event->button() == Qt::LeftButton)
   {
   qDebug() << "  PUSH L";
   ui->plot->xAxis->setRange(0, 500, Qt::AlignLeft );
   }

   if ( event->button() == Qt::RightButton)
   {
   qDebug() << "  PUSH R";
   ui->plot->xAxis->setRange(0, 4000 );

   }

   if (event->button() == Qt::MidButton )
    {
     qDebug() << "  PUSH MIDDLE";
     ui->plot->setGeometry(400,250,1000,600);
     ui->plot->yAxis->setRange(-1.45, 1.65);
    }
}


void MainWindow::FFTAnalysis(QVector<double> &AVal, QVector<double> &FTvl, int Nvl, int Nft)

{
    int i, j, n, m, Mmax, Istp;
    // double Tmpr, Tmpi, Wtmp, Theta;


    double Tmpr,Theta,Wtmp,Tmpi;
    double Wpr, Wpi, Wr, Wi;
   //QVector <double> Tmvl;


    n = Nvl * 2;

    QVector <double>  Tmvl(n);

    for (i = 0; i < n; i+=2) {
       Tmvl[i] = 0;
       Tmvl[i+1] = AVal[i/2];
      }

    i = 1; j = 1;
      while (i < n) {
        if (j > i) {
          Tmpr = Tmvl[i]; Tmvl[i] = Tmvl[j]; Tmvl[j] = Tmpr;
          Tmpr = Tmvl[i+1]; Tmvl[i+1] = Tmvl[j+1]; Tmvl[j+1] = Tmpr;
        }
        i = i + 2; m = Nvl;
        while ((m >= 2) && (j > m)) {
          j = j - m; m = m >> 1;
        }
        j = j + m;
      }

      Mmax = 2;
       while (n > Mmax) {
         Theta = -TwoPi / Mmax; Wpi = sin(Theta);
         Wtmp = sin(Theta / 2); Wpr = Wtmp * Wtmp * 2;
         Istp = Mmax * 2; Wr = 1; Wi = 0; m = 1;

         while (m < Mmax) {
           i = m; m = m + 2; Tmpr = Wr; Tmpi = Wi;
           Wr = Wr - Tmpr * Wpr - Tmpi * Wpi;
           Wi = Wi + Tmpr * Wpi - Tmpi * Wpr;

           while (i < n) {
             j = i + Mmax;
             Tmpr = Wr * Tmvl[j] - Wi * Tmvl[j-1];
             Tmpi = Wi * Tmvl[j] + Wr * Tmvl[j-1];

             Tmvl[j] = Tmvl[i] - Tmpr; Tmvl[j-1] = Tmvl[i-1] - Tmpi;
             Tmvl[i] = Tmvl[i] + Tmpr; Tmvl[i-1] = Tmvl[i-1] + Tmpi;
             i = i + Istp;
           }
         }
         Mmax = Istp;

          }

          for (i = 0; i < Nft; i++) {

            j = i * 2;
            FTvl[Nft - i - 1] = sqrt(pow(Tmvl[j],2) + pow(Tmvl[j+1],2));
            //qDebug()<<" Ftvl "<<FTvl[i];
          }
          Tmvl.removeAll(n);
          double max = FTvl[0];
          for (int i = 0; i < FTvl.size();i++)
          {
              if (FTvl[i] > max) { max = FTvl[i];}
              //qDebug() << FTvl[i];
          }
          for (int i = 0; i < FTvl.size();i++)
          {
           FTvl[i] = 20*log10(FTvl[i]/max);
           FFT[i] = FTvl[i];
           //qDebug() << FFT[i];
          }

}


void MainWindow::on_actionOpenFile_changed()
{
    qDebug() << "  Open  ";
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Opne File"),
                "D://",
                "All files (*.*);;Text File (*.txt);;Excel file (*.xls);;Music file(*.mp3)"
                );
    QMessageBox::information(this,tr("File Name "),filename);


    QAxWidget excel("Excel.Application");
    QAxObject * workbooks = excel.querySubObject("WorkBooks");
    workbooks->dynamicCall("Open (const QString&)",filename);
    QAxObject *workbook = excel.querySubObject("ActiveWorkBook");
    QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
    QString ss;

    QAxObject* usedRange = worksheet->querySubObject("UsedRange");
    QAxObject* rows = usedRange->querySubObject("Rows");
    countRows = rows->property("Count").toInt();
    qDebug() << " Число строк " << countRows;

    for (int i = 1; i < countRows; i++)      // 3840
    {
     QAxObject* cell = worksheet->querySubObject("Cells(QVariant,QVariant)", i, 1);  // строка, столбец
     QVariant vv = cell->property("Value");

     ss = vv.toString() ;
         //bits[i-1] = ss.toDouble();
     xlcos[i] = ss.toDouble();
     //qDebug() << xl[i];
    }


    for (int i = 1; i < countRows; i++)      // 3840
    {
     QAxObject* cell = worksheet->querySubObject("Cells(QVariant,QVariant)", i, 2);  // строка, столбец
     QVariant vv = cell->property("Value");

     ss = vv.toString() ;
         //bits[i-1] = ss.toDouble();
     xlsin[i] = ss.toDouble();
     //qDebug() << xl[i];
    }
    excel.dynamicCall("Quit (void)");
    qDebug() << " Doone ";

    //connect(excel, SIGNAL(), this, SLOT(ExamplSlot()));

    connect(&time, SIGNAL(timeout()), this, SLOT(ExamplSlot()));

    time.start(0); // Interval 0 means to refresh as fast as possible

}


void MainWindow:: ExamplSlot()
{
    time.stop();

    qDebug() << "  ExamplSlot";

    setGeometry(400, 250, 542, 390);

    //ui->plot->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    //ui->plot->addGraph();

    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    QCPGraph *graph = ui->plot->addGraph();
    int n = countRows;//3840; //;500
    phase = 0;
    double k = 3;
    QVector<double> x(n), y(n),yy(n);
    for ( i=0; i<n; ++i)
    {
      x[i] =  i;// /(double)(n-1)*34 - 17;
      y[i] = (qCos(qAcos(xlcos[i]) + phase)); //cos(xlcos[i]+phase); //(cos(qAcos(First[i]) + phase)); // qExp(-x[i]*x[i]/20.0)*qSin(k*x[i]+phase);
      yy[i] = (qSin(qAsin(xlsin[i]) + phase));

      cosin[i] = y[i];
      sinys[i] = yy[i];
      Rez[i] = y[i]*qCos(TwoPi*W*i/48000) + yy[i]*qSin(TwoPi*W*i/48000);
    }

    graph->setData(x, Rez);
    graph->setPen(QPen(Qt::blue));
    graph->rescaleKeyAxis();
    ui->plot->yAxis->setRange(-1.45, 1.65);
    //ui->plot->xAxis->setRange(0, 1000, Qt::AlignCenter);
    ui->plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);


    // add the bracket at the top:
    QCPItemBracket *bracket = new QCPItemBracket(ui->plot);
    ui->plot->addItem(bracket);
    bracket->left->setCoords(-8, 1.1);
    bracket->right->setCoords(8, 1.1);
    bracket->setLength(13);

    QCPItemTracer *phaseTracer = new QCPItemTracer(ui->plot);
    ui->plot->addItem(phaseTracer);
    itemDemoPhaseTracer = phaseTracer; // so we can access it later in the bracketDataSlot for animation
    phaseTracer->setGraph(graph);
    phaseTracer->setGraphKey((M_PI*1.5-phase)/k);
    phaseTracer->setInterpolating(true);
    phaseTracer->setStyle(QCPItemTracer::tsCircle);
    phaseTracer->setPen(QPen(Qt::red));
    phaseTracer->setBrush(Qt::red);
    phaseTracer->setSize(7);


    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(bracketDataSlot()));

    dataTimer.start(0); // Interval 0 means to refresh as fast as possible

}



void MainWindow::bracketDataSlot()
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
  double secs = 0;
#else
   double secs = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
  // qDebug() << " sec" << secs;

#endif

  // update data to make phase move:
  int n = countRows;//; //3840;//500;
  double phase = secs*(ui->spinBox->value());  // cкорость обновл
  double k = 3;
  QVector<double> x(n), y(n),yy(n);
  for ( i=0; i<n; ++i)
  {
    x[i] = i ;// /(double)(n-1)*34 - 17;
    y[i] = qCos((qAcos(xlcos[i]) + phase)/z); //cos((xlcos[i]+phase)/z); //  // qExp(-x[i]*x[i]/20.0)*qSin(k*x[i]+phase);
    yy[i] = (qSin(qAsin(xlsin[i]) + phase)/z);
    Rez[i] = y[i]*qCos(TwoPi*W*i/48000) + yy[i]*qSin(TwoPi*W*i/48000);
  }
  ui->plot->graph()->setData(x, Rez);

  //itemDemoPhaseTracer->setGraphKey((8*M_PI+fmod(M_PI*1.5-phase, 6*M_PI))/k);

  ui->plot->replot();

  // calculate frames per second:
  double key = secs;
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    ui->statusBar->showMessage(
          QString("%1 FPS, Total Data points: %2")
          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
          .arg(ui->plot->graph(0)->data()->count())
          , 0);
    lastFpsKey = key;
    frameCount = 0;
  }
}

void MainWindow::on_actionSpectr_changed()
{
    qDebug() << "  Menu   ";

     if (Rez.size() < 4096 ) { Rez.resize(4096);}

    qDebug() << "   resize  ";
     FFTAnalysis(Rez,Second,N,F);

 qDebug() << " Ok  ";
    Dialog*dl = new Dialog(this);
    dl->show();

}

void MainWindow::on_actionStatis_changed()   // Statc
{
    qDebug() << "  Statistics  ";
    double maxx;
    QVector <double> yy(countRows+1);
    double mat,sum,sum2,disp,SKO,PARP;
    maxx = yy[0];
    for (int i = 0; i < countRows;i++)
    {
        yy[i] = Rez[i];
        //yy[i] = cos(xl[i]);
        if (yy[i] > maxx) { maxx = yy[i];}
    }
    for (int i = 0; i < countRows;i++)
    {
        sum  =  sum + yy[i];
    }
    mat = sum/yy.size();
    for (int i = 0; i < countRows;i++)
    {
        sum2  = sum2 + (yy[i] - mat)*(yy[i] - mat);
    }
    disp = sum2/yy.size();
    SKO = sqrt(disp);
    PARP = 20*log10(maxx/SKO);

    QMessageBox::information(this, tr("Статистика"),tr(" MAX = %1 \r\n Мат. ожидание = %2 \r\n Дисперсия = %3 \r\n СКО = %4 \r\n Пикфактор = %5").arg(maxx).arg(mat).arg(disp).arg(SKO).arg(PARP));
}

void MainWindow::on_actionCos_sin_changed()
{
    new_Dialog *d = new new_Dialog(this);
    d->show();
}


void MainWindow ::on_actionConstilation_changed()
{
    con_Dialog *c = new con_Dialog(this);
    c->show();
}


void MainWindow::horzScrollBarChanged(int value)
{
  if (qAbs(ui->plot->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
  {
    ui->plot->xAxis->setRange(value/100.0, ui->plot->xAxis->range().size(), Qt::AlignCenter);
    ui->plot->replot();
  }
}

void MainWindow::vertScrollBarChanged(int value)
{
  if (qAbs(ui->plot->yAxis->range().center()+value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
  {
    ui->plot->yAxis->setRange(-value/100.0, ui->plot->yAxis->range().size(), Qt::AlignCenter);
    ui->plot->replot();
  }
}

void MainWindow::xAxisChanged(QCPRange range)
{
  ui->horizontalScrollBar->setValue(qRound(range.center()*100.0)); // adjust position of scroll bar slider
  ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}

void MainWindow::yAxisChanged(QCPRange range)
{
  ui->verticalScrollBar->setValue(qRound(-range.center()*100.0)); // adjust position of scroll bar slider
  ui->verticalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}


void MainWindow::on_pushButton_clicked()
{
    z = z + 1;
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(bracketDataSlot()));
    qDebug() << "Button + ";

}

void MainWindow::on_pushButton_2_clicked()
{
    z = z - 1;
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(bracketDataSlot()));

}
