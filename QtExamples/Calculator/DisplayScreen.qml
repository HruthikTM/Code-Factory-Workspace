import QtQuick

Rectangle {
    radius: 10
    color: "gainsboro"

    Text {
        id: display
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: 15
        font.pixelSize: parent.height * 0.4
        //text: ""
        text: calculation ? calculation.displayText : ""
    }

    function textDisplay(value) {
        calculation.appendToDisplay(value)
    }

    function clearDisplay(){
        calculation.clearDisplay()
    }

    function clear(){
        calculation.deleteLastChar()
    }

    function calculate(){
        calculation.performCalcualtion()
    }

    // function textDisplay(value) {
    //     display.text += value
    // }
    //
    // function clearDisplay(){
    //     display.text = ""
    // }
    //
    // function clear(){
    //     display.text = display.text.slice(0,-1)
    // }
    //
    // function calculate(){
    //     display.text = eval(display.text)
    // }
    

}
