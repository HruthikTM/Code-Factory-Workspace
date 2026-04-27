import QtQuick 6.11

Rectangle {
    width: root.width        // ❌ root does not exist
    height: root.height / 2
    color: "red"
}
