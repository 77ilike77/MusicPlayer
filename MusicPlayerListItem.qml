import QtQuick 2.0

import MusicPlayer 1.0

Item {
    width: parent.width
    height: 30

    Rectangle {
        anchors.bottomMargin: 2
        anchors.fill: parent
        color: MusicPlayer.currentIndex === index ? "#22ccff22" : "#00ffffff"
    }

    Text {
        id: itemNumber
        text: number + "."
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: itemName
        text: name
        anchors.left: itemNumber.right
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
    }

    MouseArea {
        anchors.fill: parent
        onDoubleClicked:  {
            MusicPlayer.play(index);
        }
    }
}

