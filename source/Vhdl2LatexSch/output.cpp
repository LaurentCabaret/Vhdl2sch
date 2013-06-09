#include "output.h"


output::output()
{
        type = WIRE;
            lenght = 1.2;
}


void output::setSentence()
{
    if (type == BUS) {
        ioSentence = QString("\\node[left] (") + ioLabel + QString(") at (")
                            + QString::number(posx) + QString(",") + QString::number(posy)
                            + QString(") {") + ioLabel +QString("};\n");
            ioSentence += "\\draw[bus={2}] (" + ioLabel + ") -- (" + QString::number(posx+lenght) + "," + QString::number(posy) + ");\n";

    }
    if (type == WIRE) {
        ioSentence = QString("\\node[left] (") + ioLabel + QString(") at (")
                            + QString::number(posx) + QString(",") + QString::number(posy)
                            + QString(") {") + ioLabel +QString("};\n");
            ioSentence += "\\draw[wire] (" + ioLabel + ") -- (" + QString::number(posx+lenght) + "," + QString::number(posy) + ");\n";

    }
}
