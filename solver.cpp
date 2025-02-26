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

QString Task183::solve(QString str1, QString str2) {
    qDebug() << "Task 183 solving with sentence:" << str1;
    str1.remove(',');
    str1.remove('.');
    str1.remove('!');
    str1.remove('?');
    QStringList words = str1.split(' ', Qt::SkipEmptyParts);
    if (words.isEmpty()) {
        qDebug() << "Task 183 sentence is empty";
    }
    int minLength = words.first().length();
    for (int i = 1; i < words.size(); ++i) {
        if(minLength > words[i].length()) {
            minLength = words[i].length();
        }
    }
    qDebug() << "Task 183 result:" << minLength;
    return "minimum length = " + QString::number(minLength);
}

QString Task195::solve(QString str1, QString str2) {
    qDebug() << "Task 195 solving with sentences:" << str1 << "and" << str2;
    QMap<QString, int> wordCounts1;
    str1.remove(',');
    str1.remove('.');
    str1.remove('!');
    str1.remove('?');
    str2.remove(',');
    str2.remove('.');
    str2.remove('!');
    str2.remove('?');
    QStringList words1 = str1.split(' ', Qt::SkipEmptyParts);
    QStringList words2 = str2.split(' ', Qt::SkipEmptyParts);
    for (QString word : words1) {
        wordCounts1[word]++;
    }
    for (QString word : words2) {
        wordCounts1[word]++;
    }
    QString result = "";
    for (QString word : wordCounts1.keys()) {
        if (wordCounts1[word] == 1) {
            result += word;
            result += " ";
        }
    }

    if (!result.isEmpty()) {
        qDebug() << "There are no different words in the sentences";
    }
    qDebug() << "Task 195 result:" << result;
    return result;
}
