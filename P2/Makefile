# Makefile for f2022, ecs36b
#
# g++ -std=c++14 test_GPS.cpp GPS.cpp -o test_GPS


CC = g++ -std=c++14

# CFLAGS = -g -I/usr/include/jsoncpp

# CFLAGS = -g

CFLAGS = -g -I/opt/homebrew/include


# CFLAGS = -g -D_ECS36B_DEBUG_ -I/usr/include/jsoncpp
# CFLAGS = -g -Wall -Wstrict-prototypes
# CFLAGS = -O3

LDFLAGS = -L/opt/homebrew/lib -ljsoncpp

# rules.
all: 	36b


GPS.o:		GPS.cpp GPS.h
	$(CC) -c $(CFLAGS) GPS.cpp

RTime.o:	RTime.cpp RTime.h
	$(CC) -c $(CFLAGS) RTime.cpp

Person.o:	Person.cpp Person.h
	$(CC) -c $(CFLAGS) Person.cpp

Thing.o:	Thing.cpp Thing.h
	$(CC) -c $(CFLAGS) Thing.cpp

Record.o:	Record.cpp Record.h
	$(CC) -c $(CFLAGS) Record.cpp

36b.o:	36b.cpp GPS.h Thing.h Person.h RTime.h Record.h
	$(CC) -c $(CFLAGS) 36b.cpp

36b:		GPS.o 36b.o Thing.o Person.o RTime.o Record.o
	g++ -std=c++14 36b.o GPS.o Thing.o Person.o RTime.o Record.o -o 36b $(LDFLAGS)

clean:
	rm -f *.o *~ core 36b
