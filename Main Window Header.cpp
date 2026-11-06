#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPrepButtonClicked();
    void onExamSetupButtonClicked();
    void onSettingsButtonClicked();

private:
    void setupUI();

    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    
    // Элементы главного меню
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QPushButton *btnPrep;
    QPushButton *btnExamSetup;
    QPushButton *btnSettings;
};

#endif // MAINWINDOW_H