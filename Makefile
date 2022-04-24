CC = g++
CFLAGS = -Wall -g

SRC = src
OBJ = obj

BINDIR = output
BIN = $(BINDIR)/main

SRC_TEST = test
BIN_TEST = $(BINDIR)/test

INCLUDE = -I include
INCLUDE_TEST:= -I cppunit

SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

SRCS_TEST = $(wildcard $(SRC_TEST)/*.cpp)
OBJS_TEST= $(filter-out $(OBJ)/main.o, $(OBJS)) $(SRCS_TEST:$(SRC_TEST)/%.cpp=$(OBJ)/%.o)


lab3:$(BIN)
	cd $(BINDIR) && ./main

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -MMD -o $@

test:$(BIN_TEST)

$(BIN_TEST):$(OBJS_TEST)
	$(CC) $(CFLAGS) $^ -lcppunit -o $@ && cd $(BINDIR) && ./test

$(OBJ)/%.o: $(SRC_TEST)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -MMD -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*