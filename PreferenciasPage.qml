import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Controls.Material

Item {
    id: preferenciasPage
    signal irARecomendados()
    width: 400
    height: 600

    // MODELO de categorías con íconos emoji
    ListModel {
        id: categoriasModel

        ListElement { nombre: "Electrónica"; icono: "📱" }
        ListElement { nombre: "Juegos"; icono: "🎮" }
    }

    // MODELO dinámico de marcas
    ListModel {
        id: marcasModel
    }

    // MODELO para mostrar preferencias guardadas
    ListModel {
        id: preferenciasGuardadasModel
    }

    Rectangle {
        anchors.centerIn: parent
        width: 340
        height: 560
        radius: 20
        color: "#ffffff"
        border.color: "#dddddd"

        Column {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 14

            Text {
                text: "PREFERENCIAS"
                font.pixelSize: 22
                font.bold: true
                color: "#000000"
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                text: "Categoría"
                font.pixelSize: 16
                font.bold: true
                color: "#222"
            }

            ComboBox {
                id: categoriaCombo
                width: parent.width
                model: categoriasModel
                textRole: "nombre"

                delegate: ItemDelegate {
                    width: categoriaCombo.width
                    contentItem: Row {
                        spacing: 10
                        Text { text: model.icono }
                        Text { text: model.nombre }
                    }
                }

                onCurrentTextChanged: {
                    marcasModel.clear()
                    const nuevasMarcas = Backend.ObtenerMarcasporCategoria(currentText)
                    for (let i = 0; i < nuevasMarcas.length; i++) {
                        marcasModel.append({ nombre: nuevasMarcas[i], seleccionado: false })
                    }
                }
            }

            Text {
                text: "Marca"
                font.pixelSize: 16
                font.bold: true
                color: "#222"
            }

            Column {
                width: parent.width
                spacing: 6

                Repeater {
                    model: marcasModel

                    delegate: Rectangle {
                        width: parent.width
                        height: 40
                        radius: 20
                        border.color: "#cccccc"
                        color: seleccionado ? "#e60012" : "#f1f1f1"

                        Row {
                            spacing: 10
                            anchors.centerIn: parent

                            Text {
                                text: nombre
                                font.pixelSize: 14
                                color: seleccionado ? "white" : "black"
                            }
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                marcasModel.setProperty(index, "seleccionado", !seleccionado)
                            }
                        }
                    }
                }
            }

            Button {
                text: "Guardar preferencia"
                width: parent.width
                background: Rectangle {
                    color: "#007acc"
                    radius: 10
                }

                onClicked: {
                    if (categoriaCombo.currentText !== "") {
                        const marcasSeleccionadas = []
                        for (let i = 0; i < marcasModel.count; ++i) {
                            if (marcasModel.get(i).seleccionado) {
                                marcasSeleccionadas.push(marcasModel.get(i).nombre)
                                preferenciasGuardadasModel.append({
                                    categoria: categoriaCombo.currentText,
                                    marca: marcasModel.get(i).nombre
                                })
                            }
                        }

                        if (marcasSeleccionadas.length > 0) {
                            Backend.GuardarPreferencia([categoriaCombo.currentText], marcasSeleccionadas)
                            console.log("✅ Preferencias guardadas:", categoriaCombo.currentText, marcasSeleccionadas)

                            const loginComponent = Qt.createComponent("LoginPage.qml")
                            if (loginComponent.status === Component.Ready) {
                                const loginPage = loginComponent.createObject(preferenciasPage)
                                if (loginPage !== null) {
                                    loginPage.loginExitoso.connect(() => {
                                        var root = preferenciasPage
                                        while (root && !root.push) root = root.parent
                                        if (root) root.push(Qt.resolvedUrl("ProductosRecomendados.qml"))
                                    })
                                    var root = preferenciasPage
                                    while (root && !root.push) root = root.parent
                                    if (root) root.push(loginPage)
                                } else {
                                    console.error("❌ No se pudo crear LoginPage")
                                }
                            } else {
                                console.error("❌ Error al cargar el componente LoginPage.qml")
                            }
                        } else {
                            console.log("⚠️ No hay marcas seleccionadas.")
                        }
                    }
                }
            }

            Text {
                text: "📋 Preferencias guardadas:"
                font.pixelSize: 16
                color: "#444"
                visible: preferenciasGuardadasModel.count > 0
            }

            ListView {
                width: parent.width
                height: 120
                model: preferenciasGuardadasModel
                clip: true

                delegate: Rectangle {
                    width: parent.width
                    height: 36
                    radius: 8
                    color: "#f9f9f9"
                    border.color: "#dddddd"

                    Row {
                        spacing: 8
                        anchors.centerIn: parent

                        Text {
                            text: "⭐ " + categoria + " - " + marca
                            font.pixelSize: 14
                            color: "#333"
                        }
                    }
                }
            }

            Button {
                text: "Volver"
                width: parent.width
                background: Rectangle {
                    color: "#999999"
                    radius: 10
                }
                onClicked: Qt.quit()
            }
        }
    }
}
