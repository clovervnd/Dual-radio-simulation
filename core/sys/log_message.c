/* Log levels */
#include "log_message.h"


void log_initialization(void){
#ifdef COOJA
	printf("Opening the file for cooja\n");
	log_fp = fopen("/home/usr/Desktop/log_message_cooja.txt", "w");
#else	/* COOJA */
	printf("Opening the file for z1/firefly\n");
	log_file = cfs_open("log_message", CFS_WRITE);
#endif /* COOJA */
}

void log_finisher(void){
#ifdef COOJA
	printf("Closing the file for cooja\n");
	fclose(log_fp);
#else
	printf("Closing the file for z1/firefly\n");
	cfs_close(log_file);
#endif
}
