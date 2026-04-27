import QtQuick
import QtQuick.Controls


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Contacts")
    color: "#1a1a1a"

    Column
    {
        id:main
        anchors.fill: parent
        anchors.margins: 25
        spacing: 5

        TextField
        {
            id:searchBar
            width: parent.width
            height: parent.height/12
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"

            background: Rectangle {
                anchors.fill: parent
                radius: 20
                border.color: "#3a3a3a"
                border.width: 1
                color: "#2a2a2a"

                Text {
                    text: " =   Search contacts"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 12
                    color: "#888888"
                }
            }
        }

        ContactCard { contactName: contact.contacts[0] }
        ContactCard { contactName: contact.contacts[1] }
        ContactCard { contactName: contact.contacts[2] }
        ContactCard { contactName: contact.contacts[3] }
        ContactCard { contactName: contact.contacts[4] }
        ContactCard { contactName: contact.contacts[5] }
        ContactCard { contactName: contact.contacts[6] }
        ContactCard { contactName: contact.contacts[7] }
        ContactCard { contactName: contact.contacts[8] }
        ContactCard { contactName: contact.contacts[9] }

    }
}







