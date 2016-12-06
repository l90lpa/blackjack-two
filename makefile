# This is the makefile for the Blackjack Two program.
# Setup:
#       - That the files/directories for the Blackjack Two program are places in a directory, keeping the same structure as current.
#	- Ensure that the compiler flag CXX is updated to specify a compiler that is C++11 compatible
#	- Also it is suggested that the compiler chosen should be the same compiler that was used to compile the Boost Library otherwise
#	  it can lead to, segmentation fault: 11, when running the unitTests executable.

# The "-I" flag adds a search path for the compiler to search for files from.
# "$(CURDIR)" is a predefined variable that evaluates to the file path of the makefile.
EXE = blackjack-two

INC_DIR = include
SRC_DIR = src
OBJ_DIR = objects

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


#CXX is the compiler to be used. See setup note above.
CXX = clang++
CXXFLAGS = -I$(CURDIR) -Wall -std=c++11


# "$@" evaluates as the file path/name of the target of a rule.
# "$<" evaluates as the first prerequisite (dependency) of a rule.
# thus the above a purely being used reduce typing.
all: $(EXE)

# Unit testing target.
unitTests: $(OBJ_DIR) $(OBJ_DIR)/card.o $(OBJ_DIR)/deck.o $(OBJ_DIR)/player.o test/testBlackjackTwo.o
	$(CXX) test/testBlackjackTwo.o $(OBJ_DIR)/card.o $(OBJ_DIR)/deck.o $(OBJ_DIR)/player.o -L/usr/local/Cellar/boost/1.61.0_1/lib -lboost_unit_test_framework-mt -o $@
	
# Link object files together to form the executable.
$(EXE) : $(OBJ_DIR) $(OBJ)
	$(CXX) $(OBJ) -o $@
	
# Check that the objects directory exists and if not create the directory.	
$(OBJ_DIR): 
	if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi

#compile the source code files into object files.
$(OBJ_DIR)/main.o : $(SRC_DIR)/main.cpp $(INC_DIR)/card.hpp $(INC_DIR)/deck.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJ_DIR)/card.o : $(SRC_DIR)/card.cpp $(INC_DIR)/card.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJ_DIR)/deck.o : $(SRC_DIR)/deck.cpp $(INC_DIR)/deck.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJ_DIR)/player.o : $(SRC_DIR)/player.cpp $(INC_DIR)/player.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test/testBlackjackTwo.o : test/testBlackjackTwo.cpp $(INC_DIR)/card.hpp $(INC_DIR)/deck.hpp
	$(CXX) $(CXXFLAGS) -I/usr/local/Cellar/boost/1.61.0_1/include -c $< -o $@

.PHONY : clean
clean : 
	$(RM) $(OBJ)
	$(RM) $(EXE)
	rmdir $(OBJ_DIR)
	rm test/testBlackjackTwo.o
	rm unitTests
