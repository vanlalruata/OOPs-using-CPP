#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void generateSerial();
    void verifySerial();

private:
    Ui::MainWindow *ui;
    QString getCPUID();
    QString generateHexKey();
    QString encryptAES(const QString &plaintext);
    QString decryptAES(const QString &ciphertext);
};

#endif // MAINWINDOW_H
