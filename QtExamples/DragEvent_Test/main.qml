import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 400
    height: 300
    visible: true

    Rectangle {
        id: dragItem
        width: 100
        height: 100
        x: 50
        y: 50
        color: "steelblue"

        MouseArea {
            id: mouse
            anchors.fill: parent
        }

        Drag.active: mouse.pressed
        Drag.source: dragItem
        Drag.hotSpot.x: width / 2
        Drag.hotSpot.y: height / 2
    }

    DropArea {
        anchors.fill: parent

        onEntered: function(drag) {
            console.log("ENTERED")
            drag.acceptProposedAction()
        }

        onDropped: function(drop) {
            console.log("DROPPED")
            console.log("drop.source =", drop.source)
            console.log("drop.drag exists =", drop.drag !== undefined)
        }
    }
}
