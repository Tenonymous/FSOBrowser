#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      webView(new QWebEngineView(parent))
{
    ui->setupUi(this);
    ui->siteArea->setWidgetResizable(true);
    webView->setGeometry(ui->siteArea->geometry());

    webView->load(QUrl("http://qt-project.org/"));
    webView->show();
    ui->siteArea->setWidget(webView.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{   
    if (event->key() == Qt::Key_Enter || event -> key() == Qt::Key_Return) {
        auto regularAddress = engine.processAddress(ui->addressBox->currentText().toStdString());
        webView->load(QUrl(regularAddress.c_str()));
        webView->show();
        setWindowTitle(QString::fromStdString(regularAddress));
    }
}
