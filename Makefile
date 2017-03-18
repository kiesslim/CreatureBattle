# Author: Meredith Kiessling
# Date: 14.2.2016
#  Description: Makefile for Assignment2 - Shopping List

CXX = g++
CXXFLAGS = -std=c++0x
SRCS = mainGame.cpp Barbarian.cpp BlueMen.cpp Creature.cpp Die.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp
HEADERS = mainGame.hpp Barbarian.hpp BlueMen.hpp Creature.hpp Die.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp
TARGET = dd

dd: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ${TARGET}

clean:
	${RM} ${TARGET} 
                 
