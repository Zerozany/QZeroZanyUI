pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Popup {
    id: root
    x: root.selfX
    y: root.selfY
    width: root.selfWidth
    height: root.selfHeight
    background: Rectangle {
        color: root.elementColor
        radius: root.elementRadius
    }

    readonly property int selfX: (ComponentMethod.findTopLevelWindow(parent).width - root.width) * 0.5
    readonly property int selfY: (ComponentMethod.findTopLevelWindow(parent).height - root.height) * 0.5
    readonly property int selfWidth: ComponentConf.landScape ? ComponentMethod.findTopLevelWindow(parent).width * 0.6 : ComponentMethod.findTopLevelWindow(parent).width * 0.7
    readonly property int selfHeight: ComponentConf.landScape ? ComponentMethod.findTopLevelWindow(parent).height * 0.6 : ComponentMethod.findTopLevelWindow(parent).height * 0.4
    readonly property int elementRadius: ElementStyle.elementRadius * 20
    readonly property int elementSpacing: ElementStyle.elementSpacing
    readonly property string elementColor: ThemeManager.currentTheme["elementColor"]
    readonly property int visibleItemCount: 7
    readonly property int flickDeceleration: 1000
    readonly property int year: yearTumbler.currentIndex + 1960
    readonly property int month: monthTumbler.currentIndex + 1
    readonly property int day: dayTumbler.currentIndex + 1

    RowLayout {
        anchors.fill: parent

        Tumbler {
            id: yearTumbler
            visibleItemCount: root.visibleItemCount
            flickDeceleration: root.flickDeceleration
            wrap: true
            Layout.preferredHeight: root.height * 0.5
            Layout.preferredWidth: root.width * 0.2
            Layout.alignment: Qt.AlignCenter

            model: {
                var arr = [];
                for (var _year = 1960; _year <= new Date().getFullYear(); _year++) {
                    arr.push(_year);
                }
                return arr;
            }

            delegate: Text {
                required property var modelData
                readonly property bool isCurrent: root.year === modelData
                text: modelData
                font.pixelSize: isCurrent ? 25 : 22
                font.bold: isCurrent
                opacity: isCurrent ? 1.0 : 0.5
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Tumbler {
            id: monthTumbler
            visibleItemCount: root.visibleItemCount
            flickDeceleration: root.flickDeceleration
            wrap: true
            Layout.preferredHeight: root.height * 0.5
            Layout.preferredWidth: root.width * 0.2
            Layout.alignment: Qt.AlignCenter

            model: {
                var arr = [];
                for (var _month = 1; _month <= 12; _month++) {
                    arr.push(_month);
                }
                return arr;
            }

            delegate: Text {
                required property var modelData
                readonly property bool isCurrent: root.month === modelData
                text: modelData
                font.pixelSize: isCurrent ? 25 : 22
                font.bold: isCurrent
                opacity: isCurrent ? 1.0 : 0.5
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Tumbler {
            id: dayTumbler
            visibleItemCount: root.visibleItemCount
            flickDeceleration: root.flickDeceleration
            wrap: true
            Layout.preferredHeight: root.height * 0.5
            Layout.preferredWidth: root.width * 0.2
            Layout.alignment: Qt.AlignCenter

            model: {
                var arr = [];
                for (var _day = 1; _day <= new Date(root.year, root.month, 0).getDate(); _day++) {
                    arr.push(_day);
                }
                return arr;
            }

            delegate: Text {
                required property var modelData
                readonly property bool isCurrent: root.day === modelData
                text: modelData
                font.pixelSize: isCurrent ? 25 : 22
                font.bold: isCurrent
                opacity: isCurrent ? 1.0 : 0.5
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
