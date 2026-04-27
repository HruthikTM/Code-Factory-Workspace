import QtQuick

// Rectangle {
//     width: 160
//     height: 80
//     color: "lightblue"

//     Text {
//         anchors.centerIn: parent
//         text: "Click Me"
//     }

//     MouseArea {
//         anchors.fill: parent
//         onClicked: {
//             loaderFunction("Hello from loaded item")
//             parentFunction("Hello from loaded item")
//         }
//     }
// }


Rectangle {
    width: 50
    height: 50
    color: "red"

    MouseArea
    {
        anchors.fill: parent
        onClicked: hello()
    }

    Component.onCompleted: {
      console.log("Constructor Call")
    }
}

