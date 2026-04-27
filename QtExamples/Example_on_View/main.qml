import QtQuick 2.15
import QtQuick.Window 2.15
import MyClass 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyClass
    {
        id:myid
        name:"likhitha"
        Component.onCompleted: {
           myid.fun()
            console.log(name)
        }
    }


    Rectangle
    {
        width:300
        height:200
        Text {
            text: myid.name
        }

    }
}
