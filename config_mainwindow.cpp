#include "config_mainwindow.h"
#include "ui_config_mainwindow.h"
#include <array>
#include <QComboBox>
#include <QDebug>



config_mainwindow::config_mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::config_mainwindow)
{
    ui->setupUi(this);
    ui->menubar->show();
    for(int i=0; i<3;i++){
        QComboBox *combox_state = new QComboBox();
        combox_state->addItem("工作");
        combox_state->addItem("待机");
        ui->tableWidget->setCellWidget(i,1,(QWidget*)combox_state);
    }
    for(int i=0; i<3;i++){
        QComboBox *combox_point = new QComboBox();
        combox_point->addItem("2.66");
        combox_point->addItem("2.36");
        ui->tableWidget->setCellWidget(i,2,(QWidget*)combox_point);
    }
    for(int i=0; i<3;i++){
        QComboBox *combox_bw = new QComboBox();
        combox_bw->addItem("5.00");
        combox_bw->addItem("10.0");
        combox_bw->addItem("20.0");
        ui->tableWidget->setCellWidget(i,3,(QWidget*)combox_bw);
    }
    for(int i=0; i<3;i++){
        QComboBox *combox_tx = new QComboBox();
        combox_tx->addItem("95");
        combox_tx->addItem("105");
        combox_tx->addItem("115");
        ui->tableWidget->setCellWidget(i,4,(QWidget*)combox_tx);
    }
    for(int i=0; i<3;i++){
        QComboBox *combox_rx = new QComboBox();
        combox_rx->addItem("90");
        combox_rx->addItem("100");
        combox_rx->addItem("110");
        ui->tableWidget->setCellWidget(i,5,(QWidget*)combox_rx);
    }
    for(int i=0; i<3;i++){
        QComboBox *combox_pw = new QComboBox();
        combox_pw->addItem("20");
        combox_pw->addItem("30");
        combox_pw->addItem("40");
        ui->tableWidget->setCellWidget(i,6,(QWidget*)combox_pw);
    }
    ui->tableWidget->setAlternatingRowColors(true);
    //ui->tableWidget->horizontalHeader()->setObjectName("hHeader");
    ui->tableWidget->verticalHeader()->setObjectName("vHeader");

    ui->pushButton->setProperty("btn","white");
}

config_mainwindow::~config_mainwindow()
{
    delete ui;
}

void config_mainwindow::closeEvent(QCloseEvent *)
{
    emit close_cg();
}

void config_mainwindow::on_pushButton_clicked()
{
//    QTableWidgetItem *itab = ui->tableWidget->item(0,0);
//    QString itabtext = itab->text();
//    qDebug()<<"item"<<itabtext;

//    QComboBox* combo=(QComboBox*)ui->tableWidget->cellWidget(0,2);
//    combo->currentIndex();
//    qDebug()<<"item"<<combo->currentText();



//    for(int i=0; i<3; i++){
//        std::array<std::string, 7> data;
//        QTableWidgetItem *itab = ui->tableWidget->item(i,0);
//        QString itabtext = itab->text();
//        data[0] = itabtext.toUtf8().constData();
//        for(int j=1; j<7; j++){
//            QComboBox* combo=(QComboBox*)ui->tableWidget->cellWidget(i,j);
//            data[j]=combo->currentText().toUtf8().constData();
//        }
//        for(int m=0; m<7; m++){
//            qDebug()<<"item is "<<QString::fromStdString(data[m]);
//        }
//    }
    QString head="<font color=red>手动配置参数：</font>";
    emit emit_to_main(head);
    print_to_main();

}

void config_mainwindow::print_to_main()
{
    QString head="ID                      状态             频点              带宽        发射增益    接收增益    功率";
    emit emit_to_main(head);
    for(int i=0; i<3; i++){
        QString data;
        QTableWidgetItem *itab = ui->tableWidget->item(i,0);
        QString itabtext = itab->text();
        data = itabtext+":  ";
        for(int j=1; j<7; j++){
            QComboBox* combo=(QComboBox*)ui->tableWidget->cellWidget(i,j);
            data=data+"            "+combo->currentText()+"  ";
        }
        emit emit_to_main(data);
    }
}


void config_mainwindow::on_cg_btn_one_clicked()
{
    QComboBox* combo_value=(QComboBox*)ui->tableWidget->cellWidget(1,1);
    combo_value->setCurrentIndex(combo_value->findText("待机"));
    QComboBox* combo_value_1=(QComboBox*)ui->tableWidget->cellWidget(1,3);
    combo_value_1->setCurrentIndex(combo_value_1->findText("10.0"));
    QString head="<font color=red>[覆盖最优]策略参数：</font>";
    emit emit_to_main(head);
    print_to_main();
}

void config_mainwindow::on_cg_btn_two_clicked()
{
    QString head="<font color=red>[性能最优]策略参数：</font>";
    emit emit_to_main(head);
    print_to_main();
}

void config_mainwindow::on_cg_btn_three_clicked()
{
    QString head="<font color=red>[吞吐量最优]策略参数：</font>";
    emit emit_to_main(head);
    print_to_main();
}
