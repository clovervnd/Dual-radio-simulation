/* Log levels */
#include "log_message.h"

#ifdef COOJA
#include "net/linkaddr.h"
FILE *log_fp;
#else	/* COOJA */
int log_file;
#endif	/* COOJA */


void log_initialization(void){
	cxmac_collision_count = 0;
	cxmac_transmission_count = 0;
	csma_transmission_count = 0;
	control_message_count = 0;
	data_message_count = 0;
	data_fwd_count = 0;
	dio_count = 0;
	dis_count = 0;
	dao_count = 0;
	dao_fwd_count = 0;
	dao_ack_count = 0;
	dao_ack_fwd_count = 0;
	LSA_count = 0;
	dio_ack_count = 0;
	icmp_count = 0;
	tcp_output_count = 0;

	

#ifdef COOJA
	char filename[100];
	sprintf(filename, "/home/user/Desktop/Debug_log/log_message%d.txt",linkaddr_node_addr.u8[1]);
	printf("\n\nOpening the file for cooja\n\n");
	log_fp = fopen(filename, "w");
#else	/* COOJA */
	printf("\n\nOpening the file for z1/firefly\n\n");
	log_file = cfs_open("log_message", CFS_WRITE);
#endif /* COOJA */
}

void log_finisher(void){
#ifdef COOJA
	printf("\n\nClosing the file for cooja\n\n");
	fclose(log_fp);
#else
	printf("\n\nClosing the file for z1/firefly\n\n");
	cfs_close(log_file);
#endif
}
