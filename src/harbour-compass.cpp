#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <QQuickView>
#include <QGuiApplication>
#include <QQmlContext>
#include <sailfishapp.h>
#include "compasssensor.h"

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/harbour-compass.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    qDebug("Hallo Welt, bis hierher funktionierts.");


    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();

    CompassSensor compassSensor;
    view->rootContext()->setContextProperty("compassSensor", &compassSensor);

    view->setSource(SailfishApp::pathTo("qml/harbour-compass.qml"));
    view->show();

    return app->exec();


    //return SailfishApp::main(argc, argv);
}
