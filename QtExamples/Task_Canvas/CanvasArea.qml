import QtQuick

Rectangle {
    id: root
    color: "#ffffff"

    property var toolType: 1
    property var freeDrawPoints: []
    property var dotPoints: []

    Canvas {
        id: drawingCanvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d")
            ctx.fillStyle = "#ffffff"
            ctx.fillRect(0, 0, width, height)

            if(toolType === 1) {
                // Free Draw
                ctx.strokeStyle = "#000000"
                ctx.lineWidth = 2
                ctx.lineJoin = "round"
                ctx.lineCap = "round"
                
                if(freeDrawPoints.length > 0) {
                    ctx.beginPath()
                    ctx.moveTo(freeDrawPoints[0].x, freeDrawPoints[0].y)

                    for(var i = 1; i < freeDrawPoints.length; i++) {
                        ctx.lineTo(freeDrawPoints[i].x, freeDrawPoints[i].y)
                    }
                    ctx.stroke()
                }
            }
            else if(toolType === 2) {
                // Connect Dots
                if(dotPoints.length >= 2) {
                    ctx.strokeStyle = "#000000"
                    ctx.lineWidth = 2
                    ctx.beginPath()
                    ctx.moveTo(dotPoints[0].x, dotPoints[0].y)

                    for(var j = 1; j < dotPoints.length; j++) {
                        ctx.lineTo(dotPoints[j].x, dotPoints[j].y)
                    }
                    ctx.stroke()
                }

                // Draw dots
                ctx.fillStyle = "#ff0000"
                for(var k = 0; k < dotPoints.length; k++) {
                    ctx.beginPath()
                    ctx.arc(dotPoints[k].x, dotPoints[k].y, 5, 0, 2 * Math.PI)
                    ctx.fill()
                }
            }
        }

        MouseArea {
            anchors.fill: parent

            onPressed: function(mouse) {
                if(toolType === 1) {
                    root.freeDrawPoints = []
                }
            }

            onPositionChanged: function(mouse) {
                if(toolType === 1 && pressed) {
                    root.freeDrawPoints.push({x: mouse.x, y: mouse.y})
                    drawingCanvas.requestPaint()
                }
            }

            onReleased: function(mouse) {
                if(toolType === 1 && root.freeDrawPoints.length > 0) {
                    try {
                        backend.sendFreeDraw(root.freeDrawPoints)
                    } catch(e) {
                        console.log("Error sending free draw:", e)
                    }
                }
            }

            onClicked: function(mouse) {
                if(toolType === 2) {
                    root.dotPoints.push({x: mouse.x, y: mouse.y})
                    drawingCanvas.requestPaint()
                    try {
                        backend.sendDotPoints(root.dotPoints)
                    } catch(e) {
                        console.log("Error sending dots:", e)
                    }
                }
            }
        }
    }

    function clearDrawing() {
        root.freeDrawPoints = []
        root.dotPoints = []
        drawingCanvas.requestPaint()
    }
}
