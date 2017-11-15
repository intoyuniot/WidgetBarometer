/*
************************************************************************
* 作者:  IntoRobot Team 
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
气压计：检测空气压强和海拔高度

所需器件:
1.BMP180气压计模块

接线说明:
BMP180                       核心板
1.VIN                        +3.3V
2.GND                        GND
3.SDA                        I2C(Wire组)的SDA
4.SCL                        I2C(Wire组)的SCL
说明：带有“D”的为数字管脚，带有“A”的为模拟管脚，接线时请确认核心板引脚，避免接线错误。
请注意各核心板的I2C引脚区别，避免接线错误
*/

#include <BMP180.h>
#include <WidgetBarometer.h>

// 定义BMP180对象
BMP180 pressure;
WidgetBarometer barometer = WidgetBarometer();

void setup()
{
	// 初始化
	if (pressure.begin())
	{
		SerialUSB.println("BMP180 init success");
	}
	else
	{
		// 初始化出错
		SerialUSB.println("BMP180 init fail (disconnected?)\n\n");
		while(1);// 永久暂停
	}
}

void loop()
{
	double h, a, P;
	// 获取气压值
	P = pressure.getPressure();
	// 获取海拔高度
	a = pressure.altitude(P);

	// 把传感器获得的气压值和海拔高度值传输到云平台
	barometer.displayPressure(P*100);
	barometer.displayAltitude(a);

	delay(3000);
}
