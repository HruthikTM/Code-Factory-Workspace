import QtQuick
Rectangle {
    width: 100
    height: 100
    color: "red"
    x: 150

    onParentChanged:
    {
        console.log("Parent is changed ")
        //parent.helloParentItem()
        parent.helloNewItem()
    }

    Component.onCompleted: {
       hello()
    }
}

