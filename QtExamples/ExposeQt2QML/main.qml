import QtQuick
import QtQuick.Window
import com.app.sample 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Sample {
        id: sample
    }

    Rectangle {
        id: mainwindow
        width: 200
        height: 100
        color: "yellow"
        anchors.centerIn: parent

        CustomBtn {
            id: btn1
            btnText: "Submit"
            btnColor: "red"

            anchors.left: parent.left
            anchors.leftMargin: 20

            onClicked: {
                sample.work()
                console.log("Submit btn is clicked")
            }
        }

        CustomBtn {
            id: btn2
            btnText: "Cancel"
            btnColor: "blue"

            anchors.right: parent.right
            anchors.rightMargin: 20

            onClicked: {
                sample.work()
                console.log("Cancel btn is clicked")
            }
        }
    }
}
