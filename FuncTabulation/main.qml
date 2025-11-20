import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtCharts 2.15

Window {
    id: form
    visible: true
    width: 340
    height: 240
    title: qsTr("Табулирование функции")

    Label {
    id: label_1
    x:10
    y:10
    text: qsTr("Начальное значение")
    }
    Label {
    id: label_2
    x:10
    y:50
    text: qsTr("Шаг табулирования")
    }
    Label {
    id: label_3
    x:10
    y:90
    text: qsTr("Конечное значение")
    }
    TextField {
    id: textBox1
    x:160
    y:5
    width: 50
    height: 30
}
    TextField {
    id: textBox2
    x:160
    y:45
    width: 50
    height: 30
}
    TextField {
    id: textBox3
    x:160
    y:85
    width: 50
    height: 30
}
    Button {
            id: button_1
            width: 160
            height: 30
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 90
            anchors.left: parent.left
            anchors.leftMargin: 10
            hoverEnabled: false
            text: qsTr("Табулировать")
            contentItem: Text
            {
                text: button_1.text
                minimumPixelSize:2
                font.family: "Z003"
                font.italic: true
                font.pixelSize: 20
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                color: button_1.pressed ? "red" : "green"
            }
            onClicked:
            {
                var str = textBox1.text + " " + textBox2.text + " " + textBox3.text;
                tabi.button1_Clicked(str)
            }
        }
        Button {
           id: button_2
           width: 160
           height: 30
           anchors.bottom: parent.bottom
           anchors.bottomMargin: 50
           anchors.left: parent.left
           anchors.leftMargin: 10
           hoverEnabled: false
            text: qsTr("График")
            contentItem: Text {
                text: button_2.text
                font.family: "Z003"
                font.italic: true
                font.pixelSize: 20
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                color: button_2.pressed ? "red" : "green"
            }
            onClicked:
            {
                form.width = 800
                form.height = 450
                chart.x = 340
                chart.y = 5
                chart.width = 500
                chart.height = 400
                chart.title = "Line"
                var startV = parseFloat(textBox1.text);
                var stepV = parseFloat(textBox2.text);
                var finV = parseFloat(textBox3.text);
                xAxis.max = finV+1
                xAxis.min = startV-1
                yAxis.min = startV*3+2-1
                yAxis.max = finV*3+2+1
                var series = chart.createSeries(ChartView.SeriesTypeLine, "line",xAxis,yAxis);
                series.pointsVisible = true;
                for (var it = 0;it<10;it++) {
                    series.append(it, 3*it+2)
                }
            }
        }
        Button {
           id: button_3
           width: 160
           height: 30
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            hoverEnabled: false
            text: qsTr("Выход")
            contentItem: Text {
                text: button_3.text
                font.family: "Z003"
                font.italic: true
                font.pixelSize: 20
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                color: button_3.pressed ? "red" : "green"
            }
            onClicked: tabi.button3_Clicked()

    }
        TextArea {
            id: listBox1
            x: 220
            y:5
            width: 120
            height: parent.height
        }

        ChartView {
            id: chart
            axes: [
                ValueAxis{
                    id: xAxis
                },
                ValueAxis{
                    id: yAxis
                }
            ]
        }
        Connections {
                   target: tabi
                   function onTabDate(str)
                   {
                       listBox1.text = str
                   }
           }

}
