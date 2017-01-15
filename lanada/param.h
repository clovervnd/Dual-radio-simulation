/* Adding simple remaining energy and alpha JJH*/
#define INITIAL_ENERGY 200
#define ALPHA 1

#define RPL_ENERGY_MODE 0
#define RPL_LIFETIME_MAX_MODE 1
#define LONG_ETX_PENALTY 5

#if RPL_ENERGY_MODE
uint8_t remaining_energy;
uint8_t alpha;
#elif RPL_LIFETIME_MAX_MODE
uint8_t my_weight;
#endif

#define DATA_PKT_SIZE 10 // 'B' in theory
#define SHORT_TX_COST 1
#define SHORT_RX_COST 3
#define LONG_TX_COST 9
#define LONG_RX_COST 6

/* DUAL RADIO */
//#define LONGRANGE_ENABLE 0
//#define NETSTACK_DUAL_RADIO LONGRANGE_ENABLE
//#define DUAL_RADIO LONGRANGE_ENABLE
//#define ADDR_MAP 0
