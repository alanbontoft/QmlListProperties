import QtQuick 2.0
import QtQuick.Controls 2.0

Label {
    property int index
    text: TheParty.guests[index].name + " : " + TheParty.guests[index].shoeSize}
