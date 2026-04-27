import QtQuick

Rectangle {
    id: connectDotsCanvas
    color: "#f8f9fa"
    radius: 8

    property var dotPoints: []

    property alias canvas: canvas

    // Hint overlay
    Text {
        anchors.centerIn: parent
        text: "\u2B24\nClick to place points and connect them"
        font.pixelSize: 15
        color: "#c0c0d0"
        horizontalAlignment: Text.AlignHCenter
        lineHeight: 1.6
        visible: dotPoints.length === 0
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

            // Draw connecting lines with shadow
            if(dotPoints.length >= 2) {
                // Shadow
                ctx.strokeStyle = "rgba(124, 111, 247, 0.12)"
                ctx.lineWidth = 5
                ctx.lineJoin = "round"
                ctx.lineCap = "round"
                ctx.beginPath()
                ctx.moveTo(dotPoints[0].x + 1, dotPoints[0].y + 2)
                for(var s = 1; s < dotPoints.length; s++) {
                    ctx.lineTo(dotPoints[s].x + 1, dotPoints[s].y + 2)
                }
                ctx.stroke()

                // Main line
                ctx.strokeStyle = "#2d2d44"
                ctx.lineWidth = 2
                ctx.lineJoin = "round"
                ctx.lineCap = "round"
                ctx.beginPath()
                ctx.moveTo(dotPoints[0].x, dotPoints[0].y)
                for(var j = 1; j < dotPoints.length; j++) {
                    ctx.lineTo(dotPoints[j].x, dotPoints[j].y)
                }
                ctx.stroke()
            }

            // Draw dots with outer ring
            for(var k = 0; k < dotPoints.length; k++) {
                var isFirst = (k === 0)
                var isLast = (k === dotPoints.length - 1)

                // Outer glow
                ctx.fillStyle = "rgba(124, 111, 247, 0.2)"
                ctx.beginPath()
                ctx.arc(dotPoints[k].x, dotPoints[k].y, 10, 0, 2 * Math.PI)
                ctx.fill()

                // Outer ring
                ctx.fillStyle = isFirst ? "#7c6ff7" : (isLast ? "#e74c5e" : "#2d2d44")
                ctx.beginPath()
                ctx.arc(dotPoints[k].x, dotPoints[k].y, 7, 0, 2 * Math.PI)
                ctx.fill()

                // Inner dot
                ctx.fillStyle = "#ffffff"
                ctx.beginPath()
                ctx.arc(dotPoints[k].x, dotPoints[k].y, 3.5, 0, 2 * Math.PI)
                ctx.fill()

                // Label
                ctx.fillStyle = "#2d2d44"
                ctx.font = "bold 10px sans-serif"
                ctx.textAlign = "center"
                ctx.fillText((k + 1).toString(), dotPoints[k].x, dotPoints[k].y - 14)
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            cursorShape: Qt.CrossCursor

            onClicked: {
                connectDotsCanvas.dotPoints.push({x: mouseX, y: mouseY})
                canvas.requestPaint()

                var xCoords = []
                var yCoords = []

                for(var i = 0; i < connectDotsCanvas.dotPoints.length; i++) {
                    xCoords.push(connectDotsCanvas.dotPoints[i].x)
                    yCoords.push(connectDotsCanvas.dotPoints[i].y)
                }

                backend.sendDotPoints(xCoords, yCoords)
            }
        }
    }

    function clearDrawing() {
        dotPoints = []
        canvas.requestPaint()
    }
}
