#include "Rte_AppDio.h"
#include "AppAtm.h"

FUNC(void, AppDio_CODE) AppDio_10ms( VAR(void, AUTOMATIC) )
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

Atm_Return_t AppIo_AtmCallOut(AtmReqPar_t* atmReq)
{
	/* ChannelID : 0 -> LED1 P011 */
	/* Test IO */
	Atm_Return_t ret = ATM_RESULT_FAILED ;
	if(atmReq->AtmReq_Sig1_TCaseID == ATM_TESTCASEID_IO_0001)
	{
		/* Step 1: Turn ON LED1 */
		if(atmReq->AtmReq_Sig2_TStepID == ATM_TESTSTEPID_0001)
		{
			ret = Rte_Call_AppDio_R_App_DioToIoHwAb_IoHwAb_Q_DioWriteChannel(0, 1);
		}
		/* Step 2: Turn OFF LED1 */
		if(atmReq->AtmReq_Sig2_TStepID == ATM_TESTSTEPID_0002)
		{
			ret = Rte_Call_AppDio_R_App_DioToIoHwAb_IoHwAb_Q_DioWriteChannel(0, 0);
		}
	}

	return ret;
}

