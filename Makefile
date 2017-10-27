#PROJ = a.out
#OBJS = main.o test.o 

PATH=/home/xizhen/arm-bin:/bin:/usr/bin:/sbin:/usr/sbin
CROSS_COMPILE=armv5te-
#CROSS_COMPILE=arm-linux-
CC=$(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
STRIP = $(CROSS_COMPILE)strip
INC_DIR = -I /usr/include/libxml2 -I include
LDFLAGS = -lpthread -lsqlite3 -lz -lrt -lxml2 -lcrypto

PRG = a.out

TARGETS = $(PRG)

CPPFLAGS = -Wall -Werror -fPIC -O2 -DCROSS_COMPILE $(INC_DIR)

all: a.out

clean:
	rm -rf a.out

a.out:	main.cpp paraser.cpp scaner.cpp Node.cpp
	g++ $^ -o $@
#	$(CXX) $^ -o $@ $(CPPFLAGS) $(LDFLAGS)

#$(PRG): $(OBJS) 
#	$(CXX) -o $(PRG) $(CPPFLAGS) $(OBJS) $(LDFLAGS)
#	$(STRIP) $(PRG)

#tags: ./gprs_new_hw.cpp
#	ctags -R

