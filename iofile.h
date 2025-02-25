#pragma once
#include <QTextStream>
#include <QtLogging>
#include <QString>
#include <QFile>
#include <QVector>

class IOFile
{
public:
    bool readFile(const QString& filePath, QString& content);
    bool writeFile(const QString& filePath, const QString& content);
};
