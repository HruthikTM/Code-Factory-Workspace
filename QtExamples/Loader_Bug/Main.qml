import QtQuick

// Window {
//     id: root
//     width: 300
//     height: 200
//     visible: true


//     function parentFunction(msg) {
//         console.log("Parent Item function called:", msg)
//     }


//     Loader {
//         id: myLoader
//         source: "MyItem.qml"

//         function loaderFunction(msg){
//             console.log("Loader Function called:", msg)
//         }
//     }
// }

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item {
        id: itm
        width: 200
        height:200
        function helloItem() {
            console.log("hello from Item")
        }

        Rectangle{
            width: 100
            height: 100
            color: "blue"
            MouseArea
            {
                anchors.fill: parent
                onClicked: {
                    load.source = "MyItem.qml"
                }
            }
        }

        Loader {
            id: load
            width: parent.width
            height: parent.height
            x: 50
            function hello() {
                console.log("hello from Loader")
            }
        }
    }
}
