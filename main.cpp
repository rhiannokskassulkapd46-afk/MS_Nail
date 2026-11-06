#include <QApplication>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include "mainwindow.h" // Наше главное окно

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

                                        // Устанавливаем стиль приложения
                                            app.setStyle("Fusion");

                                                // Проверяем и создаем базовые папки при старте (assets, config, data)
                                                    QString assetsPath = getResourceDir("assets");
                                                        QString configPath = getResourceDir("config");
                                                            QString dataPath = getResourceDir("data");

                                                                qDebug() << "Assets dir:" << assetsPath;
                                                                    qDebug() << "Config dir:" << configPath;
                                                                        qDebug() << "Data dir:" << dataPath;

                                                                            // Создаем и показываем главное окно
                                                                                MainWindow mainWindow;
                                                                                    
                                                                                        // Применяем современные стили (QSS) с мягкими тенями, скруглениями и прозрачностью
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
                                                                                                                                                                                                                                                                                                                                                                                                                                            