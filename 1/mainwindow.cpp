#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowTitle("ColorConverter");
    allValues.resize(n);
    for (int i = 0; i < n; ++i) allValues[i].resize(m);
    qDebug() << allValues;

    lightPalette = new QPalette();
    lightPalette->setColor(QPalette::Window, QColor(255, 213, 194));
    lightPalette->setColor(QPalette::WindowText, QColor(175, 93, 99));
    lightPalette->setColor(QPalette::Text, QColor(175, 93, 99));

    darkPalette = new QPalette();
    darkPalette->setColor(QPalette::Window, QColor(175, 93, 99));
    darkPalette->setColor(QPalette::WindowText, QColor(255, 213, 194));
    darkPalette->setColor(QPalette::Text, QColor(255, 213, 194));

    this->setPalette(*lightPalette);

    background = new QGridLayout();

    ChosenColor = new QLabel();
    Color = Qt::white;
    ChosenColor->setFixedSize(200,180);
    ChosenColor->setAlignment(Qt::AlignVCenter);

    ChosenColor->setStyleSheet("QLabel{background-color:"+Color.name()+";}");

    ChosenColorText = new QLabel("Chosen color:");
    QFont* font = new QFont();
    font->setPointSize(13);
    ChosenColorText->setFont(*font);
    ChosenColorText->setFixedSize(100,40);
    ChosenColorText->setAlignment(Qt::AlignCenter);

    ChosenColorHEX = new QLabel(Color.name());
    ChosenColorHEX->setFont(*font);
    ChosenColorHEX->setFixedSize(100,40);
    ChosenColorHEX->setAlignment(Qt::AlignCenter);

    LSlider1 = new QSlider();
    LSlider1->setRange(0,255);
    LSlider1->setOrientation(Qt::Horizontal);
    LSlider1->setFixedSize(105, 25);

    LSlider2 = new QSlider();
    LSlider2->setRange(0,255);
    LSlider2->setOrientation(Qt::Horizontal);
    LSlider2->setFixedSize(105, 25);

    LSlider3 = new QSlider();
    LSlider3->setRange(0,255);
    LSlider3->setOrientation(Qt::Horizontal);
    LSlider3->setFixedSize(105, 25);

    LSlider4 = new QSlider();
    LSlider4->setRange(0,255);
    LSlider4->setOrientation(Qt::Horizontal);
    LSlider4->setFixedSize(105, 25);

    MSlider1 = new QSlider();
    MSlider1->setRange(0,255);
    MSlider1->setOrientation(Qt::Horizontal);
    MSlider1->setFixedSize(105, 25);

    MSlider2 = new QSlider();
    MSlider2->setRange(0,255);
    MSlider2->setOrientation(Qt::Horizontal);
    MSlider2->setFixedSize(105, 25);

    MSlider3 = new QSlider();
    MSlider3->setRange(0,255);
    MSlider3->setOrientation(Qt::Horizontal);
    MSlider3->setFixedSize(105, 25);

    MSlider4 = new QSlider();
    MSlider4->setRange(0,255);
    MSlider4->setOrientation(Qt::Horizontal);
    MSlider4->setFixedSize(105, 25);

    RSlider1 = new QSlider();
    RSlider1->setRange(0,255);
    RSlider1->setOrientation(Qt::Horizontal);
    RSlider1->setFixedSize(105, 25);

    RSlider2 = new QSlider();
    RSlider2->setRange(0,255);
    RSlider2->setOrientation(Qt::Horizontal);
    RSlider2->setFixedSize(105, 25);

    RSlider3 = new QSlider();
    RSlider3->setRange(0,255);
    RSlider3->setOrientation(Qt::Horizontal);
    RSlider3->setFixedSize(105, 25);

    RSlider4 = new QSlider();
    RSlider4->setRange(0,255);
    RSlider4->setOrientation(Qt::Horizontal);
    RSlider4->setFixedSize(105, 25);

    LLabel1 = new QLabel("R:");
    LLabel1->setFixedSize(50, 25);
    LLabel1->setAlignment(Qt::AlignCenter);

    LLabel2 = new QLabel("G:");
    LLabel2->setFixedSize(50, 25);
    LLabel2->setAlignment(Qt::AlignCenter);

    LLabel3 = new QLabel("B:");
    LLabel3->setFixedSize(50, 25);
    LLabel3->setAlignment(Qt::AlignCenter);

    LLabel4 = new QLabel();
    LLabel4->setFixedSize(50, 25);
    LLabel4->setAlignment(Qt::AlignCenter);

    MLabel1 = new QLabel("L:");
    MLabel1->setFixedSize(50, 25);
    MLabel1->setAlignment(Qt::AlignCenter);

    MLabel2 = new QLabel("A:");
    MLabel2->setFixedSize(50, 25);
    MLabel2->setAlignment(Qt::AlignCenter);

    MLabel3 = new QLabel("B:");
    MLabel3->setFixedSize(50, 25);
    MLabel3->setAlignment(Qt::AlignCenter);

    MLabel4 = new QLabel();
    MLabel4->setFixedSize(50, 25);
    MLabel4->setAlignment(Qt::AlignCenter);

    RLabel1 = new QLabel("C:");
    RLabel1->setFixedSize(50, 25);
    RLabel1->setAlignment(Qt::AlignCenter);

    RLabel2 = new QLabel("M:");
    RLabel2->setFixedSize(50, 25);
    RLabel2->setAlignment(Qt::AlignCenter);

    RLabel3 = new QLabel("Y:");
    RLabel3->setFixedSize(50, 25);
    RLabel3->setAlignment(Qt::AlignCenter);

    RLabel4 = new QLabel("K:");
    RLabel4->setFixedSize(50, 25);
    RLabel4->setAlignment(Qt::AlignCenter);

    LLineEdit1 = new QLineEdit();
    LLineEdit1->setFixedSize(35, 25);
    //LLineEdit1->setAlignment(Qt::AlignCenter);

    LLineEdit2 = new QLineEdit();
    LLineEdit2->setFixedSize(35, 25);
    //LLineEdit2->setAlignment(Qt::AlignCenter);

    LLineEdit3 = new QLineEdit();
    LLineEdit3->setFixedSize(35, 25);
    //LLineEdit3->setAlignment(Qt::AlignCenter);

    LLineEdit4 = new QLineEdit();
    LLineEdit4->setFixedSize(35, 25);
    //LLineEdit4->setAlignment(Qt::AlignCenter);

    MLineEdit1 = new QLineEdit();
    MLineEdit1->setFixedSize(35, 25);
    MLineEdit1->setAlignment(Qt::AlignCenter);

    MLineEdit2 = new QLineEdit();
    MLineEdit2->setFixedSize(35, 25);
    MLineEdit2->setAlignment(Qt::AlignCenter);

    MLineEdit3 = new QLineEdit();
    MLineEdit3->setFixedSize(35, 25);
    MLineEdit3->setAlignment(Qt::AlignCenter);

    MLineEdit4 = new QLineEdit();
    MLineEdit4->setFixedSize(35, 25);
    MLineEdit4->setAlignment(Qt::AlignCenter);

    RLineEdit1 = new QLineEdit();
    RLineEdit1->setFixedSize(35, 25);
    RLineEdit1->setAlignment(Qt::AlignCenter);

    RLineEdit2 = new QLineEdit();
    RLineEdit2->setFixedSize(35, 25);
    RLineEdit2->setAlignment(Qt::AlignCenter);

    RLineEdit3 = new QLineEdit();
    RLineEdit3->setFixedSize(35, 25);
    RLineEdit3->setAlignment(Qt::AlignCenter);

    RLineEdit4 = new QLineEdit();
    RLineEdit4->setFixedSize(35, 25);
    RLineEdit4->setAlignment(Qt::AlignCenter);

    QRadioButton* lightThemeButton = new QRadioButton("Light Theme");
    QRadioButton* darkThemeButton = new QRadioButton("Dark Theme");

    lightThemeButton->setFixedSize(85, 20);
    darkThemeButton->setFixedSize(85, 20);

    lightThemeButton->setCheckable(true);
    lightThemeButton->setChecked(true);
    darkThemeButton->setCheckable(true);

    connect(LSlider1, &QSlider::valueChanged, this, &MainWindow::LSlidersMoved);
    connect(LSlider2, &QSlider::valueChanged, this, &MainWindow::LSlidersMoved);
    connect(LSlider3, &QSlider::valueChanged, this, &MainWindow::LSlidersMoved);
    connect(LSlider4, &QSlider::valueChanged, this, &MainWindow::LSlidersMoved);

    connect(MSlider1, &QSlider::valueChanged, this, &MainWindow::MSlidersMoved);
    connect(MSlider2, &QSlider::valueChanged, this, &MainWindow::MSlidersMoved);
    connect(MSlider3, &QSlider::valueChanged, this, &MainWindow::MSlidersMoved);
    connect(MSlider4, &QSlider::valueChanged, this, &MainWindow::MSlidersMoved);

    connect(RSlider1, &QSlider::valueChanged, this, &MainWindow::RSlidersMoved);
    connect(RSlider2, &QSlider::valueChanged, this, &MainWindow::RSlidersMoved);
    connect(RSlider3, &QSlider::valueChanged, this, &MainWindow::RSlidersMoved);
    connect(RSlider4, &QSlider::valueChanged, this, &MainWindow::RSlidersMoved);

    connect(LLineEdit1, &QLineEdit::textChanged, this, &MainWindow::LLeSChanged);
    connect(LLineEdit2, &QLineEdit::textChanged, this, &MainWindow::LLeSChanged);
    connect(LLineEdit3, &QLineEdit::textChanged, this, &MainWindow::LLeSChanged);
    connect(LLineEdit4, &QLineEdit::textChanged, this, &MainWindow::LLeSChanged);

    connect(MLineEdit1, &QLineEdit::textChanged, this, &MainWindow::MLeSChanged);
    connect(MLineEdit2, &QLineEdit::textChanged, this, &MainWindow::MLeSChanged);
    connect(MLineEdit3, &QLineEdit::textChanged, this, &MainWindow::MLeSChanged);
    connect(MLineEdit4, &QLineEdit::textChanged, this, &MainWindow::MLeSChanged);

    connect(RLineEdit1, &QLineEdit::textChanged, this, &MainWindow::RLeSChanged);
    connect(RLineEdit1, &QLineEdit::textChanged, this, &MainWindow::RLeSChanged);
    connect(RLineEdit1, &QLineEdit::textChanged, this, &MainWindow::RLeSChanged);
    connect(RLineEdit1, &QLineEdit::textChanged, this, &MainWindow::RLeSChanged);

    background->addWidget(ChosenColor,1,2,2,4, Qt::AlignLeft);
    background->addWidget(ChosenColorText,1,6,1,7, Qt::AlignBottom);
    background->addWidget(ChosenColorHEX,2,6,2,7, Qt::AlignTop);

    background->addWidget(LLabel1,3,0, Qt::AlignCenter);
    background->addWidget(LLabel2,4,0, Qt::AlignCenter);
    background->addWidget(LLabel3,5,0, Qt::AlignCenter);
    background->addWidget(LLabel4,6,0, Qt::AlignCenter);
    background->addWidget(LLineEdit1,3,1, Qt::AlignLeft);
    background->addWidget(LLineEdit2,4,1, Qt::AlignLeft);
    background->addWidget(LLineEdit3,5,1, Qt::AlignLeft);
    background->addWidget(LLineEdit4,6,1, Qt::AlignLeft);
    background->addWidget(LSlider1,3,2, Qt::AlignCenter);
    background->addWidget(LSlider2,4,2, Qt::AlignCenter);
    background->addWidget(LSlider3,5,2, Qt::AlignCenter);
    background->addWidget(LSlider4,6,2, Qt::AlignCenter);

    background->addWidget(MLabel1,3,3, Qt::AlignCenter);
    background->addWidget(MLabel2,4,3, Qt::AlignCenter);
    background->addWidget(MLabel3,5,3, Qt::AlignCenter);
    background->addWidget(MLabel4,6,3, Qt::AlignCenter);
    background->addWidget(MLineEdit1,3,4, Qt::AlignLeft);
    background->addWidget(MLineEdit2,4,4, Qt::AlignLeft);
    background->addWidget(MLineEdit3,5,4, Qt::AlignLeft);
    background->addWidget(MLineEdit4,6,4, Qt::AlignLeft);
    background->addWidget(MSlider1,3,5, Qt::AlignCenter);
    background->addWidget(MSlider2,4,5, Qt::AlignCenter);
    background->addWidget(MSlider3,5,5, Qt::AlignCenter);
    background->addWidget(MSlider4,6,5, Qt::AlignCenter);

    background->addWidget(RLabel1,3,6, Qt::AlignCenter);
    background->addWidget(RLabel2,4,6, Qt::AlignCenter);
    background->addWidget(RLabel3,5,6, Qt::AlignCenter);
    background->addWidget(RLabel4,6,6, Qt::AlignCenter);
    background->addWidget(RLineEdit1,3,7, Qt::AlignLeft);
    background->addWidget(RLineEdit2,4,7, Qt::AlignLeft);
    background->addWidget(RLineEdit3,5,7, Qt::AlignLeft);
    background->addWidget(RLineEdit4,6,7, Qt::AlignLeft);
    background->addWidget(RSlider1,3,8, Qt::AlignLeft);
    background->addWidget(RSlider2,4,8, Qt::AlignLeft);
    background->addWidget(RSlider3,5,8, Qt::AlignLeft);
    background->addWidget(RSlider4,6,8, Qt::AlignLeft);

    background->addWidget(lightThemeButton,7,0, Qt::AlignLeft);
    background->addWidget(darkThemeButton,7,2, Qt::AlignLeft);

    background->setAlignment(Qt::AlignLeft);

    QWidget *widget = new QWidget();
    widget->setLayout(background);
    setCentralWidget(widget);

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    createMenu();
    RGB_LAB_CMYK->setChecked(true);

    connect(lightThemeButton, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) this->setPalette(*lightPalette);
    });

    connect(darkThemeButton, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) this->setPalette(*darkPalette);
    });
}

void MainWindow::createMenu(){

    modeMenu = new QMenu(tr("Choose the converter"));
    RGB_LAB_CMYK = new QAction(tr("RGB ↔ LAB ↔ CMYK"), this);
    CMYK_RGB_HSV = new QAction(tr("CMYK ↔ RGB ↔ HSV"), this);
    RGB_XYZ_CMYK = new QAction(tr("RGB ↔ XYZ ↔ CMYK"), this);
    RGB_CMYK_HLS = new QAction(tr("RGB ↔ CMYK ↔ HLS"), this);
    RGB_XYZ_HSV = new QAction(tr("RGB ↔ XYZ ↔ HSV"), this);
    CMYK_LAB_XYZ = new QAction(tr("CMYK ↔ LAB ↔ XYZ"), this);
    RGB_XYZ_LAB = new QAction(tr("RGB ↔ XYZ ↔ LAB"), this);
    HSV_XYZ_LAB = new QAction(tr("HSV ↔ XYZ ↔ LAB"), this);
    RGB_CMYK_HSV = new QAction(tr("RGB ↔ CMYK ↔ HSV"), this);
    RGB_HSV_LAB = new QAction(tr("RGB ↔ HSV ↔ LAB"), this);
    CMYK_LAB_RGB = new QAction(tr("CMYK ↔ LAB ↔ RGB"), this);
    CMYK_HLS_XYZ = new QAction(tr("CMYK ↔ HLS ↔ XYZ"), this);
    CMYK_LAB_HSV = new QAction(tr("CMYK ↔ LAB ↔ HSV"), this);
    XYZ_LAB_HLS = new QAction(tr("XYZ ↔ LAB ↔ HLS"), this);
    RGB_HLS_LAB = new QAction(tr("RGB ↔ HLS ↔ LAB"), this);
    CMYK_RGB_HLS = new QAction(tr("CMYK ↔ RGB ↔ HLS"), this);
    RGB_XYZ_HLS = new QAction(tr("RGB ↔ XYZ ↔ HLS"), this);
    CMYK_XYZ_RGB = new QAction(tr("CMYK ↔ XYZ ↔ RGB"), this);

    connect(RGB_LAB_CMYK, &QAction::triggered, this, &MainWindow::RGB_LAB_CMYK_triggered);
    connect(CMYK_RGB_HSV, &QAction::triggered, this, &MainWindow::CMYK_RGB_HSV_triggered);
    connect(RGB_XYZ_CMYK, &QAction::triggered, this, &MainWindow::RGB_XYZ_CMYK_triggered);
    connect(RGB_CMYK_HLS, &QAction::triggered, this, &MainWindow::RGB_CMYK_HLS_triggered);
    connect(RGB_XYZ_HSV, &QAction::triggered, this, &MainWindow::RGB_XYZ_HSV_triggered);
    connect(CMYK_LAB_XYZ, &QAction::triggered, this, &MainWindow::CMYK_LAB_XYZ_triggered);
    connect(RGB_XYZ_LAB, &QAction::triggered, this, &MainWindow::RGB_XYZ_LAB_triggered);
    connect(HSV_XYZ_LAB, &QAction::triggered, this, &MainWindow::HSV_XYZ_LAB_triggered);
    connect(RGB_CMYK_HSV, &QAction::triggered, this, &MainWindow::RGB_CMYK_HSV_triggered);
    connect(RGB_HSV_LAB, &QAction::triggered, this, &MainWindow::RGB_HSV_LAB_triggered);
    connect(CMYK_LAB_RGB, &QAction::triggered, this, &MainWindow::CMYK_LAB_RGB_triggered);
    connect(CMYK_HLS_XYZ, &QAction::triggered, this, &MainWindow::CMYK_HLS_XYZ_triggered);
    connect(CMYK_LAB_HSV, &QAction::triggered, this, &MainWindow::CMYK_LAB_HSV_triggered);
    connect(XYZ_LAB_HLS, &QAction::triggered, this, &MainWindow::XYZ_LAB_HLS_triggered);
    connect(RGB_HLS_LAB, &QAction::triggered, this, &MainWindow::RGB_HSV_LAB_triggered);
    connect(CMYK_RGB_HLS, &QAction::triggered, this, &MainWindow::CMYK_RGB_HLS_triggered);
    connect(RGB_XYZ_HLS, &QAction::triggered, this, &MainWindow::RGB_XYZ_HLS_triggered);
    connect(CMYK_XYZ_RGB, &QAction::triggered, this, &MainWindow::CMYK_XYZ_RGB_triggered);

    modeMenu->addAction(RGB_LAB_CMYK);
    modeMenu->addAction(CMYK_RGB_HSV);
    modeMenu->addAction(RGB_XYZ_CMYK);
    modeMenu->addAction(RGB_CMYK_HLS);
    modeMenu->addAction(RGB_XYZ_HSV);
    modeMenu->addAction(CMYK_LAB_XYZ);
    modeMenu->addAction(RGB_XYZ_LAB);
    modeMenu->addAction(HSV_XYZ_LAB);
    modeMenu->addAction(RGB_CMYK_HSV);
    modeMenu->addAction(RGB_HSV_LAB);
    modeMenu->addAction(CMYK_LAB_RGB);
    modeMenu->addAction(CMYK_HLS_XYZ);
    modeMenu->addAction(CMYK_LAB_HSV);
    modeMenu->addAction(XYZ_LAB_HLS);
    modeMenu->addAction(RGB_HLS_LAB);
    modeMenu->addAction(CMYK_RGB_HLS);
    modeMenu->addAction(RGB_XYZ_HLS);
    modeMenu->addAction(CMYK_XYZ_RGB);

    menuBar = new QMenuBar(this);
    menuBar->setFixedSize(135, 25);
    menuBar->addMenu(modeMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RGB_LAB_CMYK_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    type_id1 = rgb;
    type_id2 = lab;
    type_id3 = cmyk;

    allValues = {getValues(type_id1), getValues(type_id2), getValues(type_id3)};

    LLabel1->setText("R:");
    LLabel2->setText("G:");
    LLabel3->setText("B:");
    LLabel4->setText("");


    MLabel1->setText("L:");
    MLabel2->setText("A:");
    MLabel3->setText("B:");
    MLabel4->setText("");

    RLabel1->setText("C:");
    RLabel2->setText("M:");
    RLabel3->setText("Y:");
    RLabel4->setText("K:");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();
}

void MainWindow::CMYK_RGB_HSV_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("C:");
    LLabel2->setText("M:");
    LLabel3->setText("Y:");
    LLabel4->setText("K:");

    LLabel4->show();
    LLineEdit4->show();
    LSlider4->show();

    MLabel1->setText("R:");
    MLabel2->setText("G:");
    MLabel3->setText("B:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("H:");
    RLabel2->setText("S:");
    RLabel3->setText("V:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::RGB_XYZ_CMYK_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("R:");
    LLabel2->setText("G:");
    LLabel3->setText("B:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("X:");
    MLabel2->setText("Y:");
    MLabel3->setText("Z:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("C:");
    RLabel2->setText("M:");
    RLabel3->setText("Y:");
    RLabel4->setText("K:");

    RLabel4->show();
    RLineEdit4->show();
    RSlider4->show();
}

void MainWindow::RGB_CMYK_HLS_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("R:");
    LLabel2->setText("G:");
    LLabel3->setText("B:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("C:");
    MLabel2->setText("M:");
    MLabel3->setText("Y:");
    MLabel4->setText("K:");

    MLabel4->show();
    MLineEdit4->show();
    MSlider4->show();

    RLabel1->setText("H:");
    RLabel2->setText("L:");
    RLabel3->setText("S:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::RGB_XYZ_HSV_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("R:");
    LLabel2->setText("G:");
    LLabel3->setText("B:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("X:");
    MLabel2->setText("Y:");
    MLabel3->setText("Z:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("H:");
    RLabel2->setText("S:");
    RLabel3->setText("V:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::CMYK_LAB_XYZ_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("C:");
    LLabel2->setText("M:");
    LLabel3->setText("Y:");
    LLabel4->setText("K:");

    LLabel4->show();
    LLineEdit4->show();
    LSlider4->show();

    MLabel1->setText("L:");
    MLabel2->setText("A:");
    MLabel3->setText("B:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("X:");
    RLabel2->setText("Y:");
    RLabel3->setText("Z:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::RGB_XYZ_LAB_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("R:");
    LLabel2->setText("G:");
    LLabel3->setText("B:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("X:");
    MLabel2->setText("Y:");
    MLabel3->setText("Z:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("L:");
    RLabel2->setText("A:");
    RLabel3->setText("B:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::HSV_XYZ_LAB_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("H:");
    LLabel2->setText("S:");
    LLabel3->setText("V:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("X:");
    MLabel2->setText("Y:");
    MLabel3->setText("Z:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("L:");
    RLabel2->setText("A:");
    RLabel3->setText("B:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::RGB_CMYK_HSV_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("R:");
    LLabel2->setText("G:");
    LLabel3->setText("B:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("C:");
    MLabel2->setText("M:");
    MLabel3->setText("Y:");
    MLabel4->setText("K:");

    MLabel4->show();
    MLineEdit4->show();
    MSlider4->show();

    RLabel1->setText("H:");
    RLabel2->setText("S:");
    RLabel3->setText("V:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::RGB_HSV_LAB_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("R:");
    LLabel2->setText("G:");
    LLabel3->setText("B:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("H:");
    MLabel2->setText("S:");
    MLabel3->setText("V:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("L:");
    RLabel2->setText("A:");
    RLabel3->setText("B:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::CMYK_LAB_RGB_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("C:");
    LLabel2->setText("M:");
    LLabel3->setText("Y:");
    LLabel4->setText("K:");

    LLabel4->show();
    LLineEdit4->show();
    LSlider4->show();

    MLabel1->setText("L:");
    MLabel2->setText("A:");
    MLabel3->setText("B:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("R:");
    RLabel2->setText("G:");
    RLabel3->setText("B:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::CMYK_HLS_XYZ_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("C:");
    LLabel2->setText("M:");
    LLabel3->setText("Y:");
    LLabel4->setText("K:");

    LLabel4->show();
    LLineEdit4->show();
    LSlider4->show();

    MLabel1->setText("H:");
    MLabel2->setText("L:");
    MLabel3->setText("S:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("X:");
    RLabel2->setText("Y:");
    RLabel3->setText("Z:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::CMYK_LAB_HSV_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("C:");
    LLabel2->setText("M:");
    LLabel3->setText("Y:");
    LLabel4->setText("K:");

    LLabel4->show();
    LLineEdit4->show();
    LSlider4->show();

    MLabel1->setText("L:");
    MLabel2->setText("A:");
    MLabel3->setText("B:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("H:");
    RLabel2->setText("S:");
    RLabel3->setText("V:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::XYZ_LAB_HLS_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("X:");
    LLabel2->setText("Y:");
    LLabel3->setText("Z:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("L:");
    MLabel2->setText("A:");
    MLabel3->setText("B:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("H:");
    RLabel2->setText("L:");
    RLabel3->setText("S:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::RGB_HLS_LAB_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("R:");
    LLabel2->setText("G:");
    LLabel3->setText("B:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("H:");
    MLabel2->setText("L:");
    MLabel3->setText("S:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("L:");
    RLabel2->setText("A:");
    RLabel3->setText("B:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::CMYK_RGB_HLS_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("C:");
    LLabel2->setText("M:");
    LLabel3->setText("Y:");
    LLabel4->setText("K:");

    LLabel4->show();
    LLineEdit4->show();
    LSlider4->show();

    MLabel1->setText("R:");
    MLabel2->setText("G:");
    MLabel3->setText("B:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("H:");
    RLabel2->setText("L:");
    RLabel3->setText("S:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::RGB_XYZ_HLS_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("R:");
    LLabel2->setText("G:");
    LLabel3->setText("B:");
    LLabel4->setText("");

    LLabel4->hide();
    LLineEdit4->hide();
    LSlider4->hide();

    MLabel1->setText("X:");
    MLabel2->setText("Y:");
    MLabel3->setText("Z:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("H:");
    RLabel2->setText("L:");
    RLabel3->setText("S:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::CMYK_XYZ_RGB_triggered()
{
    modeHasBeenChosen = true;

    if(modeHasBeenChosen){
        ChosenColor->setToolTip("Press to choose the color");
    }

    LLabel1->setText("C:");
    LLabel2->setText("M:");
    LLabel3->setText("Y:");
    LLabel4->setText("K:");

    LLabel4->show();
    LLineEdit4->show();
    LSlider4->show();

    MLabel1->setText("X:");
    MLabel2->setText("Y:");
    MLabel3->setText("Z:");
    MLabel4->setText("");

    MLabel4->hide();
    MLineEdit4->hide();
    MSlider4->hide();

    RLabel1->setText("R:");
    RLabel2->setText("G:");
    RLabel3->setText("B:");
    RLabel4->setText("");

    RLabel4->hide();
    RLineEdit4->hide();
    RSlider4->hide();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(modeHasBeenChosen){
    if(event->pos().x() < ChosenColor->x() || event->pos().x() > ChosenColor->x() + ChosenColor->width()) return;
    if(event->pos().y() < ChosenColor->y() || event->pos().y() > ChosenColor->y() + ChosenColor->height()) return;

    QColor changeColor = QColorDialog::getColor(Color, this, "Choose pen color");
    if (changeColor.isValid()){
        Color = changeColor;
        ChosenColorHEX->setText(Color.name());
        ChosenColor->setStyleSheet("QLabel{background-color:"+ChosenColorHEX->text()+";}");
    }
    setTextAndSliders();
    } else {
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("1.png"));
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Перед началом работы выберите режим конвертации!");
    msgBox.exec();
    }
}

double MainWindow::FromRGBToXYZ(double x)
{
    if (x>= 0.04045)
    {
        return pow((x+0.055) / 1.055, 2.4);
    }
    return (x / 12.92);
}

double MainWindow::FromXYZToLAB(double x)
{
    if(x>= 0.008856)
    {
        return pow(x,1.0/3.0);
    }
    else return (7.787*x + 16.0/116.0);
}

double MainWindow::FromLABToXYZ(double x)
{
    if (pow(x, 3) >= 0.008856)
    {
        return pow(x,3);
    }
    else return (x - 16.0 / 116.0) / 7.787;
}

double MainWindow::FromXYZToRGB(double x)
{
    if (x >= 0.0031308)
    {
        return (1.055 * pow(x, 1.0 / 2.4) - 0.055);
    }
    else return 12.92 * x;
}

QVector<int> MainWindow::getValues(type type_id)
{
    QVector<int> values;
    values.resize(m);
    switch(type_id)
    {
    case type::rgb:
        values = {Color.red(), Color.green(), Color.blue(), 0};
        break;
    case type::cmyk:
        int c,m,y,k;
        Color.getCmyk(&c,&m,&y,&k);
        values= {c,m,y,k};
        break;
    case type::hsv:
        int h,s,v;
        Color.getHsv(&h,&s,&v);
        values= {h,s,v};
        break;

    case type::hls:
        int h_,l_,s_;
        Color.getHsl(&h_,&s_,&l_);
        values = {h_,l_,s_};
        break;
    case type::xyz:
    {
        double X,Y,Z;
        double r = Color.red();
        double g = Color.green();
        double b = Color.blue();

        double Rn, Gn, Bn;
        Rn = qMin(qMax(0.0, FromRGBToXYZ (r / 255.0) *100.0), 100.0);
        Gn = qMin(qMax(0.0, FromRGBToXYZ (g / 255.0) *100.0), 100.0);
        Bn = qMin(qMax(0.0, FromRGBToXYZ (b / 255.0) *100.0), 100.0);

        X = 0.412453*Rn + 0.357580*Gn + 0.180423* Bn;
        Y = 0.212671*Rn + 0.715160*Gn + 0.072169*Bn;
        Z = 0.019334*Rn + 0.119193*Gn + 0.950227*Bn;

        values= {int(X),int(Y),int(Z)};
    }
    break;

    case type::lab:
    {
        double L,A,B;
        double X,Y,Z;
        double r = Color.red();
        double g = Color.green();
        double b = Color.blue();

        double Rn, Gn, Bn;
        Rn = FromRGBToXYZ (r / 255.0) * 100.0;
        Gn = FromRGBToXYZ (g / 255.0) * 100.0;
        Bn = FromRGBToXYZ (b / 255.0) * 100.0;

        X = 0.412453 * Rn + 0.357580 * Gn + 0.18042 * Bn;
        Y = 0.212671 * Rn + 0.715160 * Gn + 0.072169 * Bn;
        Z = 0.019334 * Rn + 0.119193 * Gn + 0.950227 * Bn;

        double Xw = 95.047;
        double Yw = 100.0;
        double Zw = 108.883;

        L = 116.0 * FromXYZToLAB(Y/Yw) -16.0;
        A = 500.0 *(FromXYZToLAB(X/Xw) - FromXYZToLAB(Y/Yw));
        B = 200.0 *(FromXYZToLAB(Y/Yw) - FromXYZToLAB(Z/Zw));

        values= {int(L),int(A), int (B)};
    }
    break;
    }

    return values;
}

void MainWindow::SetColor(type type_id, int a, int b, int c, int d)
{
    switch(type_id)
    {
    case type::rgb:
        Color.setRed(a);
        Color.setGreen(b);
        Color.setBlue(c);
        ChosenColorHEX->setText(Color.name());
        break;
    case type::cmyk:
        Color.setCmyk(a,b,c,d);
        ChosenColorHEX->setText(Color.name());
        break;
    case type::hsv:
        Color.setHsv(a,b,c);
        ChosenColorHEX->setText(Color.name());
        break;

    case type::hls:
        Color.setHsl(a,c,b);
        ChosenColorHEX->setText(Color.name());
        break;
    case type::xyz:
    {
        double x = a;
        double y = b;
        double z = c;
        double Rn = 0.032406 *x - 0.015372*y -0.004986* z;
        double Gn = -0.009689 *x + 0.018758*y + 0.000415 * z;
        double Bn = 0.000557 *x - 0.002040*y + 0.010570 * z;


        double R = qMin(qMax(0.0,FromXYZToRGB(Rn)*255), 255.0);
        double G = qMin(qMax(0.0, FromXYZToRGB(Gn)*255), 255.0);
        double B = qMin(qMax(0.0, FromXYZToRGB(Bn)*255), 255.0);

        Color.setRed(R);
        Color.setGreen(G);
        Color.setBlue(B);
        ChosenColorHEX->setText(Color.name());
    }
    break;
    case type::lab:
    {
        double Xw = 95.047;
        double Yw = 100.0;
        double Zw = 108.883;
        double L = a;
        double A = b;
        double B = c;
        double Y = FromLABToXYZ((L+16.0)/116.0)*Yw;
        double X = FromLABToXYZ(A/500.0 + (L+16.0)/116.0)*Xw;
        double Z = FromLABToXYZ((L+16.0)/116.0 - B/200.0)*Zw;

        double Rn = 0.032406 * X - 0.015372* Y -0.004986* Z;
        double Gn = -0.009689 * X + 0.018758 * Y + 0.000415 * Z;
        double Bn = 0.000557 * X - 0.002040 * Y + 0.010570 * Z;

        double R = FromXYZToRGB(Rn)*255;
        double G = FromXYZToRGB(Gn)*255;
        double B_ = FromXYZToRGB(Bn)*255;
        Color.setRed(R);
        Color.setGreen(G);
        Color.setBlue(B_);
        ChosenColorHEX->setText(Color.name());
    }
    break;
    }
}

void MainWindow::setTextAndSliders()
{
    allValues = {getValues(type_id1), getValues(type_id2), getValues(type_id3)};
    slider_changed_manual = true;
    LSlider1->setValue((allValues[0][0]));
    slider_changed_manual = true;
    LSlider2->setValue((allValues[0][1]));
    slider_changed_manual = true;
    LSlider3->setValue((allValues[0][2]));

    if(!LSlider4->isHidden()){
        slider_changed_manual = true;
        LSlider4->setValue((allValues[0][3]));
    }

    slider_changed_manual = true;
    MSlider1->setValue((allValues[1][0]));
    slider_changed_manual = true;
    MSlider2->setValue((allValues[1][1]));
    slider_changed_manual = true;
    MSlider3->setValue((allValues[1][2]));
    if(!MSlider4->isHidden()){
        slider_changed_manual = true;
        MSlider4->setValue((allValues[1][3]));
    }

    slider_changed_manual = true;
    RSlider1->setValue((allValues[2][0]));
    slider_changed_manual = true;
    RSlider2->setValue((allValues[2][1]));
    slider_changed_manual = true;
    RSlider3->setValue((allValues[2][3]));
    if(!RSlider4->isHidden()){
        slider_changed_manual = true;
        RSlider4->setValue((allValues[2][3]));
    }

    lineedit_changed_manual = true;
    LLineEdit1->setText(QString::number(allValues[0][0]));
    lineedit_changed_manual = true;
    LLineEdit2->setText(QString::number(allValues[0][1]));
    lineedit_changed_manual = true;
    LLineEdit3->setText(QString::number(allValues[0][2]));
    if(!LLineEdit4->isHidden()){
        lineedit_changed_manual = true;
        LLineEdit4->setText(QString::number(allValues[0][3]));
    }

    lineedit_changed_manual = true;
    MLineEdit1->setText(QString::number(allValues[1][0]));
    lineedit_changed_manual = true;
    MLineEdit2->setText(QString::number(allValues[1][1]));
    lineedit_changed_manual = true;
    MLineEdit3->setText(QString::number(allValues[1][2]));
    if(!MLineEdit4->isHidden()){
        lineedit_changed_manual = true;
        MLineEdit4->setText(QString::number(allValues[1][3]));
    }

    lineedit_changed_manual = true;
    RLineEdit1->setText(QString::number(allValues[2][0]));
    lineedit_changed_manual = true;
    RLineEdit2->setText(QString::number(allValues[2][1]));
    lineedit_changed_manual = true;
    RLineEdit3->setText(QString::number(allValues[2][2]));
    if(!RLineEdit4->isHidden()){
        lineedit_changed_manual = true;
        RLineEdit4->setText(QString::number(allValues[2][3]));
    }
}

void MainWindow::OutOfRange(int value){
    if(value < 0 || value > 255){
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("1.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Вводимое значение должно быть в пределах от 0 до 255!");
        msgBox.exec();
    }
}

void MainWindow::LSlidersMoved()
{
    if(modeHasBeenChosen){
    if(slider_changed_manual)
    {
    slider_changed_manual=false;
    return;
    }
    int val1 = LSlider1->value();
    int val2 = LSlider2->value();
    int val3 = LSlider3->value();
    int val4 = LSlider4->value();

    SetColor(type_id1, val1, val2, val3, val4);

    ChosenColor->setStyleSheet("QLabel{background-color:"+Color.name()+";}");
    setTextAndSliders();
    ChosenColorHEX->setText(Color.name());
    } else {
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("1.png"));
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Перед началом работы выберите режим конвертации!");
    msgBox.exec();
    }
}

void MainWindow::MSlidersMoved()
{
    if(modeHasBeenChosen){
    if(slider_changed_manual)
    {
    slider_changed_manual=false;
    return;
    }
    int val1 = MSlider1->value();
    int val2 = MSlider2->value();
    int val3 = MSlider3->value();
    int val4 = MSlider4->value();

    SetColor(type_id2, val1, val2, val3, val4);

    ChosenColor->setStyleSheet("QLabel{background-color:"+Color.name()+";}");
    setTextAndSliders();
    ChosenColorHEX->setText(Color.name());
    } else {
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("1.png"));
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Перед началом работы выберите режим конвертации!");
    msgBox.exec();
    }
}

void MainWindow::RSlidersMoved()
{
    if(modeHasBeenChosen){
    if(slider_changed_manual)
    {
    slider_changed_manual=false;
    return;
    }
    int val1 = RSlider1->value();
    int val2 = RSlider2->value();
    int val3 = RSlider3->value();
    int val4 = RSlider4->value();

    SetColor(type_id3, val1, val2, val3, val4);
    ChosenColor->setStyleSheet("QLabel{background-color:"+Color.name()+";}");
    setTextAndSliders();
    ChosenColorHEX->setText(Color.name());
    } else {
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("1.png"));
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Перед началом работы выберите режим конвертации!");
    msgBox.exec();
    }
}

void MainWindow::LLeSChanged(){
    if(modeHasBeenChosen){
    if(lineedit_changed_manual)
    {
    lineedit_changed_manual=false;
    return;
    }

    bool ok; // Этот флаг будет установлен в true, если конвертация прошла успешно

    int val1 = (LLineEdit1->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val1);

    int val2 = (LLineEdit2->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val2);

    int val3 = (LLineEdit3->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val3);

    int val4 = (LLineEdit4->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val4);

    SetColor(type_id3, val1, val2, val3, val4);
    ChosenColor->setStyleSheet("QLabel{background-color:"+Color.name()+";}");
    setTextAndSliders();
    ChosenColorHEX->setText(Color.name());
    } else {
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("1.png"));
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Перед началом работы выберите режим конвертации!");
    msgBox.exec();
    }
}

void MainWindow::MLeSChanged(){
    if(modeHasBeenChosen){
    if(lineedit_changed_manual)
    {
    lineedit_changed_manual=false;
    return;
    }

    bool ok; // Этот флаг будет установлен в true, если конвертация прошла успешно

    int val1 = (MLineEdit1->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val1);

    int val2 = (MLineEdit2->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val2);

    int val3 = (MLineEdit3->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val3);

    int val4 = (MLineEdit4->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val4);

    SetColor(type_id3, val1, val2, val3, val4);
    ChosenColor->setStyleSheet("QLabel{background-color:"+Color.name()+";}");
    setTextAndSliders();
    ChosenColorHEX->setText(Color.name());
    } else {
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("1.png"));
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Перед началом работы выберите режим конвертации!");
    msgBox.exec();
    }
}

void MainWindow::RLeSChanged(){
    if(modeHasBeenChosen){
    if(lineedit_changed_manual)
    {
    lineedit_changed_manual=false;
    return;
    }

    bool ok; // Этот флаг будет установлен в true, если конвертация прошла успешно

    int val1 = (RLineEdit1->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val1);

    int val2 = (RLineEdit2->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val2);

    int val3 = (RLineEdit3->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val3);

    int val4 = (RLineEdit4->text()).toInt(&ok);
    if (ok) {
    qDebug() << "Converted int value: " << val1;
    } else {
    qDebug() << "Conversion failed";
    }
    OutOfRange(val4);

    SetColor(type_id3, val1, val2, val3, val4);
    ChosenColor->setStyleSheet("QLabel{background-color:"+Color.name()+";}");
    setTextAndSliders();
    ChosenColorHEX->setText(Color.name());
    } else {
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("1.png"));
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Перед началом работы выберите режим конвертации!");
    msgBox.exec();
    }
}
