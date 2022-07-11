#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "string.h"
#include "unistd.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString data, fromBase, toBase, test;

    data = ui->input->text();
    fromBase = ui->from->currentText();
    toBase = ui->to->currentText();

    //write
    QString filePath = "/dev/lab51";
    QFile file(filePath);
    file.open(QIODevice::ReadWrite);
    if(!file.isOpen()){
        test = "false";
        qDebug("Cannot open file!");
    } else {
        test = "True";
    }

    QString input = data + " " + "2" + " " + "8";

    QTextStream inStream(&file);
    inStream << input;
    file.close();
    usleep(6000);

    QFile fileRead(filePath);
    if(!fileRead.open(QIODevice::ReadOnly)) {
        qDebug("Cannot open file!");
    }

    QTextStream in(&fileRead);
    while(!in.atEnd()) {
        QString line = in.readLine();
        ui->ressult->setText(line);
    }
    fileRead.close();

}

