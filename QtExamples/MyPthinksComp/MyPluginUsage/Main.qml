import QtQuick
import com.pthinks.MyPthinksComp

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color : "red"

    MyItem
    {

    }

    MyItemControls
    {
       width : 300;
       height : 300;
    }
}
