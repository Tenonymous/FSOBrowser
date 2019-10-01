#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webView = new QWebEngineView(parent);
    webView->setGeometry(ui->siteArea->geometry());

    webView->load(QUrl("http://qt-project.org/"));
    webView->show();
    ui->siteArea->setWidget(webView);
 //   ui->siteArea->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete webView;
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{   
    if (event->key() == Qt::Key_Enter || event -> key() == Qt::Key_Return) {
        auto address = ui->addressBox -> currentText();
        auto regularAddress = engine.processAddress(address.toStdString());
        webView->load(QUrl(regularAddress.c_str()));
        webView->show();
    }
}
