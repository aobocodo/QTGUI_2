#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>
#include "dialog_mg.h"

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
    dialog_mg *mg_dialog;

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;

private slots:
    void initForm();
    //void buttonClick();

private slots:
    void menu_one_trigged(QAction* action);
    void menu_two_trigged(QAction* action);
    void on_btn_max_clicked();
    void on_btn_min_clicked();
    void on_btn_close_clicked();
};

#endif // WIDGET_H
