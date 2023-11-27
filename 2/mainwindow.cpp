#include <QFileDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDir>
#include <QImageWriter>
#include <QImage>
#include <QFileInfo>
#include <QDialog>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    lightPalette = new QPalette();
    lightPalette->setColor(QPalette::Window, QColor(255, 213, 194));
    lightPalette->setColor(QPalette::WindowText, QColor(175, 93, 99));
    lightPalette->setColor(QPalette::Text, QColor(175, 93, 99));
    this->setPalette(*lightPalette);

    layout = new QGridLayout(this);
    tableWidget = new QTableWidget();
    wholeTable = new QTableWidget();
    tableWidget->setFixedSize(300, 176);
    listWidget = new QListWidget();
    listWidget->setFixedSize(500, 400);
    open = new QPushButton("Open the folder");
    open->setFixedSize(200, 30);
    open->setStyleSheet("background-color:"+QColor(175, 93, 99).name());
    info = new QPushButton("Show the Information");
    info->setFixedSize(250, 30);
    info->setStyleSheet("background-color:"+QColor(175, 93, 99).name());
    allTheInfo = new QPushButton("Show all the Information");
    allTheInfo->setFixedSize(250, 30);
    allTheInfo->setStyleSheet("background-color:"+QColor(175, 93, 99).name());

    tableWidget->setColumnCount(1);
    tableWidget->setRowCount(5);
    tableWidget->setVerticalHeaderLabels({"File Name", "Size (px)", "Resolution (dpi)", "Color Depth", "Compression"});
    tableWidget->setHorizontalHeaderLabels({"Chosen image characteristics"});
    tableWidget->setColumnWidth(0, 200);

    wholeTable->setColumnCount(5);
    wholeTable->setHorizontalHeaderLabels({"File Name", "Size (px)", "Resolution (dpi)", "Color Depth", "Compression"});
    wholeTable->setColumnWidth(0, 180);

    connect(open, &QPushButton::clicked, this, &MainWindow::openFolder);
    connect(allTheInfo, &QPushButton::clicked, this, &MainWindow::showInfo);
    connect(info, &QPushButton::clicked, this, &MainWindow::showInfoOne);

    layout->addWidget(open,0,1,Qt::AlignCenter);
    layout->addWidget(listWidget,1,1,Qt::AlignCenter);
    layout->addWidget(tableWidget,1,4,Qt::AlignCenter);
    layout->addWidget(allTheInfo,3,4,Qt::AlignCenter);
    layout->addWidget(info,2,4,Qt::AlignCenter);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::openFolder()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Select Folder");

    if (!folderPath.isEmpty()) {
        images(folderPath);
    }
}

void MainWindow::images(const QString &folderPath)
{
    QDir directory(folderPath);
    QStringList nameFilters = {"*.jpg", "*.gif", "*.tif", "*.bmp", "*.png", "*.pcx"};
    QStringList imageFiles = directory.entryList(nameFilters, QDir::Files);
    listWidget->setIconSize(QSize(35,35));

    wholeTable->setRowCount(imageFiles.size());

    for (int i = 0; i < imageFiles.size(); ++i) {
        QString filePath = directory.filePath(imageFiles[i]);
        QImage image(filePath);
        listWidget->addItem(imageFiles[i]);
        listWidget->item(i)->setIcon(QIcon(filePath));
        QImageWriter imageWriter(filePath);

        QTableWidgetItem *fileNameItem = new QTableWidgetItem(imageFiles[i]);
        QTableWidgetItem *sizeItem = new QTableWidgetItem(QString("%1 x %2").arg(image.width()).arg(image.height()));
        QTableWidgetItem *resolutionItem = new QTableWidgetItem(QString("%1 x %2").arg(image.dotsPerMeterX() * 0.0254).arg(image.dotsPerMeterY() * 0.0254));
        QTableWidgetItem *colorDepthItem = new QTableWidgetItem(QString::number(image.depth()));
        QTableWidgetItem *compressionItem = new QTableWidgetItem(QString::number(imageWriter.compression()));

        wholeTable->setItem(i, 0, fileNameItem);
        wholeTable->setItem(i, 1, sizeItem);
        wholeTable->setItem(i, 2, resolutionItem);
        wholeTable->setItem(i, 3, colorDepthItem);
        wholeTable->setItem(i, 4, compressionItem);
    }
}

void MainWindow::showInfoOne(){
    QListWidgetItem *curItem = listWidget->currentItem();
    if (!curItem) {
        return;
    }
    int i = listWidget->row(curItem);

    if (i < 0 || i >= wholeTable->rowCount()) {
        return;
    }

    QTableWidgetItem *fileNameItem = new QTableWidgetItem(wholeTable->item(i, 0)->text());
    QTableWidgetItem *sizeItem = new QTableWidgetItem(wholeTable->item(i, 1)->text());
    QTableWidgetItem *resolutionItem = new QTableWidgetItem(wholeTable->item(i, 2)->text());
    QTableWidgetItem *colorDepthItem = new QTableWidgetItem(wholeTable->item(i, 3)->text());
    QTableWidgetItem *compressionItem = new QTableWidgetItem(wholeTable->item(i, 4)->text());

    tableWidget->setItem(0, 0, fileNameItem);
    tableWidget->setItem(1, 0, sizeItem);
    tableWidget->setItem(2, 0, resolutionItem);
    tableWidget->setItem(3, 0, colorDepthItem);
    tableWidget->setItem(4, 0, compressionItem);
}

void MainWindow::showInfo(){
    QDialog table;
    table.setFixedSize(635, 500);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(wholeTable);
    table.setPalette(*lightPalette);
    table.setLayout(layout);
    table.exec();
}
