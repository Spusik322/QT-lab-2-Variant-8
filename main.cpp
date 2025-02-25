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
    //171



    //183



    //195
    return a.exec();
}
