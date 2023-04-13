CC = g++ -std=c++14
CFLAGS = -I/opt/homebrew/include -g
#LDFLAGS = 	-L/opt/homebrew/Cellar/jsoncpp/1.9.5/lib -ljsoncpp
LDFLAGS = -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

ll: 	RedRidingHood

Record.o:		Record.cpp Record.h commonfiles.h
	$(CC) -c $(CFLAGS) Record.cpp

vTime.o:		vTime.cpp vTime.h commonfiles.h
	$(CC) -c $(CFLAGS) vTime.cpp

Location.o:		Location.cpp Location.h commonfiles.h
	$(CC) -c $(CFLAGS) Location.cpp

Person.o:	Person.cpp Person.h commonfiles.h
	$(CC) -c $(CFLAGS) Person.cpp

Thing.o:	Thing.cpp Thing.h commonfiles.h
	$(CC) -c $(CFLAGS) Thing.cpp

ecs36b_JSON.o:	ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp


RedRidingHood.o:	RedRidingHood.cpp Thing.h Person.h Location.h vTime.h Record.h commonfiles.h ecs36b_JSON.cpp
	$(CC) -c $(CFLAGS) RedRidingHood.cpp

RedRidingHood:		RedRidingHood.o Thing.o Person.o Location.o vTime.o Record.o ecs36b_JSON.o
	g++ -std=c++14 RedRidingHood.o Thing.o Person.o Location.o vTime.o Record.o ecs36b_JSON.o -o RedRidingHood $(LDFLAGS)

clean:
	rm -f *.o *~ core test_ThingPerson

