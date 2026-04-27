// import QtQuick

// Window {
//     width: 640
//     height: 480
//     visible: true
//     title: qsTr("Hello World")
// }
import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 300
    height: 150
    visible: true

    Rectangle{
        id: rect
        width: 200
        height: 100
        visible: true
        anchors.centerIn: parent
        color: "silver"


        SearchField {
            id: searchField
            anchors.centerIn: rect
            visible: true
            width:rect.width


            Component.onCompleted: {
                clearButtonVisible: true

                // console.log(searchIndicator.visible)
                searchIndicator.indicator = false
                console.log("typeof searchIndicator =", typeof searchIndicator)
                console.log("typeof searchIndicator =", typeof clearIndicator)
            }
        }
    }
}
