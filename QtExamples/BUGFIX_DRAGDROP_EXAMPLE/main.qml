import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 200

    Rectangle {
        anchors.fill: parent
        color: "#dddddd"

        Rectangle {
            id: dragSource
            width: 80
            height: 80
            color: "steelblue"
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter

            Drag.active: mouseArea.pressed
            Drag.source: dragSource
            Drag.keys: ["demo"]
            Drag.hotSpot.x: width / 2
            Drag.hotSpot.y: height / 2

            MouseArea {
                id: mouseArea
                anchors.fill: parent
            }
        }

        DropArea {
            anchors.fill: parent
            keys: ["demo"]

            onEntered: {
                console.log("Hover source:", drag.source)
            }

            onDropped: function(drop) {
                console.log("Dropped source:", drop.source)

                // ❌ This never exists
                // console.log(drop.drag.source)
            }
        }
    }
}
