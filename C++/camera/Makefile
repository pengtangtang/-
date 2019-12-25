CC=${CROSS_COMPILE}gcc
AR=${CROSS_COMPILE}ar
LD=${CROSS_COMPILE}ld

APP	= server
CFLAGS	= -Wall -O2 -g -std=gnu99 -I. -DMYDBG
LDFLAGS	= -static -L. -ljpeg -lpthread
SRCS	= $(wildcard *.c)
OBJS	= $(patsubst %.c,%.o,$(SRCS))

$(APP): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean: 
	rm -f $(APP) $(OBJS)


