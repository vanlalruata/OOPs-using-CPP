#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCryptographicHash>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->generateBtn, &QPushButton::clicked, this, &MainWindow::generateSerial);
    connect(ui->verifyBtn, &QPushButton::clicked, this, &MainWindow::verifySerial);
}

MainWindow::~MainWindow() { delete ui; }

// 🔹 Generate Unique Serial Key
void MainWindow::generateSerial() {
    QString name = ui->nameInput->text();
    QString email = ui->emailInput->text();
    QString cpuId = getCPUID();

    if (name.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter name and email.");
        return;
    }

    QString rawKey = name + email + cpuId;
    QByteArray hash = QCryptographicHash::hash(rawKey.toUtf8(), QCryptographicHash::Sha256);
    QString serialKey = hash.toHex().toUpper().mid(0, 16);

    QString encryptedKey = encryptAES(serialKey);

    ui->serialOutput->setText(encryptedKey);

    QFile file("serial_key.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << encryptedKey;
        file.close();
    }
}

// 🔹 Get Unique CPU ID (Windows/Linux)
QString MainWindow::getCPUID() {
#ifdef Q_OS_WIN
    QProcess process;
    process.start("wmic cpu get ProcessorId");
    process.waitForFinished();
    QString output = process.readAllStandardOutput();
    output = output.split("\n")[1].trimmed();
    return output;
#elif defined(Q_OS_LINUX)
    QFile file("/sys/devices/virtual/dmi/id/product_uuid");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        return in.readLine().trimmed();
    }
    return "UNKNOWN";
#else
    return "UNKNOWN";
#endif
}

// 🔹 AES Encryption (Simple XOR for Demo, Replace with OpenSSL)
QString MainWindow::encryptAES(const QString &plaintext) {
    QByteArray key = "1234567890ABCDEF";  // 16-byte key (Replace with AES-256)
    QByteArray encrypted;
    for (int i = 0; i < plaintext.size(); ++i)
        encrypted.append(plaintext[i].unicode() ^ key[i % key.size()]);
    return encrypted.toHex().toUpper();
}

// 🔹 AES Decryption
QString MainWindow::decryptAES(const QString &ciphertext) {
    QByteArray key = "1234567890ABCDEF";
    QByteArray data = QByteArray::fromHex(ciphertext.toUtf8());
    QByteArray decrypted;
    for (int i = 0; i < data.size(); ++i)
        decrypted.append(data[i] ^ key[i % key.size()]);
    return QString::fromUtf8(decrypted);
}

// 🔹 Verify Serial Key
void MainWindow::verifySerial() {
    QFile file("serial_key.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No serial key found.");
        return;
    }

    QTextStream in(&file);
    QString storedKey = in.readLine().trimmed();
    file.close();

    QString enteredKey = ui->serialOutput->text().trimmed();
    QString decryptedKey = decryptAES(storedKey);

    if (enteredKey == decryptedKey) {
        QMessageBox::information(this, "Success", "Serial Key Verified!");
    } else {
        QMessageBox::warning(this, "Error", "Invalid Serial Key!");
    }
}
