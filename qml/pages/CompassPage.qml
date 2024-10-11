import QtQuick 2.0
import Sailfish.Silica 1.0



Page {
    id: page

    //allowedOrientations: Orientation.All

    SilicaFlickable {

        anchors.fill: parent

/*        PullDownMenu {
            MenuItem {
                text: qsTr("Show Page 2")
                onClicked: pageStack.animatorPush(Qt.resolvedUrl("SecondPage.qml"))
            }
        } */

        Image{
            id: jungleImage
            source: "qrc:/qml/png/Jungle2.png"
            width: parent.width
            height: parent.height
            anchors.centerIn: parent
        }

        Image{
            id: title
            source: "qrc:/qml/png/AztecExplorer.png"
            width: 1000
            height: 600
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: Theme.paddingLarge
        }



        Image{
            id: compassImage
            //source: "..\png\Windrose_mit_Skala.png"
            source: "qrc:/qml/png/Windrose_mit_Skala.png"
            width: 1000
            height: 1000
            anchors.centerIn: parent
            transformOrigin: Item.Center
            rotation: compassSensor.azimuth
        }


        Image{
            id: arrow
            source: "qrc:/qml/png/RedArrow.png"
            width: 30
            height: 130
            anchors.horizontalCenter:  parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 600
        }

        Text {
            id: origAzimuthLabel
            text: qsTr("Orig. Azimuth: ") + compassSensor.orig_azimuth
            font.pointSize: 50
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter

            anchors.bottom: parent.bottom

            //anchors.bottomMargin: Theme.paddingLarge
            anchors.bottomMargin: 190
        }


        Text {
            id: correctionsLabel
            text: qsTr("Adjust (N,E,S,W): ") + compassSensor.corrections
            font.pointSize: 50
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter

            anchors.bottom: parent.bottom
            anchors.bottomMargin: 120
        }


        Text {
            id: azimuthLabel
            text: qsTr("Azimuth: ") + compassSensor.azimuth
            font.pointSize: 50
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter

            anchors.bottom: parent.bottom

            //anchors.bottomMargin: Theme.paddingLarge
            anchors.bottomMargin: 50
        }
    }

}
