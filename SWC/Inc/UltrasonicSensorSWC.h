#include "Rte_AppSensor.h"

FUNC(void, AppSensor_CODE) MeasureDistance( VAR(void, AUTOMATIC) )
{
	// blink led to check stuck
	static uint8 level = 0;
	static uint8 count = 0;
	count++;
	if (count >= 50) {
		count = 0;
		level = !level;
		Rte_Call_AppDio_R_App_DioToIoHwAb_IoHwAb_Q_DioWriteChannel(1, level);
	}
	
}