import QtQuick 2.0

Item {
    Image {
        source: "play_list_background.png"
        anchors.fill: parent
    }

    ListView {
        id: playListView
        width: parent.width
        height: parent.height
        model: playlistmodel
        delegate:playlistdelegate
    }

    Component {
        id: playlistdelegate

        MusicPlayerListItem {

        }
    }

}

