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
    dataProcessor = DataProcessor("/Users/tobiasz/caches.csv");
    loadFromFile();
    ui->siteArea->setWidgetResizable(true);
    webView->setGeometry(ui->siteArea->geometry());

    webView->load(QUrl(engine.processAddress(ui->addressBox->currentText().toStdString()).c_str()));
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
        items.push_back(regularAddress);
        webView->load(QUrl(regularAddress.c_str()));
        webView->show();
        setWindowTitle(QString::fromStdString(regularAddress));
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    dataProcessor.writeAddressList(items);
}

void MainWindow::loadFromFile()
{
    items = dataProcessor.getAddressesList();
    for (const auto& item: items)
    {
        ui->addressBox->addItem(QString::fromStdString(item));
    }
}
