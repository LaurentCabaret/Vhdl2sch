#ifndef INPUT_H
#define INPUT_H

#include "ios.h"

class input : public IOs
{
public:
    input();
    input(QString name);
    void  setSentence();
};

#endif // INPUT_H
