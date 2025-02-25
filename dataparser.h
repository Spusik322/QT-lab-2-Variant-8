#pragma once
#include <QVector>
#include <QString>
#include <QMap>
#include <QPair>
#include <QDebug>

class DataParser
{
private:
    QMap<QString,QString> data;
public:
    void ParseData(QVector<QString> result);
    QPair<QString,QString> getDataFor171 () const;
    QString getDataFor183 () const;
    QPair<QString,QString> getDataFor195 () const;
};

