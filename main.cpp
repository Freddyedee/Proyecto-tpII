#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Backend/BackendManager.h"

int main(int argc, char *argv[]) {

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    BackendManager backend;
    engine.rootContext()->setContextProperty("Backend", &backend);

    engine.loadFromModule("interfaz-proyecto", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
