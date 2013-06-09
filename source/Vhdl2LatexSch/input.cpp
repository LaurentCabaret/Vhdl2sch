#include "input.h"

input::input()
{
    lenght = 1.2;
    type = WIRE;
}

input::input(QString name) {

    this->ioLabel = name;

}



void input::setSentence()
{
    if (type == BUS) {
        ioSentence = QString("\\node[right] (") + ioLabel + QString(") at (")
                + QString::number(posx,'g',2) + QString(",") + QString::number(posy,'g',2)
                + QString(") {") + ioLabel +QString("};\n");
        ioSentence += "\\draw[bus={8}] (" + QString::number(posx-lenght,'g',2) + ","
                    + QString::number(posy,'g',2) + ") -- (" + ioLabel  + ");";
    }
    if (type == WIRE) {
        ioSentence = QString("\\node[right] (") + ioLabel + QString(") at (")
                + QString::number(posx,'g',2) + QString(",") + QString::number(posy,'g',2)
                + QString(") {") + ioLabel +QString("};\n");
        ioSentence += QString("\\draw[wire] (") + QString::number(posx-lenght,'g',2) +","
                    + QString::number(posy,'g',2) + ") -- (" + ioLabel  + ");";
    }

    if (type == CLK) {
        ioSentence = QString("\\node[right] (") + ioLabel + QString(") at (")
                + QString::number(posx,'g',2) + QString(",") + QString::number(posy,'g',2)
                + QString(") {") + "  " + ioLabel +QString("};\n");
        ioSentence += QString("\\draw[ckwire] (") + QString::number(posx-lenght,'g',2) +","
                    + QString::number(posy,'g',2) + ") -- (" + ioLabel  + ");";
    }
}
