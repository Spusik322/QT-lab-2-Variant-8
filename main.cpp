#include <QApplication>
#include "iofile.h"
#include "dataparser.h"
#include "solver.h"
#include "repo.h"

QtMessageHandler originalHandler = nullptr;

void customMessageHandlerToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    static QFile logFile("log.txt");
    if (!logFile.isOpen()) {
        logFile.open(QIODevice::WriteOnly | QIODevice::Text);
    }

    QTextStream stream(&logFile);
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";

    QString message;
    switch (type) {
    case QtDebugMsg:
        message = QString("Debug: %1 (%2:%3, %4)").arg(localMsg.constData()).arg(file).arg(context.line).arg(function);
        break;
    case QtInfoMsg:
        message = QString("Info: %1 (%2:%3, %4)").arg(localMsg.constData()).arg(file).arg(context.line).arg(function);
        break;
    case QtWarningMsg:
        message = QString("Warning: %1 (%2:%3, %4)").arg(localMsg.constData()).arg(file).arg(context.line).arg(function);
        break;
    case QtCriticalMsg:
        message = QString("Critical: %1 (%2:%3, %4)").arg(localMsg.constData()).arg(file).arg(context.line).arg(function);
        break;
    case QtFatalMsg:
        message = QString("Fatal: %1 (%2:%3, %4)").arg(localMsg.constData()).arg(file).arg(context.line).arg(function);
        abort();
    }

    // Выводим сообщение в файл
    stream << message << '\n';
    logFile.flush();

    // Выводим сообщение в консоль
    fprintf(stdout, "%s\n", message.toLocal8Bit().constData());
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    originalHandler = qInstallMessageHandler(customMessageHandlerToFile);
    QString in = "input.txt";
    IOFile file;
    file.readFile(in);
    DataParser par;
    par.ParseData(file.getResult());
    Repo repa;
    ////////////////////////
    //171
    QPair<QString,QString> pair171(par.getDataFor171());
    Task171 solusion171;
    repa.pushBackToRep(solusion171.solve(pair171.first, pair171.second));
    ////////////////////////
    //183
    QString str183 = par.getDataFor183();
    Task183 solusion183;
    repa.pushBackToRep(solusion183.solve(str183));
    ////////////////////////
    //195
    QPair<QString,QString> pair195 = par.getDataFor195();
    Task195 solution195;
    repa.pushBackToRep(solution195.solve(pair195.first, pair195.second));
    ////////////////////////
    file.writeFile("output.txt", repa.getRepository());
    return 0;
}

