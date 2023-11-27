#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMouseEvent>
#include <QColor>
#include <QPainter>
#include <QApplication>
#include <QRadioButton>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QSlider>
#include <QLabel>
#include <QMessageBox>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QtMath>
#include <QVector>
#include <QColorDialog>
#include <QVariant>

enum type {rgb = 0, cmyk, hsv, xyz, hls, lab};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    const int n = 3, m = 4;

private slots:
    void RGB_LAB_CMYK_triggered();
    void CMYK_RGB_HSV_triggered();
    void RGB_XYZ_CMYK_triggered();
    void RGB_CMYK_HLS_triggered();
    void RGB_XYZ_HSV_triggered();
    void CMYK_LAB_XYZ_triggered();
    void RGB_XYZ_LAB_triggered();
    void HSV_XYZ_LAB_triggered();
    void RGB_CMYK_HSV_triggered();
    void RGB_HSV_LAB_triggered();
    void CMYK_LAB_RGB_triggered();
    void CMYK_HLS_XYZ_triggered();
    void CMYK_LAB_HSV_triggered();
    void XYZ_LAB_HLS_triggered();
    void RGB_HLS_LAB_triggered();
    void CMYK_RGB_HLS_triggered();
    void RGB_XYZ_HLS_triggered();
    void CMYK_XYZ_RGB_triggered();

    void LSlidersMoved();
    void MSlidersMoved();
    void RSlidersMoved();

    void LLeSChanged();
    void MLeSChanged();
    void RLeSChanged();

protected:
    void mousePressEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    type type_id1, type_id2, type_id3;
    bool slider_changed_manual = false;
    bool lineedit_changed_manual = false;
    bool modeHasBeenChosen = false;

    double FromRGBToXYZ(double x);
    double FromXYZToRGB(double x);
    double FromXYZToLAB(double x);
    double FromLABToXYZ(double x);
    QVector<int> getValues(type type_id);
    void SetColor(type type_id, int a, int b, int c, int d);
    void setTextAndSliders();
    void OutOfRange(int value);

    QVector<QVector<int>> allValues;

    void createMenu();
    QMenu* modeMenu;
    QMenuBar *menuBar;

    QAction* RGB_LAB_CMYK;
    QAction* CMYK_RGB_HSV;
    QAction* RGB_XYZ_CMYK;
    QAction* RGB_CMYK_HLS;
    QAction* RGB_XYZ_HSV;
    QAction* CMYK_LAB_XYZ;
    QAction* RGB_XYZ_LAB;
    QAction* HSV_XYZ_LAB;
    QAction* RGB_CMYK_HSV;
    QAction* RGB_HSV_LAB;
    QAction* CMYK_LAB_RGB;
    QAction* CMYK_HLS_XYZ;
    QAction* CMYK_LAB_HSV;
    QAction* XYZ_LAB_HLS;
    QAction* RGB_HLS_LAB;
    QAction* CMYK_RGB_HLS;
    QAction* RGB_XYZ_HLS;
    QAction* CMYK_XYZ_RGB;

    QLabel* ChosenColor;
    QColor Color;
    QLabel* ChosenColorText;
    QLabel* ChosenColorHEX;

    QString r;
    QString g;
    QString b;

    QSlider* LSlider1;
    QSlider* LSlider2;
    QSlider* LSlider3;
    QSlider* LSlider4;

    QSlider* MSlider1;
    QSlider* MSlider2;
    QSlider* MSlider3;
    QSlider* MSlider4;

    QSlider* RSlider1;
    QSlider* RSlider2;
    QSlider* RSlider3;
    QSlider* RSlider4;

    QLabel* LLabel1;
    QLabel* LLabel2;
    QLabel* LLabel3;
    QLabel* LLabel4;

    QLabel* MLabel1;
    QLabel* MLabel2;
    QLabel* MLabel3;
    QLabel* MLabel4;

    QLabel* RLabel1;
    QLabel* RLabel2;
    QLabel* RLabel3;
    QLabel* RLabel4;

    QLineEdit* LLineEdit1;
    QLineEdit* LLineEdit2;
    QLineEdit* LLineEdit3;
    QLineEdit* LLineEdit4;

    QLineEdit* MLineEdit1;
    QLineEdit* MLineEdit2;
    QLineEdit* MLineEdit3;
    QLineEdit* MLineEdit4;

    QLineEdit* RLineEdit1;
    QLineEdit* RLineEdit2;
    QLineEdit* RLineEdit3;
    QLineEdit* RLineEdit4;

    QGridLayout *background;
    QPalette* lightPalette;
    QPalette* darkPalette;

};
#endif // MAINWINDOW_H
