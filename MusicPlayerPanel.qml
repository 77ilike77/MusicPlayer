import QtQuick 2.0

Item {
    id: panel
    anchors.fill: parent

    MusicPlayerListPanel {
        id: list
        anchors.top: controller.bottom
        width: parent.width
        height: parent.height
    }

    MusicPlayerControllerPanel {
        id: controller
        width: parent.width
        height: 100
        anchors.top: header.bottom
    }

    MusicPlayerHeaderPanel {
        id: header
        width: parent.width
        anchors.top: parent.top
    }
}

