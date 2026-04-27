import QtQuick

Rectangle {
    id: freeDrawCanvas
    color: "#f8f9fa"
    radius: 8

    property var freeDrawPoints: []
    property bool isDrawing: false

    property alias canvas: canvas

    // Hint overlay
    Text {
        anchors.centerIn: parent
        text: "\u270F\nClick and drag to draw freely"
        font.pixelSize: 15
        color: "#c0c0d0"
        horizontalAlignment: Text.AlignHCenter
        lineHeight: 1.6
        visible: freeDrawPoints.length === 0 && !isDrawing
        opacity: 0.7
    }

    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)

            // Light grid
            ctx.strokeStyle = "#e8e8f0"
            ctx.lineWidth = 0.5
            var gridSize = 30
            for(var gx = 0; gx < width; gx += gridSize) {
                ctx.beginPath()
                ctx.moveTo(gx, 0)
                ctx.lineTo(gx, height)
                ctx.stroke()
            }
            for(var gy = 0; gy < height; gy += gridSize) {
                ctx.beginPath()
                ctx.moveTo(0, gy)
                ctx.lineTo(width, gy)
                ctx.stroke()
            }

            if(freeDrawPoints.length > 0) {
                // Shadow
                ctx.strokeStyle = "rgba(124, 111, 247, 0.15)"
                ctx.lineWidth = 6
                ctx.lineJoin = "round"
                ctx.lineCap = "round"
                ctx.beginPath()
                ctx.moveTo(freeDrawPoints[0].x + 1, freeDrawPoints[0].y + 2)
                for(var s = 1; s < freeDrawPoints.length; s++) {
                    ctx.lineTo(freeDrawPoints[s].x + 1, freeDrawPoints[s].y + 2)
                }
                ctx.stroke()

                // Main stroke
                ctx.strokeStyle = "#2d2d44"
                ctx.lineWidth = 2.5
                ctx.lineJoin = "round"
                ctx.lineCap = "round"
                ctx.beginPath()
                ctx.moveTo(freeDrawPoints[0].x, freeDrawPoints[0].y)
                for(var i = 1; i < freeDrawPoints.length; i++) {
                    ctx.lineTo(freeDrawPoints[i].x, freeDrawPoints[i].y)
                }
                ctx.stroke()
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            cursorShape: Qt.CrossCursor

            onPressed: {
                freeDrawCanvas.isDrawing = true
                freeDrawCanvas.freeDrawPoints = []
                canvas.requestPaint()
            }

            onPositionChanged: {
                if(freeDrawCanvas.isDrawing) {
                    freeDrawCanvas.freeDrawPoints.push({x: mouseX, y: mouseY})
                    canvas.requestPaint()
                }
            }

            onReleased: {
                freeDrawCanvas.isDrawing = false

                if(freeDrawCanvas.freeDrawPoints.length > 0) {
                    var xCoords = []
                    var yCoords = []

                    for(var i = 0; i < freeDrawCanvas.freeDrawPoints.length; i++) {
                        xCoords.push(freeDrawCanvas.freeDrawPoints[i].x)
                        yCoords.push(freeDrawCanvas.freeDrawPoints[i].y)
                    }

                    backend.sendFreeDraw(xCoords, yCoords)
                }
            }
        }
    }

    function clearDrawing() {
        freeDrawPoints = []
        canvas.requestPaint()
    }
}
