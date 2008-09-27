
#include <QtGui>
#include "taster_mainwindow.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    TasterMainWindow *mainWindow = new TasterMainWindow();
    mainWindow->show();
    return app.exec();
}
