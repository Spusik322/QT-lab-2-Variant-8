#include "dataparser.h"

void DataParser::ParseData(QVector<QString> result) {
    data.insert("word1", result[0].remove(' '));
    data.insert("word2", result[1].remove(' '));
    data.insert("sentence", result[2]);
    data.insert("sentence1", result[3]);
    data.insert("sentence2", result[4]);
    qDebug() << "The general database has been created";
}

QPair<QString,QString> DataParser::getDataFor171 () const {
    qDebug() << "The data for171 has been created";

    return QPair<QString,QString>(data["word1"],data["word2"]);
}

QString DataParser::getDataFor183 () const {
    qDebug() << "The data for183 has been created";
    return data["sentence"];
}

QPair<QString,QString> DataParser::getDataFor195 () const {
    qDebug() << "The data for171 has been created";
    return QPair<QString,QString>(data["sentence1"],data["sentence2"]);
}
