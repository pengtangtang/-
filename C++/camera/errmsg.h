#ifndef ERRMSG_H
#define ERRMSG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
extern int errno;

#ifdef MYDBG
#define PRN_ERRMSG_EXIT(errmsg) \
	({ \
		fprintf(stderr, "%s:%s[%d]:%s:%s\n\r", \
			errmsg,__FILE__,__LINE__,__FUNCTION__,strerror(errno)); \
		exit(-1); \
	})
#else
#define PRN_ERRMSG_EXIT(errmsg) ({ exit(-1); })
#endif

#ifdef MYDBG
#define PRN_ERRMSG_RETURN(errmsg) \
	({ \
		fprintf(stderr, "%s:%s[%d]:%s:%s\n\r", \
			errmsg,__FILE__,__LINE__,__FUNCTION__,strerror(errno)); \
		return(-1); \
	})
#else
#define PRN_ERRMSG_RETURN(errmsg) ({ return(-1); })
#endif

#ifdef MYDBG
#define PRN_ERRMSG(errmsg) \
	({ \
		fprintf(stderr, "%s:%s[%d]:%s:%s\n\r", \
			errmsg,__FILE__,__LINE__,__FUNCTION__,strerror(errno)); \
	})
#else
#define PRN_ERRMSG(errmsg)
#endif

#ifdef MYDBG
#define ASSERT(EXP) \
	({ \
		if(!(EXP)){\
			fprintf(stderr, "[assert] %s, \"%s()\", line%d.\n\r", \
				__FILE__,__FUNCTION__,__LINE__); \
			exit(-1); \
		}\
	})
#else
#define ASSERT(EXP)
#endif

#endif
