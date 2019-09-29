#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{   
    if (event->key() == Qt::Key_Enter || event -> key() == Qt::Key_Return) {
        auto address = ui->addressBox -> currentText();
        auto regularAddress = engine.processAddress(address.toStdString());
    }
}
