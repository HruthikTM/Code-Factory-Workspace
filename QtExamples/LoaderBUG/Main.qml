import QtQuick
Window {
    width: 640
    height: 480
    visible: true


    Item {
        id: itm
        width: 200; height: 200
        function helloParentItem() {
            console.log("hello from parent Item")
        }

        Item{
            id:sample
            width: 200; height: 200
            function helloNewItem() {
                console.log("hello from new Item")
            }
        }

        Loader {
            id:load
            x: 50
            function hello() {
                console.log("hello from Loader")
            }
            source: "MyItem.qml"
            onLoaded:
            {
                console.log("onLoaded function")
                //item.parent = itm
                item.parent = sample
            }
        }
    }
}
