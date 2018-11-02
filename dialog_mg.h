#ifndef DIALOG_MG_H
#define DIALOG_MG_H

#include <QDialog>

namespace Ui {
class dialog_mg;
}

class dialog_mg : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_mg(QWidget *parent = 0);
    ~dialog_mg();

private:
    Ui::dialog_mg *ui;
};

#endif // DIALOG_MG_H
