// WelcomePage.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Item {
    id: welcomePage
    width: 400
    height: 560

    signal irARegistro()
    signal irALogin()

    Rectangle {
        anchors.fill: parent
        color: "#ffffff"
        border.color: "#dddddd"
        radius: 20
        anchors.margins: 20

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 24

            Text {
                text: "🎉 ¡Bienvenido!"
                font.pixelSize: 26
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                Layout.alignment: Qt.AlignHCenter
            }

            Text {
                text: "Selecciona una opción para comenzar"
                font.pixelSize: 16
                color: "#555"
                horizontalAlignment: Text.AlignHCenter
                Layout.alignment: Qt.AlignHCenter
            }

            Button {
                text: "Registrarse"
                Layout.fillWidth: true
                onClicked: irARegistro()
            }

            Button {
                text: "Iniciar Sesión"
                Layout.fillWidth: true
                onClicked: irALogin()
            }
        }
    }
}
