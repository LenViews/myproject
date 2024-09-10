# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Directories
SRC_DIR = .
OBJ_DIR = build
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/Main

# Source files
SRCS = $(SRC_DIR)/Main.cpp \
       $(SRC_DIR)/Fixture.cpp \
       $(SRC_DIR)/Match.cpp \
       $(SRC_DIR)/Scheduler.cpp \
       $(SRC_DIR)/Team.cpp

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Rebuild everything
rebuild: clean all
