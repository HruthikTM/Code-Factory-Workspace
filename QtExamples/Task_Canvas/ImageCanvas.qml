import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts

Rectangle {
    id: imageCanvas
    color: "#f8f9fa"
    radius: 8

    property string imagePath: ""
    property var drawingPoints: []
    property bool isDrawing: false

    property alias canvas: canvas

    FileDialog {
        id: fileDialog
        title: "Select Image"

        onAccepted: {
            imageCanvas.imagePath = fileDialog.selectedFile
            imageCanvas.drawingPoints = []
            canvas.requestPaint()
            backend.uploadImage(fileDialog.selectedFile)
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 0
        spacing: 0

        // Top toolbar
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 48
            color: "#f0f0f8"
            radius: 8

            // Cut bottom radius
            Rectangle {
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                height: 8
                color: parent.color
            }

            RowLayout {
                anchors.fill: parent
                anchors.leftMargin: 16
                anchors.rightMargin: 16
                spacing: 12

                // Upload button
                Rectangle {
                    Layout.preferredWidth: uploadRow.width + 28
                    Layout.preferredHeight: 32
                    radius: 6
                    color: uploadArea.containsMouse ? "#6a5de8" : "#7c6ff7"

                    Behavior on color { ColorAnimation { duration: 150 } }

                    Row {
                        id: uploadRow
                        anchors.centerIn: parent
                        spacing: 8

                        Text {
                            text: "\uD83D\uDCC2"
                            font.pixelSize: 14
                            color: "#ffffff"
                            anchors.verticalCenter: parent.verticalCenter
                        }

                        Text {
                            text: "Choose Image"
                            font.pixelSize: 12
                            font.bold: true
                            color: "#ffffff"
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }

                    MouseArea {
                        id: uploadArea
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: fileDialog.open()
                    }
                }

                Item { Layout.fillWidth: true }

                Text {
                    text: imageCanvas.imagePath !== "" ? "Image loaded \u2713" : "No image"
                    font.pixelSize: 11
                    color: imageCanvas.imagePath !== "" ? "#4caf50" : "#9090a8"
                }
            }
        }

        // Canvas area
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#ffffff"
            border.color: "#e0e0e8"
            border.width: 1

            // Empty state
            Column {
                anchors.centerIn: parent
                spacing: 16
                visible: imageCanvas.imagePath === ""

                Rectangle {
                    width: 80
                    height: 80
                    radius: 40
                    color: "#f0f0f8"
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        anchors.centerIn: parent
                        text: "\uD83D\uDDBC"
                        font.pixelSize: 32
                    }
                }

                Text {
                    text: "No image selected"
                    font.pixelSize: 16
                    font.bold: true
                    color: "#4a4a60"
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    text: "Click 'Choose Image' above to upload\nthen draw annotations on it"
                    font.pixelSize: 12
                    color: "#9090a8"
                    horizontalAlignment: Text.AlignHCenter
                    lineHeight: 1.5
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            // Background Image
            Image {
                id: displayImage
                anchors.fill: parent
                anchors.margins: 4
                fillMode: Image.PreserveAspectFit
                source: imageCanvas.imagePath
                cache: false
            }

            // Drawing Canvas overlay
            Canvas {
                id: canvas
                anchors.fill: parent
                anchors.margins: 4

                onPaint: {
                    var ctx = getContext("2d")
                    ctx.clearRect(0, 0, width, height)

                    if(imageCanvas.drawingPoints.length > 0) {
                        // Shadow
                        ctx.strokeStyle = "rgba(231, 76, 94, 0.2)"
                        ctx.lineWidth = 7
                        ctx.lineJoin = "round"
                        ctx.lineCap = "round"
                        ctx.beginPath()
                        ctx.moveTo(imageCanvas.drawingPoints[0].x + 1, imageCanvas.drawingPoints[0].y + 2)
                        for(var s = 1; s < imageCanvas.drawingPoints.length; s++) {
                            ctx.lineTo(imageCanvas.drawingPoints[s].x + 1, imageCanvas.drawingPoints[s].y + 2)
                        }
                        ctx.stroke()

                        // Main stroke
                        ctx.strokeStyle = "#e74c5e"
                        ctx.lineWidth = 3
                        ctx.lineJoin = "round"
                        ctx.lineCap = "round"
                        ctx.globalAlpha = 0.9
                        ctx.beginPath()
                        ctx.moveTo(imageCanvas.drawingPoints[0].x, imageCanvas.drawingPoints[0].y)
                        for(var i = 1; i < imageCanvas.drawingPoints.length; i++) {
                            ctx.lineTo(imageCanvas.drawingPoints[i].x, imageCanvas.drawingPoints[i].y)
                        }
                        ctx.stroke()
                        ctx.globalAlpha = 1.0
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    cursorShape: imageCanvas.imagePath !== "" ? Qt.CrossCursor : Qt.ArrowCursor

                    onPressed: {
                        if(imageCanvas.imagePath !== "") {
                            imageCanvas.isDrawing = true
                            imageCanvas.drawingPoints = []
                            canvas.requestPaint()
                        }
                    }

                    onPositionChanged: {
                        if(imageCanvas.isDrawing && imageCanvas.imagePath !== "") {
                            imageCanvas.drawingPoints.push({x: mouseX, y: mouseY})
                            canvas.requestPaint()
                        }
                    }

                    onReleased: {
                        if(imageCanvas.imagePath !== "") {
                            imageCanvas.isDrawing = false

                            if(imageCanvas.drawingPoints.length > 0) {
                                var xCoords = []
                                var yCoords = []

                                for(var i = 0; i < imageCanvas.drawingPoints.length; i++) {
                                    xCoords.push(imageCanvas.drawingPoints[i].x)
                                    yCoords.push(imageCanvas.drawingPoints[i].y)
                                }

                                backend.sendFreeDraw(xCoords, yCoords)
                            }
                        }
                    }
                }
            }
        }
    }

    function clearDrawing() {
        drawingPoints = []
        canvas.requestPaint()
    }
}
