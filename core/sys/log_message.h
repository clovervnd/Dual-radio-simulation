/* Log levels */
#include <stdio.h>
#include "cfs/cfs.h"

#ifdef COOJA
static FILE *log_fp;
#else	/* COOJA */
static int log_file;
#endif	/* COOJA */

void log_initialization(void);
void log_finisher(void);

#define LOG_LEVEL		1

#if LOG_LEVEL == 0
#define LOG_MESSAGE(...) printf(__VA_ARGS__)

#elif	LOG_LEVEL == 1
#ifdef COOJA
#define LOG_MESSAGE(...) fprintf(log_fp, __VA_ARGS__)
#else	/* COOJA */
#define LOG_MESSAGE(...) cfs_write(log_file, __VA_ARGS__, 30)
#endif	/* COOJA */

#elif LOG_LEVEL == 2
#ifdef COOJA
#define LOG_MESSAGE(...) \
	do{\
		printf(__VA_ARGS__);\
		fprintf(log_fp, __VA_ARGS__);\
	}while(0)

#else /* COOJA */
#define LOG_MESSAGE(...) \
	do{\
		printf(__VA_ARGS__);\
		cfs_write(log_file, __VA_ARGS__,30);\
	}while(0)
#endif	/* COOJA */
#endif
