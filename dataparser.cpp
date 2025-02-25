#include "dataparser.h"

void DataParser::ParseData(QVector<QString> result) {
    data.insert("word1", result[0].remove(' '));
    data.insert("word2", result[1].remove(' '));
    data.insert("sentenсe", result[2]);
    data.insert("sentenсe1", result[4]);
    data.insert("sentenсe2", result[5]);
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
    return QPair<QString,QString>(data["sentenсe1"],data["sentenсe2"]);
}
