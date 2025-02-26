#include <QApplication>
#include "iofile.h"
#include "dataparser.h"
#include "solver.h"
#include "repo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString in = "input.txt";
    IOFile file;
    file.readFile(in);
    DataParser par;
    par.ParseData(file.getResult());
    Repo repa;
    //171
    QPair<QString,QString> pair171(par.getDataFor171());
    Task171 solusion171;
    repa.pushBackToRep(solusion171.solve(pair171.first, pair171.second));
    //183
    QString str183(par.getDataFor183());
    Task183 solusion183;

    //195
    file.writeFile("output.txt", repa.getRepository());
    return a.exec();
}
