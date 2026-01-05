import QtQuick
import QtQuick.Controls

TextField {
    id: root
    placeholderText: root.placeText
    placeholderTextColor: "gray"
    font.letterSpacing: root.elementSpacing * 0.5
    font.bold: root.fontBold
    leftPadding: root.height - root.elementMargins
    rightPadding: root.height - root.elementMargins
    background: Rectangle {
        anchors.fill: root
        color: root.elementColor
        border.color: root.activeFocus ? "black" : "#DCDCDC"
        radius: root.elementRadius

        Image {
            source: root.source
            anchors.left: parent.left
            anchors.leftMargin: root.elementMargins
            anchors.verticalCenter: parent.verticalCenter
            width: root.height * 0.5
            height: root.height * 0.5
            fillMode: Image.PreserveAspectFit
        }

        Image {
            source: root.otherSource
            anchors.right: parent.right
            anchors.rightMargin: root.elementMargins
            anchors.verticalCenter: parent.verticalCenter
            width: root.height * 0.5
            height: root.height * 0.5
            fillMode: Image.PreserveAspectFit
        }
    }

    property var text: null
    property var placeText: null
    property url source: ""
    property url otherSource: ""
    property bool fontBold: false

    readonly property string elementColor: ThemeManager.currentTheme["elementColor"]
    readonly property string textColor: ThemeManager.currentTheme["textColor"]
    readonly property int elementRadius: ElementStyle.elementRadius * 2
    readonly property int elementSpacing: ElementStyle.elementSpacing
    readonly property int elementMargins: ElementStyle.elementMargins * 2
    readonly property string fontFamily: ThemeFont.fontFamily

    MouseArea {
        parent: Overlay.overlay
        anchors.fill: parent
        enabled: root.activeFocus
        propagateComposedEvents: true
        onClicked: function (_mouse) {
            var localPos = root.mapFromItem(parent, _mouse.x, _mouse.y);
            if (localPos.x < 0 || localPos.y < 0 || localPos.x > root.width || localPos.y > root.height) {
                root.focus = false;
            }
        }
    }
}
