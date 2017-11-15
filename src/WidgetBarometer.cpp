
#include "WidgetBarometer.h"


WidgetBarometer::WidgetBarometer(uint8_t ucItem)
{
    _Item = ucItem;
    memset(pDataPressureTopic,0,sizeof(pDataPressureTopic));
    memset(pDataAltitudeTopic,0,sizeof(pDataAltitudeTopic));

    sprintf(pDataPressureTopic,"channel/barometer_%d/data/pressure",_Item);
    sprintf(pDataAltitudeTopic,"channel/barometer_%d/data/altitude",_Item);
}

WidgetBarometer::~WidgetBarometer()
{
    
}

void WidgetBarometer::begin(void (*UserCallBack)(void))
{

}

void WidgetBarometer::displayPressure(float fPressure)
{
	IntoRobot.publish(pDataPressureTopic,fPressure);
}


void WidgetBarometer::displayAltitude(float fAltitude)
{
	IntoRobot.publish(pDataAltitudeTopic,fAltitude);
}







