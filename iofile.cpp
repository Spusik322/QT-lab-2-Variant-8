#include "iofile.h"

bool IOFile::readFile(const QString& filePath, QString& content) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qWarning("Could't open file for reading");
            return false;
        }
        QTextStream in(&file);
        content = in.readAll();
        file.close();
        qDebug("File read successfully");
        return true;
    }
bool IOFile::writeFile(const QString& filePath, const QString& content) {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning("Could't open file for writing");
        }
        QTextStream out(&file);
        out << content;
        file.close();
        qDebug("File written successfully");
        return true;
    }
