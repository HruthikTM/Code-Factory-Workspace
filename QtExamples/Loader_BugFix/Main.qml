import QtQuick

Item {
    id: root

    function parentItemFunction(msg) {
        console.log("Parent item function called:", msg)
    }

    Loader {
        id: myLoader
        source: "MyItem.qml"

        function loaderFunction(msg) {
            console.log("Loader function called:", msg)
        }

        onLoaded: {
            myLoader.item.host = root
        }
    }
}

