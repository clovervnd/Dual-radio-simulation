#include "dual_radio.h"

int dual_radio_switch(int radio)
{
	if (radio == LONG_RADIO)
	{
		long_range_radio = 1;
		NETSTACK_CONF_RADIO = cc1200_driver;
		NETSTACK_RADIO = cc1200_driver;
	}
	else if (radio == SHORT_RADIO)
	{
		long_range_radio = 0;
		NETSTACK_CONF_RADIO = cc2420_driver;
		NETSTACK_RADIO = cc2420_driver;
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
	}
	else if (radio == SHORT_RADIO)
	{
		radio_received = SHORT_RADIO;
	}
}
