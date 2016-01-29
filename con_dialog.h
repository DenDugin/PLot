#ifndef CON_DIALOG_H
#define CON_DIALOG_H
#include <QTimer>
#include <QDialog>

namespace Ui {
class con_Dialog;
}

class con_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit con_Dialog(QWidget *parent = 0);
    ~con_Dialog();

private slots:

void PlaybackStep();
void circle();


private:
    Ui::con_Dialog *ui;
    QTimer dataTimer;


};

#endif // CON_DIALOG_H
