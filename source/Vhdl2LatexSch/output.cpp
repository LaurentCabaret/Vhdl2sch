#include "output.h"


output::output()
{
        size = 1;
        type = WIRE;
        lenght = 1.2;
}


void output::setSentence()
{
    if (type == BUS) {
        ioSentence = QString("\\node[left] (") + ioLabel + QString(") at (")
                            + QString::number(posx,'g',2) + QString(",") + QString::number(posy,'g',2)
                            + QString(") {") + ioLabel +QString("};\n");
            ioSentence += "\\draw[bus={" + QString::number(size) + "}] (" + ioLabel + ") -- (" + QString::number(posx+lenght,'g',2) + "," + QString::number(posy,'g',2) + ");\n";

    }
    if (type == WIRE) {
        ioSentence = QString("\\node[left] (") + ioLabel + QString(") at (")
                            + QString::number(posx,'g',2) + QString(",") + QString::number(posy,'g',2)
                            + QString(") {") + ioLabel +QString("};\n");
            ioSentence += "\\draw[wire] (" + ioLabel + ") -- (" + QString::number(posx+lenght,'g',2) + "," + QString::number(posy,'g',2) + ");\n";

    }
}
