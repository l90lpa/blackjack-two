CXX = /usr/local/bin/g++-4.8
CXXFLAGS = -Wall -std=c++11

objects = main.o card.o deck.o

all: blackjackTwo

blackjackTwo : $(objects) ; $(CXX) $(CXXFLAGS) $(objects) -o blackjackTwo

main.o : main.cpp card.hpp deck.hpp ; $(CXX) $(CXXFLAGS) -c main.cpp

card.o : card.cpp card.hpp ; $(CXX) $(CXXFLAGS) -c card.cpp

deck.o : deck.cpp deck.hpp ; $(CXX) $(CXXFLAGS) -c deck.cpp

.PHONY : clean
clean : ; rm $(objects) ; rm blackjackTwo