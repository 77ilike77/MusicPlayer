import QtQuick 2.0


Item {
    readonly property int index: -1
    readonly property alias name: name.text

    Rectangle {
        id: background
        anchors.fill: parent
    }

    Text {
        text: index
    }

    Text {
        id: name
    }

}

