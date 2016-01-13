#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "musicplayer.h"
#include "playlistmodel.h"
#include "playlistdelegate.h"

static QObject* getMusicPlayerInstance(QQmlEngine *engine, QJSEngine* jsEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(jsEngine)

    return MusicPlayer::getInstance();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("playlistmodel", MusicPlayer::getInstance()->playlistModel);

    qmlRegisterSingletonType<MusicPlayer>("MusicPlayer", 1, 0, "MusicPlayer", getMusicPlayerInstance);
    qmlRegisterType<PlayListDelegate>("PlayListDelegate", 1, 0, "PlayListDelegate");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

