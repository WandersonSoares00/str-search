PROJ_NAME = main
CXX = g++
CPPFLAGS = -Wall -Wextra -std=c++17 -g -pedantic
RM = rm -rf
OBJ_DIR = bin
RM = rm -rf

all: $(OBJ_DIR) $(PROJ_NAME)

$(PROJ_NAME):	$(OBJ_DIR)/main.o $(OBJ_DIR)/search_time.o $(OBJ_DIR)/search.o $(OBJ_DIR)/str.o
	$(CXX) $(CPPFLAGS) $^  -o $(PROJ_NAME) 

$(OBJ_DIR)/main.o:	src/main.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/search_time.o: src/search_time.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/search.o: src/search.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/str.o: src/str.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR) $(PROJ_NAME)
