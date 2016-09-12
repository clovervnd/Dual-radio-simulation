#include "dual_conf.h"
#define DEBUG_DUAL	1
#if DEBUG_DUAL
#include <stdio.h>

#define RADIO(...) printf(__VA_ARGS__)
#else
#define RADIO(...) 
#endif

long_range_radio = 0;
radio_received = SHORT_RADIO;

int dual_radio_switch(int radio)
{
	if (radio == LONG_RADIO)
	{
		long_range_radio = 1;
		LongRangeTransmit = 1;
		RADIO("LONG RANGE BIT = %d\n",LongRangeTransmit);
		RADIO("$$$$$$$$$$$$$$$$$$  Using long-range radio\n");
	}
	else if (radio == SHORT_RADIO)
	{
		long_range_radio = 0;
		LongRangeTransmit = 0; 
		RADIO("LONG RANGE BIT = %d\n",LongRangeTransmit);
		RADIO("$$$$$$$$$$$$$$$$$$  Using short-range radio\n");
	}
	return 1;
}

int dual_radio_change(void)
{
	if (long_range_radio == 1)
		dual_radio_switch(SHORT_RADIO);
	else if (long_range_radio == 0)
		dual_radio_switch(LONG_RADIO);
		return 1;
}

int dual_radio_received(int radio)
{
	if (radio == LONG_RADIO)
	{
		radio_received = LONG_RADIO;
		RADIO("$$$$$$$$$$$$$$$$$$  INTERRUPT!! long-range radio\n");
	}
	else if(radio == SHORT_RADIO)
	{
		radio_received = SHORT_RADIO;	
		RADIO("$$$$$$$$$$$$$$$$$$  INTERRUPT!! short-range radio\n");
	}
}

int radio_received_is_longrange(void)
{
	if (radio_received == LONG_RADIO)
	{
		RADIO("$$$$$$$$$$$$$$$$$$  LONG_RADIO_RECEIVED\n");
		return LONG_RADIO;
	}
	else
	{
		RADIO("$$$$$$$$$$$$$$$$$$  SHORT_RADIO_RECEIVED\n");
		return SHORT_RADIO;
	}
}
