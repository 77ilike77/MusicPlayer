#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include "musicplayer.h"
#include "playlistmodel.h"

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

    app.setFont(QFont("Microsoft YaHei"));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

