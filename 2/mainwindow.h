#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QListWidget>
#include <QPushButton>
#include <QGridLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void openFolder();
    void images(const QString &folderPath);
    void showInfoOne();
    void showInfo();

private:
    QGridLayout *layout;
    QTableWidget *tableWidget;
    QTableWidget *wholeTable;
    QListWidget *listWidget;
    QPushButton *open;
    QPushButton *allTheInfo;
    QPushButton *info;
    QPushButton *goBack;
    QPushButton *comeback;
    QPalette *lightPalette;
};

#endif // MAINWINDOW_H
