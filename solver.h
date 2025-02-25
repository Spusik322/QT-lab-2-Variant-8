#pragma once
#include <QString>
#include <QMap>

class Solver {
public:
    virtual QString solve(QString str1, QString str2, QString solution) = 0;
};

class Task171 : public Solver {
public:
    QString solve(QString str1, QString str2, QString solution) override;
};

class Task183 : public Solver {
public:
    QString solve(QString str1, QString str2 = "", QString solution = "") override;
};

class Task195 : public Solver {
public:
    QString solve(QString str1, QString str2, QString solution) override;
};
