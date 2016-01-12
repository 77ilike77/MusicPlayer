import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.0

import MusicPlayer 1.0

Item {
    id: playerContainer

    Row {
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

        Text {
            text: ""
        }
    }
}

