import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.0

import MusicPlayer 1.0

Item {
    id: playerContainer

    Row {
        id: panel
        Button {
            id: playAndPause
            text:MusicPlayer.state === MusicPlayer.PlayingState ? "pause" : "play"

            onClicked: {
                if (MusicPlayer.state === MusicPlayer.PlayingState) {
                    MusicPlayer.pause();
                } else {
                    MusicPlayer.play();
                }
            }
        }

        Button {
            id: stop
            text: "stop"

            onClicked: {
                MusicPlayer.stop();
            }
        }

        Button {
            id: next
            text: "next"

            onClicked: {
                MusicPlayer.next();
            }
        }

        Button {
            text: "file"

            onClicked: {
                fileDialog.open();
            }
        }

        FileDialog {
            id: fileDialog
            title: "Please choose music file"
            selectMultiple: true
            nameFilters: [ "Image files (*.mp3 *.avi)", "All files (*)" ]
            onAccepted: {
                MusicPlayer.add(fileDialog.fileUrls);
            }
            onRejected: {
                console.log("File Choose Canceled")
            }
        }

        Text {
            text: MusicPlayer.state
        }
    }

    ListView {
        objectName: "playListObject"
        anchors.top: panel.bottom
        width: panel.width
        height: 300
        model: playlistmodel
        delegate:playlistdelegate
    }

    Component {
        id: playlistdelegate
            Row {
                width: panel.width
                spacing: 15

                Text {
                    text: playlistmodel.data(playlistmodel.index(index,1)) + 1
                }
                Button {
                    text: playlistmodel.data(playlistmodel.index(index,0))
                    onClicked: {
                        MusicPlayer.remove(index);
                    }
                }
            }
    }
}

