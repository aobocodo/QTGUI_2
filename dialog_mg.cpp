#include "dialog_mg.h"
#include "ui_dialog_mg.h"

dialog_mg::dialog_mg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_mg)
{
    ui->setupUi(this);
}

dialog_mg::~dialog_mg()
{
    delete ui;
}
