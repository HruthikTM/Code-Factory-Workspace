import QtQuick


Window {
    width: 1200
    height: 900
    visible: true
    color: "#dcdcdc"
    title: qsTr("Hello World")

    CustomText {
        id: text1
        displaytext: "KRAFTON"
        anchors.bottom: frame4.top
        anchors.right: frame4.right
    }

    CustomText {
        id: text2
        displaytext: "PLAY NOW"
        anchors.top: frame6.bottom
        anchors.left: frame6.left
    }

    CustomRectangle {
        id: frame1
        rectWidth: 300
        rectHeight: 240
        anchors.centerIn: parent

        CustomText {
            id: text3
            displaytext: "BGMI"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    CustomRectangle {
        id: frame2
        rectWidth: 300
        rectHeight: 280
        anchors.bottom: frame1.top
        anchors.horizontalCenter:  frame1.horizontalCenter

        CustomImage {
            id: second
            source: "images/pic2.jpg"
        }
    }

    CustomRectangle {
        id: frame3
        rectWidth: 300
        rectHeight: 280
        anchors.top: frame1.bottom
        anchors.horizontalCenter:  frame1.horizontalCenter

        CustomImage {
            id: third
            source: "images/pic3.jpg"
        }
    }

    CustomRectangle {
        id: frame4
        rectWidth: 250
        rectHeight: 200
        anchors.right: frame2.left
        anchors.top: frame2.verticalCenter

        CustomImage {
            id: forth
            source: "images/pic4.jpg"
        }
    }

    CustomRectangle {
        id: frame5
        rectWidth: 240
        rectHeight: 190
        anchors.top: frame4.bottom
        anchors.right: frame1.left

        CustomImage {
            id: fifth
            source: "images/pic5.jpg"
        }
    }

    CustomRectangle {
        id: frame6
        rectWidth: 250
        rectHeight: 200
        anchors.left: frame3.right
        anchors.bottom: frame3.verticalCenter

        CustomImage {
            id: sixth
            source: "images/pic6.jpg"
        }
    }

    CustomRectangle {
        id: frame7
        rectWidth: 240
        rectHeight: 190
        anchors.bottom: frame6.top
        anchors.left: frame1.right

        CustomImage {
            id: seventh
            source: "images/pic7.jpg"
        }
    }
}
