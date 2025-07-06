import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

Item {
    width: 400
    height: 600

    ListModel {
        id: productosModel
    }

    // Cargar productos recomendados del backend
    Component.onCompleted: {
        const productos = Backend.ObtenerProductosPreferidos()
        for (let i = 0; i < productos.length; i++) {
            productosModel.append(productos[i])
        }
    }

    Rectangle {
        anchors.centerIn: parent
        width: 360
        height: 580
        radius: 20
        color: "#ffffff"
        border.color: "#dddddd"

        Column {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 10

            Text {
                text: "🛒 Productos Recomendados"
                font.pixelSize: 20
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            ScrollView {
                width: parent.width
                height: 470

                Column {
                    spacing: 12
                    width: parent.width

                    Repeater {
                        model: productosModel

                        delegate: Rectangle {
                            width: parent.width
                            height: 100
                            radius: 12
                            border.color: "#cccccc"
                            color: "#f7f7f7"

                            Row {
                                anchors.fill: parent
                                anchors.margins: 10
                                spacing: 12

                                // Imagen del producto
                                Rectangle {
                                    width: 80
                                    height: 80
                                    radius: 8
                                    color: "#dddddd"
                                    Text {
                                        anchors.centerIn: parent
                                        text: "📦"
                                        font.pixelSize: 30
                                    }
                                }

                                // Detalles del producto
                                Column {
                                    spacing: 4
                                    width: parent.width - 120

                                    Text {
                                        text: descripcion
                                        font.pixelSize: 16
                                        font.bold: true
                                        color: "#222"
                                        elide: Text.ElideRight
                                    }

                                    Text {
                                        text: "💰 $" + precio.toFixed(2) + "     🆔 ID: " + id
                                        font.pixelSize: 14
                                        color: "#333"
                                    }

                                    Text {
                                        text: "📁 " + categoria + " - " + marca
                                        font.pixelSize: 13
                                        color: "#666"
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Button {
                text: "← Volver a preferencias"
                width: parent.width
                background: Rectangle {
                    color: "#888888"
                    radius: 10
                }
                onClicked: {
                    // Buscar el StackView más cercano y hacer pop
                    var current = parent
                    while (current && !current.pop) current = current.parent
                    if (current) current.pop()
                }
            }

            }
        }
    }


