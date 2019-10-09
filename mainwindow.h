#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "engine.h"
#include <QWebEngineView>
#include <QScopedPointer>
#include "dataprocessor.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QScopedPointer<QWebEngineView> webView;
    Engine engine;
    DataProcessor dataProcessor;
    std::vector<Address> items;

    void loadFromFile();
};
#endif // MAINWINDOW_H
