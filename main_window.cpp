#include "main_window.h"
#include "ui_main_window.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pbtn_sort, SIGNAL(pressed()), this, SLOT(pbtnSortPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbtn_sort_clicked()
{
    int original_arr[4];
    original_arr[0] = ui->lineEdit_o1->text().toInt();
    original_arr[1] = ui->lineEdit_o2->text().toInt();
    original_arr[2] = ui->lineEdit_o3->text().toInt();
    original_arr[3] = ui->lineEdit_o4->text().toInt();

    for (int i = 4; i> 0; i--) {
        for (int j = 1; j < i; j++) {
            int a = original_arr[j - 1];
            int b = original_arr[j];
            if (a > b) {
                original_arr[j - 1] = b;
                original_arr[j] = a;
            }
        }
    }

    ui->lineEdit_s1->setText(QString::number(original_arr[0]));
    ui->lineEdit_s2->setText(QString::number(original_arr[1]));
    ui->lineEdit_s3->setText(QString::number(original_arr[2]));
    ui->lineEdit_s4->setText(QString::number(original_arr[3]));
}

void MainWindow::on_pbtn_clear_clicked()
{
    ui->lineEdit_o1->clear();
    ui->lineEdit_o2->clear();
    ui->lineEdit_o3->clear();
    ui->lineEdit_o4->clear();
    ui->lineEdit_s1->clear();
    ui->lineEdit_s2->clear();
    ui->lineEdit_s3->clear();
    ui->lineEdit_s4->clear();

    ui->lineEdit_o1->setFocus();
}

void MainWindow::pbtnSortPressed()
{
    qDebug() << "PRESSED!!";
}
