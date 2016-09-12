#include "dev/cooja-radio.h"

#ifndef SHORT_RADIO
#define SHORT_RADIO 2
#endif

#ifndef LONG_RADIO
#define LONG_RADIO 1
#endif



/* Functions */
int dual_radio_switch(int radio);
int dual_radio_change(void);
int dual_radio_received(int radio); 
int radio_received_is_longrange(void);

/* Global variable for Dual RPL */
int long_range_radio;
int radio_received;

/* Global variable for Cooja simulation */
extern int LongRangeTransmit;
