import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

ApplicationWindow {
    id: appWindow
    width: 400
    height: 560
    visible: true
    title: "Sistema de Registro"
    Material.theme: Material.Light
    Material.accent: Material.Blue

    StackView {
        id: stack
        anchors.fill: parent

        initialItem: Bienvenida {
            onIrARegistro: {
                const registroPage = Qt.createComponent("RegistroPage.qml").createObject(stack)
                registroPage.registroExitoso.connect(() => {
                    const prefPage = Qt.createComponent("PreferenciasPage.qml").createObject(stack)
                    prefPage.irARecomendados.connect(() => {
                        const loginPage = Qt.createComponent("LoginPage.qml").createObject(stack)
                        loginPage.loginExitoso.connect(() => {
                            stack.push(Qt.resolvedUrl("ProductosRecomendados.qml"))
                        })
                        stack.push(loginPage)
                    })
                    stack.push(prefPage)
                })
                stack.push(registroPage)
            }

            onIrALogin: {
                const loginPage = Qt.createComponent("LoginPage.qml").createObject(stack)
                loginPage.loginExitoso.connect(() => {
                    stack.push(Qt.resolvedUrl("ProductosRecomendados.qml"))
                })
                stack.push(loginPage)
            }
        }
    }
}
