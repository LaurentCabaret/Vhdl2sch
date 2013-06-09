#include "entity.h"
#include "ios.h"
#include "math.h"

Entity::Entity()
{    
    lenght = 1.2;
    topmargin = -0.9;
}

void Entity::CreateInput(QString label, char type) {
    input In1;
    In1.ioLabel = label;
    In1.posy = topmargin - inputs.size()*0.5;
    In1.type = type;
    In1.setSentence();
    inputs.append(In1);
}

void Entity::CreateOutput(QString label, char type) {
    output Pin;
    Pin.ioLabel = label;
    Pin.posx = 0;
    Pin.posy = topmargin - outputs.size()*0.5;
    Pin.type = type;
    Pin.setSentence();
    outputs.append(Pin);
}


QString Entity::GetLatexFull() {
    QString latexFull = "";

    latexFull += GetLatexPreamble();
    latexFull += GetTikzFull();
    latexFull += GetLatexClosure();

    return latexFull;
}

QString Entity::GetLatexPreamble()
{
    QString latexPreample = "";


    latexPreample += QString("\\documentclass[10pt,a4paper]{standalone}\n");
    latexPreample += QString("\\usepackage[utf8]{inputenc}\n");
    latexPreample += QString("\\usepackage{amsmath}\n");
    latexPreample += QString("\\usepackage{amsfonts}\n");
    latexPreample += QString("\\usepackage{amssymb}\n");
    latexPreample += QString("\\usepackage{tikz}\n");
    latexPreample += QString("\\usepackage{fontspec}\n");
    latexPreample += QString("\\usetikzlibrary{arrows,decorations.markings}\n");
    latexPreample += QString("\\usepackage[math-style=upright]{unicode-math}\n");
    latexPreample += QString("\\setmathfont{Asana Math} % for math symbols, can be any other OpenType math font\n");
    latexPreample += QString("\\begin{document}\n");
    latexPreample += QString("\\fontspec{Aegyptus}\n");
    return latexPreample;
}


QString Entity::GetLatexClosure()
{
    QString latexClosure = "";
    latexClosure += QString("\\end{document}");

    return latexClosure;
}


QString Entity::GetTikzFull() {
    QString tikzFull = "";
    int i = 0,j = 0;
    tikzFull += GetTikzPreamble();
    tikzFull += GetEntityDescription();
    while(i<inputs.size()) {
        inputs[i].reconfigure(-width/2.7);
        inputs[i].setSentence();
        tikzFull += inputs[i].ioSentence;
        i++;
    }
    while(j<outputs.size()) {
        outputs[j].reconfigure(0);
        outputs[j].setSentence();
        tikzFull += outputs[j].ioSentence;
        j++;
    }



    tikzFull += QString("\\end{tikzpicture}\n");

    return tikzFull;
}


QString Entity::GetTikzPreamble()
{
    QString tikzPreample = "";

    tikzPreample += QString("\\tikzset{middlearrow/.style={decoration={markings,mark= at position 0.4 with {\\arrow{#1}},},postaction={decorate}}}\n");
    tikzPreample += QString("\\tikzset{bus/.style 2 args={-triangle 45, thin,double, very thin,black!90,decoration={markings,\n");
    tikzPreample += QString("  mark=at position {0.4} with {\\arrow{|},\\node[transform shape,above] {\\footnotesize \\emph{#1}};}},postaction={decorate}}}\n");
    tikzPreample += QString("\\tikzset{wire/.style 2 args={-triangle 60},postaction={decorate}}\n");
    tikzPreample += QString("\\tikzset{ckwire/.style 2 args={-open triangle 60,shorten >=-5pt,},postaction={decorate}}\n");
    tikzPreample += QString("\\tikzset{Entity/.style 2 args={shape = rectangle,rounded corners=1pt,draw=black, thick,minimum width={1.05*#1 em},minimum height={#2 em},text centered}}\n");
    tikzPreample += QString("\\begin{tikzpicture}\n");

    return tikzPreample;
}


QString Entity::GetEntityDescription()
{
    QString entityDescription = "";
    entityDescription += QString("\\node[text depth=") + QString::number(height/3.2,'g',2) + QString("cm,anchor=north east,Entity={")  + QString::number(width,'g',2) + QString("}{") + QString::number(height,'g',2) + QString("}] (") + this->name + ") at (0,0) {" + this->name  + "};\n";
    return entityDescription ;
}


void Entity::AdjustHeight() {

    height = fmax((std::max(inputs.size(),outputs.size())+1)*1.46,5);
}

void Entity::AdjustWidth() {
    int i=0,j=0;
    int insize = 0,outsize = 0,globalsize =0, labelsize = this->name.size();
    int maxiter = std::max(inputs.size(),outputs.size());
    while(i<maxiter) {
        insize = 0;
        outsize = 0;
        if (i<inputs.size())
            insize = inputs[i].ioLabel.size();
        if (i<outputs.size())
            outsize = outputs[i].ioLabel.size();
        insize = outsize + insize;
        globalsize = std::max(globalsize,insize);
        i++;
    }

    width = (float)(globalsize)*0.5+1;// - (float)(labelsize/2);
}


void Entity::AdjustSize() {
    AdjustHeight();
    AdjustWidth();

}
