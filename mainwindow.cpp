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
    dataProcessor = DataProcessor(pathToHistoryFile, pathToSettingsFile);
    loadFromFile();
    ui->siteArea->setWidgetResizable(true);
    webView->load(QUrl(engine.processAddress(currentAddress()).c_str()));
    ui->siteArea->setWidget(webView.get());
    connect(ui->addressBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
        [=](int index){
            webView->setUrl(QUrl(ui->addressBox->itemText(index)));
            auto regularAddress = engine.processAddress(currentAddress());
            items.push_back(regularAddress);
            ui->addressBox->setCurrentText(formatAddressToShow(regularAddress));
        });
    connect(webView.get(), &QWebEngineView::titleChanged, this, [=](){
        setWindowTitle(webView->title());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::currentAddress() const
{
    return ui->addressBox->currentText().toStdString();
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event -> key() == Qt::Key_Return) {
        auto regularAddress = engine.processAddress(currentAddress());
        items.push_back(regularAddress);
        removeDuplicates();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    dataProcessor.writeAddressList(items);
    auto height = ui->centralwidget->height();
    auto width = ui->centralwidget->width();
    auto currentIndex = ui->addressBox->currentIndex();
    std::map<std::string, int> settings {
        {"height", height},
        {"width", width},
        {"currentIndex", currentIndex}
    };
    dataProcessor.saveSettings(settings);
}

void MainWindow::loadFromFile()
{
    items = dataProcessor.getAddressesList();
    for (const auto& item: items)
    {
        ui->addressBox->addItem(QString::fromStdString(item));
    }
    auto settings = dataProcessor.loadSetings();
    this->resize(settings["width"], settings["height"]);
    ui->addressBox->setCurrentIndex(settings["currentIndex"]);
}

QString MainWindow::formatAddressToShow(const std::string& address) const
{
    return QString::fromStdString(address);
}

std::vector<Address> MainWindow::copyItemsToVector()
{
    std::vector<Address> itemsInBox{};
    for (auto index = 0; index < ui->addressBox->count(); ++index) {
        itemsInBox.push_back(ui->addressBox->itemText(index).toStdString());
    }
    return itemsInBox;
}

void MainWindow::addItemsToBoxWithoutCurrent(const std::vector<Address>& itemsInBox, const std::string& current)
{
    for (const auto& item: itemsInBox)
    {
        if (item != current)
            ui->addressBox->addItem(QString::fromStdString(item));
    }
}
void MainWindow::removeDuplicates()
{
    auto itemsInBox = copyItemsToVector();
    std::transform(std::begin(itemsInBox), std::end(itemsInBox), std::begin(itemsInBox), [](Address val){
        return Engine().processAddress(val);
    });
    std::sort(std::begin(itemsInBox), std::end(itemsInBox));
    itemsInBox.erase(std::unique(std::begin(itemsInBox), std::end(itemsInBox)), std::end(itemsInBox));
    auto current = currentAddress();
    ui->addressBox->clear();
    addItemsToBoxWithoutCurrent(itemsInBox, current);
    ui->addressBox->insertItem(0, QString::fromStdString(current));
    ui->addressBox->setCurrentIndex(0);
}
