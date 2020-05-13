CC=
CFLAGS=-g -Wall -Werror
# LDFLAGS=
# LDLIBS=
SRCS=main.c van-emde-boas.c
OBJS=main.o van-emde-boas.o
RM=
TARGET=

ifeq ($(OS), Windows_NT)
    CC=C:\Program Files (x86)\CodeBlocks\MinGW\bin\x86_64-w64-mingw32-gcc.exe
    RM=del
	TARGET=a.exe
else
	CC=gcc
    RM=rm
	TARGET=a.out
endif

all: $(TARGET)

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)