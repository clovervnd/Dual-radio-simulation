/* RPL MODES */
#define RPL_ENERGY_MODE 0
#define RPL_LIFETIME_MAX_MODE 1

/* Distributed weight update problem solutions */
#define MODE_DIO_WEIGHT_UPDATED 0
#define MODE_LAST_PARENT	0 // Tx Last parent info. in dio_ack
#define MODE_PARENT_UPDATE_IN_ROUND 0 // Update parent only when round is synchronized // Not implemented yet

/* OF best parent selection strategy */
#define OF_MWHOF	0 // Minimum Weight Hysteresis Objective Function

/* Metric ratio between weight and rank */
//#define ALPHA 2
/* Weight ratio between long and short*/
#define LONG_WEIGHT_RATIO 5

/* Sink's infinite energy */
#define SINK_INFINITE_ENERGY	0

#if RPL_ENERGY_MODE
uint8_t remaining_energy;
uint8_t alpha;
#define LONG_ETX_PENALTY 5

#elif RPL_LIFETIME_MAX_MODE
#define RPL_ETX_WEIGHT 	0
uint8_t my_weight;
uint8_t my_sink_reachability;
uint8_t my_child_number;
#define DATA_PKT_SIZE 10 // 'B' in theory
#define SHORT_TX_COST 1
#define SHORT_RX_COST 1
#define LONG_TX_COST 9
#define LONG_RX_COST 6
#endif
