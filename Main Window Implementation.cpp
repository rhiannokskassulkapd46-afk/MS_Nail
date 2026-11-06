#include "mainwindow.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setupUI();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
    // Настройки главного окна
    setWindowTitle("Экзамен АЭС");
    resize(1024, 768);

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(16);
    mainLayout->setContentsMargins(40, 40, 40, 40);

    // Заголовок приложения
    titleLabel = new QLabel("Экзамен АЭС", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 32px; font-weight: bold; color: #0f172a; margin-bottom: 4px;");

    subtitleLabel = new QLabel("Проверка знаний нормативно-технической документации", this);
    subtitleLabel->setAlignment(Qt::AlignCenter);
    subtitleLabel->setStyleSheet("font-size: 14px; color: #64748b; margin-bottom: 24px;");

    // Кнопки главного меню
    btnPrep = new QPushButton("Подготовка к экзамену", this);
    btnExamSetup = new QPushButton("Сдать экзамен", this);
    btnSettings = new QPushButton("⚙️ Настройки", this);

    // Добавляем красивую легкую тень кнопкам для объема
    auto *shadowEffect1 = new QGraphicsDropShadowEffect(this);
    shadowEffect1->setBlurRadius(15);
    shadowEffect1->setOffset(0, 4);
    shadowEffect1->setColor(QColor(0, 0, 0, 25));
    btnPrep->setGraphicsEffect(shadowEffect1);

    auto *shadowEffect2 = new QGraphicsDropShadowEffect(this);
    shadowEffect2->setBlurRadius(15);
    shadowEffect2->setOffset(0, 4);
    shadowEffect2->setColor(QColor(0, 0, 0, 25));
    btnExamSetup->setGraphicsEffect(shadowEffect2);

    // Добавление элементов на макет
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(subtitleLabel);
    mainLayout->addWidget(btnPrep);
    mainLayout->addWidget(btnExamSetup);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(btnSettings);

    // Подключение сигналов к слотам (клик по кнопкам)
    connect(btnPrep, &QPushButton::clicked, this, &MainWindow::onPrepButtonClicked);
    connect(btnExamSetup, &QPushButton::clicked, this, &MainWindow::onExamSetupButtonClicked);
    connect(btnSettings, &QPushButton::clicked, this, &MainWindow::onSettingsButtonClicked);
}

void MainWindow::onPrepButtonClicked() {
    QMessageBox::information(this, "Подготовка", "Здесь откроется меню выбора документов для подготовки.");
}

void MainWindow::onExamSetupButtonClicked() {
    QMessageBox::information(this, "Экзамен", "Здесь откроется экран ввода данных сотрудника для экзамена.");
}

void MainWindow::onSettingsButtonClicked() {
    QMessageBox::information(this, "Настройки", "Здесь откроется панель настроек и авторизация администратора.");
}