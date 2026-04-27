import QtQuick
pragma ComponentBehavior: Bound

Item {
    property Item host: null

    onHostChanged: {
        if (host)
            host.parentItemFunction("Hello from loaded item")
    }

    Component.onCompleted: {
        myLoader.loaderFunction("Hello from loaded item")
    }
}
