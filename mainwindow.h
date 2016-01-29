#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../qcustomplot.h"
#include <QMouseEvent>
extern double P;
extern double FFT [4096];
extern double cosin [4096];
extern double sinys [4096];
extern int countRows;
//extern double Second [4096];


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  

  void setupPlot();
  void setupSimpleItemDemo(QCustomPlot *customPlot);
  void mousePressEvent(QMouseEvent *event);




private slots:

   //void setupItemDemo(QCustomPlot *plot);

  void ReadXL();
  void horzScrollBarChanged(int value);
  void vertScrollBarChanged(int value);
  void xAxisChanged(QCPRange range);
  void yAxisChanged(QCPRange range);
  void bracketDataSlot();
  void ExamplSlot();
  void FFTAnalysis(QVector <double> &AVal, QVector <double> &FTvl, int Nvl, int Nft);
  //void FFTAnalysis(double AVal[], QVector <double> &FTvl, int Nvl, int Nft);

  void on_actionOpenFile_changed();
  void on_actionSpectr_changed();
  void on_actionStatis_changed();
  void on_actionCos_sin_changed();
  void on_actionConstilation_changed();


  // void on_h_Slider_sliderMoved(int position);

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::MainWindow *ui;
  QString demoName;
  QCPItemTracer *itemDemoPhaseTracer;
  QTimer dataTimer;
  QTimer time;

};

#endif // MAINWINDOW_H
