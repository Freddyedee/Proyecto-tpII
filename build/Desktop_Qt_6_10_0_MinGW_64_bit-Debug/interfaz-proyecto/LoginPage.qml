import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Item {
    id: loginPage
    width: 400
    height: 560

    signal loginExitoso()

    property string mensaje: ""
    property bool exito: false

    Dialog {
        id: dialogoLogin
        title: exito ? "✅ Éxito" : "❌ Error"
        standardButtons: Dialog.Ok

        contentItem: Text {
            text: mensaje
            wrapMode: Text.Wrap
            font.pixelSize: 14
            horizontalAlignment: Text.AlignHCenter
        }

        onAccepted: {
            if (exito)
                loginExitoso()
        }
    }

    Rectangle {
        anchors.fill: parent
        anchors.margins: 20
        color: "transparent"

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 12

            Text {
                text: "Iniciar Sesión"
                font.pixelSize: 22
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
            }

            TextField {
                id: usuarioField
                placeholderText: "Nombre de usuario"
                Layout.fillWidth: true
            }

            TextField {
                id: contrasenaField
                placeholderText: "Contraseña"
                echoMode: TextInput.Password
                Layout.fillWidth: true
            }

            Button {
                text: "Ingresar"
                Layout.fillWidth: true
                onClicked: {
                    if (usuarioField.text === "" || contrasenaField.text === "") {
                        mensaje = "⚠️ Todos los campos son obligatorios"
                        exito = false
                        dialogoLogin.open()
                        return
                    }

                    const correcto = Backend.iniciarSesion(usuarioField.text, contrasenaField.text)
                    if (correcto) {
                        mensaje = "✅ Sesión iniciada\nBienvenido, " + Backend.obtenerNombreUsuarioActual()
                        exito = true
                    } else {
                        mensaje = "❌ Usuario o contraseña incorrectos"
                        exito = false
                    }

                    dialogoLogin.open()
                }
            }

            Button {
                text: "Cancelar"
                Layout.fillWidth: true
                onClicked: {
                    var root = loginPage
                    while (root && !root.pop) root = root.parent
                    if (root) root.pop()
                }
            }
        }
    }
}


