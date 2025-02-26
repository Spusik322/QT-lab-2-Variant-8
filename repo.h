#pragma once
#include <QString>
#include <QVector>
#include <QDebug>

class Repo
{
public:
    void pushBackToRep(QString line);
    QVector<QString> getRepository () const;
private:
    QVector<QString> repository;
};
