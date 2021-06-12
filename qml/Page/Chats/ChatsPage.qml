import QtQuick 2.0
import Felgo 3.0

import Common 1.0

ListPage {

    model: chatsController.chatItemList

    listView.showSearch: true

    delegate: Item {
        anchors.left: parent.left
        anchors.right: parent.right
        height: dp(40)
        Rectangle {
            id: imageWrap
            anchors.left: parent.left
            anchors.leftMargin: dp(2)
            anchors.verticalCenter: parent.verticalCenter
            width: dp(32)
            height: width
            border.width: dp(1)
            border.color: "gray"
            radius: dp(2)
            Image {
                anchors.fill: parent
                anchors.margins: dp(2)
                source: modelData.avatar
            }
            Rectangle {
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.rightMargin: -width / 2
                anchors.topMargin: -width / 3
                width: dp(12)
                height: width
                radius: width / 2
                color: "red"
                visible: modelData.unreadCount > 0
                AppText {
                    anchors.fill: parent
                    text: modelData.unreadCount
                    font.pixelSize: sp(8)
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
        Text {
            id: groupName
            anchors.left: imageWrap.right
            anchors.leftMargin: dp(5)
            anchors.top: imageWrap.top
            text: modelData.groupName
            font.pixelSize: dp(14)
        }
        Text {
            id: message
            anchors.left: groupName.left
            anchors.bottom: imageWrap.bottom
            text: modelData.message
            font.pixelSize: dp(10)
            color: "gray"
        }
        Rectangle {
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            width: parent.width - dp(40)
            height: dp(1)
            color: WColor.grayLine
        }
    }
}
