/* Log levels */
#include "log_message.h"

#ifdef COOJA
#include "net/linkaddr.h"
FILE *log_fp;
#else	/* COOJA */
int log_file;
#endif	/* COOJA */


void log_initialization(void){
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
