/* Adding simple remaining energy and alpha JJH*/
#define INITIAL_ENERGY 200
#define ALPHA 1

static uint8_t remaining_energy = INITIAL_ENERGY;
static uint8_t alpha = ALPHA;

#define RPL_ENERGY_MODE 1
#define LONG_ETX_PENALTY 5

/* DUAL RADIO */
//#define LONGRANGE_ENABLE 0
//#define NETSTACK_DUAL_RADIO LONGRANGE_ENABLE
//#define DUAL_RADIO LONGRANGE_ENABLE
//#define ADDR_MAP 0
