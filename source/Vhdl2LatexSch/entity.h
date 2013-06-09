#ifndef ENTITY_H
#define ENTITY_H

#include "QString"
#include "QList"
#include "input.h"
#include "output.h"
#include "QTextStream"

class Entity
{
public:
    Entity();
    QString name;
    unsigned int nb_inputs;
    unsigned int nb_outputs;
    float height;
    float width;
    float topmargin;
    float lenght;
    QString GetLatexPreamble();
    QString GetLatexClosure();
    QString GetLatexFull();
    QString GetTikzPreamble();
    QString GetTikzFull();
    QString GetEntityDescription();
    void CreateInput(QString label,char type);
    void CreateOutput(QString label, char type);
    QList<input> inputs;
    QList<output> outputs;
    void AdjustHeight();
    void AdjustWidth();
    void AdjustSize();
};

#endif // ENTITY_H
