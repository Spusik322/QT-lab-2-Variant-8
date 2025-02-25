#pragma once
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QVector>

class IOFile
{
public:
    bool readFile(const QString& filePath);
    bool writeFile(const QString& filePath, const QString& content);
    QVector<QString> getResult() const;
private:
    QVector<QString> result;
};
