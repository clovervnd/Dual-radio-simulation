#include "platform-conf.h"
#include "cc1200.h"
#include "cc2420.h"

#ifndef SHORT_RADIO
#define SHORT_RADIO 1
#endif

#ifndef LONG_RADIO
#define LONG_RADIO 2
#endif

/* Radio drivers */
extern struct radio_driver NETSTACK_CONF_RADIO;
extern struct radio_driver NETSTACK_RADIO;

/* Functions */
int dual_radio_switch(int radio);
int dual_radio_change(void);
int dual_radio_received(int radio);

/* Global variable for Cooja simulation */
int long_range_radio;
int radio_received;
