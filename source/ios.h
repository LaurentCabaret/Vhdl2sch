#ifndef IOS_H
#define IOS_H
#include "QString"

#define BUS     0
#define WIRE    1
#define CLK     2
class IOs
{
public:
    IOs();    
    QString ioLabel;
    QString ioSentence;
    QString getNodeSentence();
    QString getDrawSentence();
    void setPosx(int );
    void setPosy(int );
    float posx,posy;
    char type;
    QString size;
    void reconfigure(float posx);
    float lenght;

};

#endif // IOS_H
