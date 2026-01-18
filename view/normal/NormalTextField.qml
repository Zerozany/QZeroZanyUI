pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Templates as T
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl
import QZeroZanyUI

T.TextField {
    id: root
    leftPadding: root.height * 0.5 + root.elementMargins * 2
    rightPadding: root.height + root.elementMargins * 2
    color: enabled && activeFocus ? root.textColor : Material.hintTextColor
    // selectionColor: Material.accentColor
    // selectedTextColor: Material.primaryHighlightedTextColor
    placeholderTextColor: enabled && activeFocus ? root.textColor : Material.hintTextColor
    verticalAlignment: TextInput.AlignVCenter
    Material.containerStyle: Material.Outlined
    cursorDelegate: CursorDelegate {
        color: root.borderColor
    }

    property url source: ""
    property url passwordSource: ""
    property url pressedPasswordSource: ""
    property url clearSource: ""
    property color borderColor: "#7FFFD4"

    readonly property string textColor: ThemeManager.currentTheme["textColor"]
    readonly property int elementMargins: ElementStyle.elementMargins * 2

    Image {
        source: "qrc:/qt/qml/SonixBeautyStudio/view/resource/setting.png"
        width: root.height * 0.5
        height: root.height * 0.5
        anchors.left: parent.left
        anchors.leftMargin: root.elementMargins
        anchors.verticalCenter: parent.verticalCenter
        verticalAlignment: Text.AlignVCenter
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: clearImage
        source: "qrc:/qt/qml/SonixBeautyStudio/view/resource/clearInput.png"
        width: root.height * 0.5
        height: root.height * 0.5
        anchors.right: passwordImage.left
        anchors.rightMargin: root.elementMargins * 0.5
        anchors.verticalCenter: parent.verticalCenter
        verticalAlignment: Text.AlignVCenter
        fillMode: Image.Pad

        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.clear();
            }
        }
    }

    Image {
        id: passwordImage
        source: "qrc:/qt/qml/SonixBeautyStudio/view/resource/setting.png"
        width: root.height * 0.5
        height: root.height * 0.5
        anchors.right: parent.right
        anchors.rightMargin: root.elementMargins
        anchors.verticalCenter: parent.verticalCenter
        fillMode: Image.PreserveAspectFit
    }

    FloatingPlaceholderText {
        id: placeholder
        width: root.width - (root.leftPadding + root.rightPadding)
        text: root.placeholderText
        font: root.font
        color: root.placeholderTextColor
        elide: Text.ElideRight
        controlHasActiveFocus: root.activeFocus
        controlHasText: root.length > 0
        controlImplicitBackgroundHeight: root.implicitBackgroundHeight
        controlHeight: root.height
        leftPadding: root.leftPadding
        floatingLeftPadding: root.Material.textFieldHorizontalPadding
    }

    background: MaterialTextContainer {
        implicitWidth: root.height
        implicitHeight: root.Material.textFieldHeight
        filled: root.Material.containerStyle === Material.Filled
        fillColor: root.Material.textFieldFilledContainerColor
        outlineColor: (enabled && root.hovered) ? root.Material.primaryTextColor : root.Material.hintTextColor
        focusedOutlineColor: root.borderColor
        placeholderTextWidth: Math.min(placeholder.width, placeholder.implicitWidth) * placeholder.scale
        placeholderTextHAlign: root.effectiveHorizontalAlignment
        controlHasActiveFocus: root.activeFocus
        controlHasText: root.length > 0
        placeholderHasText: placeholder.text.length > 0
        horizontalPadding: root.Material.textFieldHorizontalPadding
    }
}
