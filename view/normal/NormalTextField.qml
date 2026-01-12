import QtQuick
import QtQuick.Templates as T
import QtQuick.Controls.Material
import QtQuick.Controls.Material.impl

T.TextField {
    id: root

    readonly property string elementColor: ThemeManager.currentTheme["elementColor"]

    background: Rectangle {
        border.color: "transparent"
        color: "transparent"
    }

    FloatingPlaceholderText {
        anchors.fill: parent
        text: root.placeholderText
        color: root.placeholderTextColor
        controlHasActiveFocus: root.activeFocus
        controlHasText: root.text.length > 0
        controlHeight: root.height
        controlImplicitBackgroundHeight: root.implicitBackgroundHeight
        elide: Text.ElideRight
        font: root.font
        filled: root.Material.containerStyle === Material.Filled
        renderType: root.renderType
        verticalPadding: root.Material.textFieldVerticalPadding
    }
}
