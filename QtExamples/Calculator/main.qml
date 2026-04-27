import QtQuick

Window {
    width: 340
    height: 520
    minimumWidth: 340
    minimumHeight: 520
    maximumWidth: 340
    maximumHeight: 520
    visible: true
    title: "Calculator"

    Rectangle {
        anchors.fill: parent
        anchors.margins: 10

        DisplayScreen{
            id: screenDisplay
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.height * 0.15
        }

        Grid
        {
            id: custGrid
            anchors.top: screenDisplay.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.topMargin: 10

            rows: 5
            rowSpacing: 5
            columns: 4
            columnSpacing: 5


            CustomRectangle
            {
                id: btnallclear
                btnText: qsTr("AC")
                btnColor: "red"

                onBtnClicked: screenDisplay.clearDisplay()
            }
            CustomRectangle
            {
                id: btnhash
                btnText: qsTr("#")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btnmod
                btnText: qsTr("%")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btndivide
                btnText: qsTr("/")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btn7
                btnText: qsTr("7")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btn8
                btnText: qsTr("8")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btn9
                btnText: qsTr("9")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btnmultiply
                btnText: qsTr("*")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btn4
                btnText: qsTr("4")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btn5
                btnText: qsTr("5")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btn6
                btnText: qsTr("6")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btnminus
                btnText: qsTr("-")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btn1
                btnText: qsTr("1")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btn2
                btnText: qsTr("2")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btn3
                btnText: qsTr("3")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btnplus
                btnText: qsTr("+")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btnzero
                btnText: qsTr("0")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btndot
                btnText: qsTr(".")

                onBtnClicked: screenDisplay.textDisplay(btnText)
            }
            CustomRectangle
            {
                id: btnclear
                btnText: qsTr("C")

                onBtnClicked: screenDisplay.clear()
            }
            CustomRectangle
            {
                id: btnequals
                btnText: qsTr("=")

                onBtnClicked: screenDisplay.calculate()
            }
        }
    }
}
