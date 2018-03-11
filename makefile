###
###@file - Make file for CS162
###@author - Jacob Powers
###@description - Make file to compile projects
### includes testc: which is simple g++ compile all
### testo: is compile individual changes
### debug: includes -g flag for GDB
### clean: removes all executables and .o 

CC = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
OBJS = RandomNum.o DMenu.o ValidIn.o Spaces.o Grocery.o Entry.o Produce.o Meat.o Dairy.o Bread.o Checkout.o Gameplay.o main.o
SRCS = RandomNum.cpp DMenu.cpp ValidIn.cpp Spaces.cpp Grocery.cpp Entry.cpp Produce.cpp Meat.cpp Dairy.cpp Bread.cpp Checkout.cpp Gameplay.cpp main.cpp

HEADERS = 

default: a 

 all: 
	$(CC) -g -std=c++11 ${SRCS} -o debug

a: ${OBJS} ${HEADERS}
	${CC} ${LDFLAGS} ${OBJS} -o a 

mem: ${OBJS} ${HEADERS}
	${CC} ${LDFLAGS} ${OBJS} -v -g -o mem 


${OBJS}: ${SRCS}
	${CC} ${CXXFLAGS} -c $(@:.o=.cpp) 

clean:
	${RM} a mem debug *.o
