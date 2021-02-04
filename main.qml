import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

import QtQuick.Layouts 1.0


import Person 1.0
import Party 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Frame {
        anchors.centerIn: parent

        ColumnLayout {

            anchors.fill: parent

            MyLabel {
                id: label1
                index: 0
            }

            MyLabel {
                id: label2
                index: 1
            }

            MyLabel {
                id: label3
                index: 2
            }

            MyLabel {
                id: label4
                index: 3
            }
        }
    }



}
