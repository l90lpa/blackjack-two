# This is the makefile for the Blackjack Two program.
# Setup:
#       - Ensure that the makefile and all the dependent files are in the same directory.
#	- Ensure that the compiler flag CXX is updated to specify a compiler that is 
#	  C++11 compatible, here it is the compiler is g++ 4.8 located at /usr/local/bin/g++-4.8

EXE = blackjack-two

INC_DIR = include
SRC_DIR = src
OBJ_DIR = objects

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


#CXX is the compiler to be used ensure that it is g++ version > version 4.8.
# The "-I" flag adds a search path for the compiler to search for files from.
# "$(CURDIR)" is a predefined variable that evaluates to the file path of the makefile.
CXX = /usr/local/bin/g++-4.8
CXXFLAGS = -I$(CURDIR) -Wall -std=c++11


# "$@" evaluates as the file path/name of the target of a rule.
# "$<" evaluates as the first prerequisite (dependency) of a rule.
# thus the above a purely being used reduce typing.
all: $(OBJ_DIR) $(EXE)

# Check that the objects directory exists and if not create the directory.	
$(OBJ_DIR): 
	if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi

#link object files together to form the executable.
$(EXE) : $(OBJ)
	$(CXX) $(OBJ) -o $@

#compile the source code files into object files.
$(OBJ_DIR)/main.o : $(SRC_DIR)/main.cpp $(INC_DIR)/card.hpp $(INC_DIR)/deck.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJ_DIR)/card.o : $(SRC_DIR)/card.cpp $(INC_DIR)/card.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJ_DIR)/deck.o : $(SRC_DIR)/deck.cpp $(INC_DIR)/deck.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean : 
	$(RM) $(OBJ)
	$(RM) $(EXE)
	rmdir $(OBJ_DIR)
