
# Makefile for f2022, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp

CC = g++ -std=c++14
CFLAGS = -g

LDFLAGS = 	-L/opt/homebrew/lib/ -ljsoncpp			\
		-lmicrohttpd -ljsonrpccpp-common		\
		-ljsonrpccpp-server -ljsonrpccpp-client -lcurl

INC	=	ecs36b_Common.h

INC_CL	=	JvTime.h
OBJ	=	JvTime.o

# rules.
all: 	hw6server hw6client

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>

hw6client.h:		ecs36b_hw6.json
	jsonrpcstub ecs36b_hw6.json --cpp-server=hw6Server --cpp-client=hw6Client

hw6server.h:		ecs36b_hw6.json
	jsonrpcstub ecs36b_hw6.json --cpp-server=hw6Server --cpp-client=hw6Client

hw6client.o:		hw6client.cpp hw6client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw6client.cpp

hw6server.o:		hw6server.cpp hw6server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw6server.cpp

ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp

hw6server:	hw6server.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw6server hw6server.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

hw6client:	hw6client.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw6client hw6client.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o *~ core hw6client.h hw6server.h hw6client hw6server
