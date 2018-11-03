#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>
#include "config_mainwindow.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QMenu *menu_one;
    QMenu *menu_two;
    config_mainwindow *cg_frame;

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;

private slots:
    void initForm();
    void menu_one_trigged(QAction* action);
    void cg_close();
    void menu_two_trigged(QAction* action);
    void on_btn_max_clicked();
    void on_btn_min_clicked();
    void on_btn_close_clicked();
};

#endif // WIDGET_H
