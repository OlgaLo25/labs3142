CC = g++
CFLAGS = -Wall -g

#Folders
SRC = src
OBJ = obj

BINDIR = bin
BIN = $(BINDIR)/main

SRC_TEST = test
BIN_TEST = $(BINDIR)/lab2Test

INCLUDE = -I include
INCLUDE_TEST:= -I cppunit

LD_LIBRARY_PATH=/usr/local/lib
#Getting files in folders
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

SRCS_TEST = $(wildcard $(SRC_TEST)/*.cpp)
OBJS_TEST= $(filter-out $(OBJ)/main.o, $(OBJS)) $(SRCS_TEST:$(SRC_TEST)/%.cpp=$(OBJ)/%.o)

#DEPENDENCIES = $(OBJS:.o=.d)

#SUBMITNAME = project.zip



lab2:$(BIN)
	echo $LD_LIBRARY_PATH

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ && ./$(BIN)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -MMD -o $@

test:$(BIN_TEST)

$(BIN_TEST):$(OBJS_TEST)
	$(CC) $(CFLAGS) $^ -lcppunit -o $@ && ./$(BIN_TEST)

$(OBJ)/%.o: $(SRC_TEST)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -MMD -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*