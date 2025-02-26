#include "repo.h"

void Repo::pushBackToRep(QString line) {
    repository.push_back(line);
    qDebug() << "The answer has been added to the repository:" << line;
}

QVector<QString> Repo::getRepository() const {
    qDebug() << "Repository with answers successfully received";
    return repository;
}
