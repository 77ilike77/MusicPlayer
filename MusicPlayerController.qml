import QtQuick 2.4
import MusicPlayer 1.0
import QtQuick.Controls 1.2
import QtMultimedia 5.5

Item {
    id: playerContainer

    Rectangle {
        id: background
        color: "#00ccff"
        anchors.fill: parent
    }

    Row {
        Button {
            id: play
            text:

            onClicked: {
                MusicPlayer.play();
            }
        }

        Button {
            id: pause
            text: "pause"

            onClicked: {
                MusicPlayer.pause();
            }
        }
    }
}

