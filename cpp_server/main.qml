import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400
    height: 400

    Connections {
        target: qtqml
        onAddText: list.append(text)
    }

    TextArea {
        id: list
        anchors.fill: parent
        text: ""
    }
}
