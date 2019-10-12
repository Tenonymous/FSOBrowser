#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "engine.h"
#include <QWebEngineView>
#include <QScopedPointer>
#include "dataprocessor.h"
#include <QStandardPaths>
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
    const std::string pathToHistoryFile = QStandardPaths::writableLocation(QStandardPaths::CacheLocation).toStdString() + "/history";
    const std::string pathToSettingsFile = QStandardPaths::writableLocation(QStandardPaths::CacheLocation).toStdString() + "/settings";
    Ui::MainWindow *ui;
    QScopedPointer<QWebEngineView> webView;
    Engine engine;
    DataProcessor dataProcessor;
    std::vector<Address> items;

    std::string currentAddress() const;

    QString formatAddressToShow(const std::string&) const;
    void loadFromFile();
    std::vector<Address> copyItemsToVector();
    void addItemsToBoxWithoutCurrent(const std::vector<Address>&, const std::string& current);
    void removeDuplicates();

signals:
    void enterPressed();
};
#endif // MAINWINDOW_H
