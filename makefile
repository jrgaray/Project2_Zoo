CXX = g++
CXXFLAGS = -pedantic-errors
CXXFLAGS += -Wall
CXXFLAGS += -std=c++0x
CXXFLAGS += -g

OBJS = Animal.o main.o Tiger.o Penguin.o Turtle.o Zoo.o Game.o

HEADERS = Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp Zoo.hpp Game.hpp

SRCS = Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp Zoo.cpp main.cpp Game.cpp

zoo: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o zoo 

${OBJS}: ${SRCS} 
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm ${OBJS} zoo
