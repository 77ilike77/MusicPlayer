import QtQuick 2.0
import MusicPlayer 1.0

Item {
    height: icon.height

    Image {
        id: background
        source: "header_background.png"
        anchors.fill: parent
    }

    Image {
        id: icon
        source: "pan.png"
    }

    Item {
        id: musicProgressBar
        height: parent.height
        anchors.left: icon.right
        anchors.right: parent.right

        Rectangle {
            id: progressBar
            height: 3
            width: 2*parent.width/3
            anchors.centerIn: parent
            color: "#22ffffff"

            Rectangle {
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                color: "#ecebd7"
                width: (MusicPlayer.currentPosition / MusicPlayer.currentDuration) * parent.width
            }

            MouseArea {
                anchors.fill: parent

                property int pos
                onClicked: {
                    if (!MusicPlayer.isSeekable()) return
                    pos = MusicPlayer.currentDuration * mouse.x / width
                    MusicPlayer.seek(pos);
                }
            }
        }

        Text {
            id: duration
            text: MusicPlayer.currentDuration
            color: "#ecebd7"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: progressBar.right
            anchors.right: musicProgressBar.right
            anchors.margins:20
        }
    }

}

