import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: registroPage
    width: 400
    height: 560

    signal registroExitoso()
    property string mensajeResultado: ""
    property bool exitoRegistro: false

    Dialog {
        id: mensajeDialogo
        modal: true
        title: exitoRegistro ? "✅ Registro exitoso" : "❌ Error de registro"
        standardButtons: Dialog.Ok

        onAccepted: {
            if (exitoRegistro)
                registroExitoso()
        }

        contentItem: Text {
            text: mensajeResultado
            wrapMode: Text.Wrap
            font.pixelSize: 14
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
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
                text: "Registro de Usuario"
                font.pixelSize: 20
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
            }

            TextField {
                id: nombreField
                placeholderText: "Nombre"
                Layout.fillWidth: true
            }

            TextField {
                id: apellidoField
                placeholderText: "Apellido"
                Layout.fillWidth: true
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

            TextField {
                id: confirmarField
                placeholderText: "Confirmar contraseña"
                echoMode: TextInput.Password
                Layout.fillWidth: true
            }

            Button {
                text: "Registrarse"
                Layout.fillWidth: true
                onClicked: {
                    if (nombreField.text === "" || apellidoField.text === "" || usuarioField.text === "" ||
                        contrasenaField.text === "" || confirmarField.text === "") {
                        mensajeResultado = "⚠️ Todos los campos son obligatorios"
                        exitoRegistro = false
                        mensajeDialogo.open()
                        return
                    }

                    if (contrasenaField.text !== confirmarField.text) {
                        mensajeResultado = "❌ Las contraseñas no coinciden"
                        exitoRegistro = false
                        mensajeDialogo.open()
                        return
                    }

                    const resultado = Backend.RegistrarUsuarioCompleto(
                        nombreField.text,
                        apellidoField.text,
                        usuarioField.text,
                        contrasenaField.text
                    )

                    if (resultado === "OK") {
                        mensajeResultado = "✅ Usuario registrado correctamente\nBienvenido, " +
                            Backend.obtenerNombreUsuarioActual() + "\nTu ID es: " +
                            Backend.ObtenerIDUser()
                        exitoRegistro = true
                    } else {
                        mensajeResultado = resultado
                        exitoRegistro = false
                    }

                    mensajeDialogo.open()
                }
            }
        }
    }
}


