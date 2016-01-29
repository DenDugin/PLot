#ifndef NEW_DIALOG_H
#define NEW_DIALOG_H
#include <QDialog>

namespace Ui {
class new_Dialog;
}

class new_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit new_Dialog(QWidget *parent = 0);
    ~new_Dialog();


private:
    Ui::new_Dialog *ui;
};

#endif // NEW_DIALOG_H
