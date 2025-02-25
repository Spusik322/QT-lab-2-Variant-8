#include <QApplication>
#include "iofile.h"
#include "dataparser.h"
#include "solver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString in = "input.txt";
    IOFile file;
    file.readFile(in);
    DataParser par;
    par.ParseData(file.getResult());
    //171
    QPair<QString,QString> pair(par.getDataFor171());
    Task171 solusion;
    file.writeFile("output.txt", solusion.solve(pair.first, pair.second));
    //183



    //195
    return a.exec();
}
