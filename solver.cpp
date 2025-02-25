#include "solver.h"

QString Task171::solve(QString str1, QString str2) {
    QString solution = "";
    QMap <QChar, int> lettersCount;
    for (QChar c : str1) {
        lettersCount[c]++;
    }
    qDebug() << "First word read successfully:" << str1;
    for (QChar c : str2) {
        lettersCount[c]++;
    }
    qDebug() << "Second word read successfully:" << str2;
    for (QChar c : lettersCount.keys()) {
        if (lettersCount[c] == 1) {
            solution += c + ' ';
        }
    }
    qDebug() << "received response:" << solution;
    return solution;
}
