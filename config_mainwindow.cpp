#include "config_mainwindow.h"
#include "ui_config_mainwindow.h"


config_mainwindow::config_mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::config_mainwindow)
{
    ui->setupUi(this);
}

config_mainwindow::~config_mainwindow()
{
    delete ui;
}

void config_mainwindow::closeEvent(QCloseEvent *)
{
    emit close_cg();
}
