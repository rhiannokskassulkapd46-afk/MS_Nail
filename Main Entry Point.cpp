#include <QApplication>
#include <QDir>
#include <QDebug>
#include "mainwindow.h"

// Функция получения рабочей директории (рядом с .exe или в папке проекта для отладки)
QString getResourceDir(const QString &folderName) {
    QString exeDir = QCoreApplication::applicationDirPath();
    QString targetDir = exeDir + "/" + folderName;

    QDir dir(targetDir);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    return targetDir;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Устанавливаем стиль приложения и палитру для поддержки современных эффектов
    app.setStyle("Fusion");

    // Проверяем и создаем базовые папки при старте
    QString assetsPath = getResourceDir("assets");
    QString configPath = getResourceDir("config");
    QString dataPath = getResourceDir("data");

    qDebug() << "Assets dir:" << assetsPath;
    qDebug() << "Config dir:" << configPath;
    qDebug() << "Data dir:" << dataPath;

    // Создаем и показываем главное окно
    MainWindow mainWindow;
    
    // Применяем стили с прозрачностью и современным дизайном (QSS)
    QString modernStyle = R"(
        QMainWindow {
            background-color: #f4f6f9;
        }
        QWidget {
            font-family: 'Segoe UI', Arial, sans-serif;
            font-size: 14px;
            color: #1f2937;
        }
        QPushButton {
            background-color: #2563eb;
            color: white;
            border: none;
            border-radius: 10px;
            padding: 12px 20px;
            font-weight: 600;
        }
        QPushButton:hover {
            background-color: #1d4ed8;
        }
        QPushButton:pressed {
            background-color: #1e40af;
        }
        /* Эффект полупрозрачности для карточек */
        .QFrame, .QGroupBox {
            background-color: rgba(255, 255, 255, 0.85);
            border: 1px solid rgba(226, 232, 240, 0.8);
            border-radius: 14px;
        }
        QLineEdit, QComboBox {
            background-color: #ffffff;
            border: 1px solid #cbd5e1;
            border-radius: 8px;
            padding: 8px 12px;
        }
        QLineEdit:focus, QComboBox:focus {
            border: 2px solid #2563eb;
        }
    )";
    
    app.setStyleSheet(modernStyle);
    mainWindow.show();

    return app.exec();
}