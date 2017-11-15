#ifndef WIDGET_BAROMETER_H_
#define WIDGET_BAROMETER_H_

#include "application.h"


class WidgetBarometer
{
public:
    WidgetBarometer(uint8_t ucItem = 0);
    ~WidgetBarometer();
    void begin(void (*UserCallBack)(void) = NULL);
    void displayPressure(float fPressure);
    void displayAltitude(float fAltitude);

    
private:
    char pDataPressureTopic[64];
    char pDataAltitudeTopic[64];
    uint8_t _Item=0;         
};

#endif
