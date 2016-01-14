import QtQuick 2.0

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
}

