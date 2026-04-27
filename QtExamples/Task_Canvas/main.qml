import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: window
    visible: true
    width: 1080
    height: 680
    minimumWidth: 800
    minimumHeight: 500
    title: "Task Canvas"
    color: "#1e1e2e"

    property int toolIndex: 0
    property bool waitingForImageClear: false

    // Theme colors
    readonly property color sidebarBg: "#2b2b3d"
    readonly property color sidebarHover: "#363650"
    readonly property color accentColor: "#7c6ff7"
    readonly property color accentLight: "#9d93f9"
    readonly property color canvasBg: "#f8f9fa"
    readonly property color textPrimary: "#e8e8f0"
    readonly property color textSecondary: "#9090a8"
    readonly property color dangerColor: "#e74c5e"
    readonly property color dangerHover: "#f25d6e"

    RowLayout {
        anchors.fill: parent
        spacing: 0

        // Sidebar
        Rectangle {
            Layout.fillHeight: true
            Layout.preferredWidth: 220
            color: sidebarBg

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 0
                spacing: 0

                // App header
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 64
                    color: "transparent"

                    RowLayout {
                        anchors.centerIn: parent
                        spacing: 10

                        Text {
                            text: "\u270E"
                            font.pixelSize: 22
                            color: accentColor
                        }

                        Text {
                            text: "Task Canvas"
                            font.pixelSize: 17
                            font.bold: true
                            color: textPrimary
                        }
                    }
                }

                // Divider
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 1
                    Layout.leftMargin: 16
                    Layout.rightMargin: 16
                    color: "#3a3a52"
                }

                // Section label
                Text {
                    text: "DRAWING TOOLS"
                    font.pixelSize: 10
                    font.bold: true
                    font.letterSpacing: 1.5
                    color: textSecondary
                    Layout.topMargin: 20
                    Layout.leftMargin: 20
                    Layout.bottomMargin: 8
                }

                // Free Draw button
                ToolSidebarButton {
                    icon: "\u270F"
                    label: "Free Draw"
                    isActive: toolIndex === 0
                    accentColor: window.accentColor
                    hoverColor: window.sidebarHover
                    textColor: window.textPrimary
                    secondaryTextColor: window.textSecondary
                    onClicked: {
                        toolIndex = 0
                        stack.currentIndex = 0
                        waitingForImageClear = false
                    }
                }

                // Connect Dots button
                ToolSidebarButton {
                    icon: "\u2B24"
                    label: "Connect Dots"
                    isActive: toolIndex === 1
                    accentColor: window.accentColor
                    hoverColor: window.sidebarHover
                    textColor: window.textPrimary
                    secondaryTextColor: window.textSecondary
                    onClicked: {
                        toolIndex = 1
                        stack.currentIndex = 1
                        waitingForImageClear = false
                    }
                }

                // Upload Image button
                ToolSidebarButton {
                    icon: "\uD83D\uDDBC"
                    label: "Image Markup"
                    isActive: toolIndex === 2
                    accentColor: window.accentColor
                    hoverColor: window.sidebarHover
                    textColor: window.textPrimary
                    secondaryTextColor: window.textSecondary
                    onClicked: {
                        toolIndex = 2
                        stack.currentIndex = 2
                        waitingForImageClear = false
                    }
                }

                // Spacer
                Item {
                    Layout.fillHeight: true
                }

                // Divider
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 1
                    Layout.leftMargin: 16
                    Layout.rightMargin: 16
                    color: "#3a3a52"
                }

                // Clear button
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 48
                    Layout.margins: 12
                    Layout.bottomMargin: 16
                    radius: 8
                    color: clearArea.containsMouse ? dangerHover : dangerColor

                    Behavior on color { ColorAnimation { duration: 150 } }

                    Text {
                        anchors.centerIn: parent
                        text: waitingForImageClear ? "\u26A0  Clear Image" : "\u2716  Clear All"
                        font.pixelSize: 13
                        font.bold: true
                        color: "#ffffff"
                    }

                    MouseArea {
                        id: clearArea
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: handleClearAll()
                    }
                }
            }
        }

        // Main content area
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#1e1e2e"

            ColumnLayout {
                anchors.fill: parent
                spacing: 0

                // Toolbar / status bar
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 40
                    color: "#252538"

                    RowLayout {
                        anchors.fill: parent
                        anchors.leftMargin: 16
                        anchors.rightMargin: 16
                        spacing: 12

                        // Active tool indicator
                        Rectangle {
                            width: 8
                            height: 8
                            radius: 4
                            color: accentColor
                        }

                        Text {
                            text: {
                                if(toolIndex === 0) return "Free Draw \u2014 Click and drag to draw"
                                if(toolIndex === 1) return "Connect Dots \u2014 Click to place points"
                                return "Image Markup \u2014 Upload an image, then draw on it"
                            }
                            font.pixelSize: 12
                            color: textSecondary
                        }

                        Item { Layout.fillWidth: true }

                        Text {
                            text: {
                                if(toolIndex === 0 && freeDrawCanvas.freeDrawPoints.length > 0)
                                    return freeDrawCanvas.freeDrawPoints.length + " points"
                                if(toolIndex === 1 && connectDotsCanvas.dotPoints.length > 0)
                                    return connectDotsCanvas.dotPoints.length + " dots"
                                if(toolIndex === 2 && imageCanvas.drawingPoints.length > 0)
                                    return imageCanvas.drawingPoints.length + " points"
                                return ""
                            }
                            font.pixelSize: 11
                            color: accentLight
                        }
                    }
                }

                // Canvas area with border
                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 12
                    radius: 10
                    color: canvasBg
                    border.color: "#d0d0e0"
                    border.width: 1
                    clip: true

                    // Inner shadow effect
                    Rectangle {
                        anchors.fill: parent
                        anchors.margins: 1
                        radius: 9
                        color: "transparent"
                        border.color: "#00000008"
                        border.width: 1
                    }

                    StackLayout {
                        id: stack
                        anchors.fill: parent
                        anchors.margins: 2
                        currentIndex: 0

                        FreeDrawCanvas {
                            id: freeDrawCanvas
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                        }

                        ConnectDotsCanvas {
                            id: connectDotsCanvas
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                        }

                        ImageCanvas {
                            id: imageCanvas
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                        }
                    }
                }
            }
        }
    }

    function handleClearAll() {
        if(!waitingForImageClear) {
            if(toolIndex === 0) {
                freeDrawCanvas.freeDrawPoints = []
                freeDrawCanvas.canvas.requestPaint()
            }
            else if(toolIndex === 1) {
                connectDotsCanvas.dotPoints = []
                connectDotsCanvas.canvas.requestPaint()
            }
            else if(toolIndex === 2) {
                imageCanvas.drawingPoints = []
                imageCanvas.canvas.requestPaint()
            }
            waitingForImageClear = true
        }
        else {
            imageCanvas.imagePath = ""
            imageCanvas.drawingPoints = []
            imageCanvas.canvas.requestPaint()
            waitingForImageClear = false
        }
    }

    // Reusable sidebar tool button component
    component ToolSidebarButton: Rectangle {
        id: toolBtn

        property string icon: ""
        property string label: ""
        property bool isActive: false
        property color accentColor: "#7c6ff7"
        property color hoverColor: "#363650"
        property color textColor: "#e8e8f0"
        property color secondaryTextColor: "#9090a8"

        signal clicked()

        Layout.fillWidth: true
        Layout.preferredHeight: 44
        Layout.leftMargin: 8
        Layout.rightMargin: 8
        radius: 8
        color: isActive ? Qt.rgba(accentColor.r, accentColor.g, accentColor.b, 0.15) : (btnArea.containsMouse ? hoverColor : "transparent")

        Behavior on color { ColorAnimation { duration: 150 } }

        // Active indicator bar
        Rectangle {
            width: 3
            height: 24
            radius: 2
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            color: accentColor
            visible: isActive
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 16
            anchors.rightMargin: 12
            spacing: 12

            Text {
                text: toolBtn.icon
                font.pixelSize: 16
                color: isActive ? accentColor : secondaryTextColor
            }

            Text {
                text: toolBtn.label
                font.pixelSize: 13
                font.bold: isActive
                color: isActive ? textColor : secondaryTextColor
                Layout.fillWidth: true
            }
        }

        MouseArea {
            id: btnArea
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
            onClicked: toolBtn.clicked()
        }
    }
}
