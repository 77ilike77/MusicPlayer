import QtQuick 2.0
import QtQuick.Dialogs 1.0

import MusicPlayer 1.0

Item {

    Image {
        id: background
        source: "all_background.png"
        anchors.fill: parent
    }

    Image {
        id: playButton
        source: getSource()
        anchors.centerIn: parent

        MouseArea {
            id: playButtonMouseArea
            anchors.fill: parent
            onClicked: {
                if (MusicPlayer.state === MusicPlayer.PlayingState) {
                    MusicPlayer.pause();
                } else {
                    MusicPlayer.play();
                }
            }
        }

        function getSource() {
            if (MusicPlayer.state === MusicPlayer.PlayingState) {
                if (playButtonMouseArea.pressed) {
                    return "pause_press.png";
                }
                return "pause.png";
            } else {
                if (playButtonMouseArea.pressed) {
                    return "begin_press.png";
                }
                return "begin.png";
            }
        }
    }

    Image {
        id: backButton
        source: backButtonMouseArea.pressed ? "back_press.png" : "back.png"
        anchors.verticalCenter: playButton.verticalCenter
        anchors.right: playButton.left
        scale: 0.7

        MouseArea {
            id: backButtonMouseArea
            anchors.fill: parent
            onClicked: {
                MusicPlayer.previous();
            }
        }
    }

    Image {
        id: nextButton
        source: nextButtonMouseArea.pressed ? "go_press.png" : "go.png"
        anchors.verticalCenter: playButton.verticalCenter
        anchors.left: playButton.right
        scale: 0.7

        MouseArea {
            id: nextButtonMouseArea
            anchors.fill: parent
            onClicked: {
                MusicPlayer.next();
            }
        }
    }

    Image {
        id: repeatButton
        source: getRepeatButtonSource()
        anchors.verticalCenter: playButton.verticalCenter
        anchors.right: backButton.left
        scale: 0.3

        MouseArea {
            id: repeatButtonMouseArea
            anchors.fill: parent
            onClicked: {
                MusicPlayer.changePlaybackMode();
            }
        }

        function getRepeatButtonSource() {
            switch (MusicPlayer.mode) {
                case MusicPlayer.CurrentItemInLoop:
                    return "repeat_press.png";
                case MusicPlayer.Loop:
                    return "repeat.png";
                case MusicPlayer.Random:
                    return "shuffl.png";
            }
        }
    }

    Image {
        id: fileChooseButton
        source: fileChooseButtonMouseArea.pressed ? "more_press.png" : "more.png"
        anchors.verticalCenter: playButton.verticalCenter
        anchors.right: parent.right
        scale: 0.6

        MouseArea {
            id: fileChooseButtonMouseArea
            anchors.fill: parent
            onClicked: {
                fileDialog.open();
            }
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

}

