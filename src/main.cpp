#include <QApplication>

#include "ui/mainwindow.h"
#include "config_manager.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Logger::init();

    ConfigManager::instance(); // 自动加载

    MainWindow w;
    w.show();

    return app.exec();
}
