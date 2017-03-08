#include "dev/cooja-radio.h"
#include "net/rpl/rpl-private.h" 

#ifndef SHORT_RADIO
#define SHORT_RADIO 2
#endif

#ifndef LONG_RADIO
#define LONG_RADIO 1
#endif

#ifndef BOTH_RADIO
#define BOTH_RADIO 0
#endif

#ifndef DUAL_DUTY_RATIO
#define DUAL_DUTY_RATIO 1
#endif

#if DUAL_ROUTING_CONVERGE

#ifndef LONG_DUTY_RATIO
#define LONG_DUTY_RADIO		1
#endif

#ifndef SHORT_DUTY_RATIO
#define SHORT_DUTY_RATIO	1
#endif
#endif /* DUAL_ROUTING_CONVERGE */

/* Functions */
int dual_radio_switch(int radio);
int dual_radio_change(void);
int dual_radio_received(int radio); 
int radio_received_is_longrange(void);
int sending_in_LR(void);
int dual_radio_turn_on(char targetRadio);
int dual_radio_turn_off(char targetRadio);

/* Process */
int dio_broadcast(rpl_instance_t* instance);
int dis_broadcast(void);
#if RPL_LIFETIME_MAX_MODE
int dio_ack_broadcast(rpl_instance_t* instance);
#endif

/* Global variable for Dual RPL */
int long_range_radio;
int radio_received;
char dual_duty_cycle_count;


#if DUAL_ROUTING_CONVERGE
char long_duty_cycle_count;
char short_duty_cycle_count;
#endif /* DUAL_ROUTING_CONVERGE */

/* Global variable for Cooja simulation */
extern int LongRangeTransmit;
char simRadioTarget;
