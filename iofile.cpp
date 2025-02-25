#include "iofile.h"

bool IOFile::readFile(const QString& filePath) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Error: Could't open file for reading:" << filePath;
            return false;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            line.remove('\t');
            line.remove('\n');
            result.push_back(line);
        }
        file.close();
        qDebug() << "File read successfully:" << filePath;
        return true;
    }
bool IOFile::writeFile(const QString& filePath) {
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
QVector<QString> IOFile::getResult () const {
    qDebug() << "Results successfully received";
    return result;
}
