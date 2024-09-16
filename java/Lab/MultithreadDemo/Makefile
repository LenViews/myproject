# Variables
JAVAC = javac
JAVA_FILES = RaceTrack.java Runner.java RaceSimulation.java
BIN_DIR = bin
MAIN_CLASS = RaceSimulation  # Update this with the correct main class

# Default target
all: $(BIN_DIR)/RaceSimulation.class

# Compile Java files
$(BIN_DIR)/RaceSimulation.class: $(JAVA_FILES)
	mkdir -p $(BIN_DIR)
	$(JAVAC) -d $(BIN_DIR) $(JAVA_FILES)

# Run the program
run: all
	java -cp $(BIN_DIR) $(MAIN_CLASS)

# Clean up
clean:
	rm -rf $(BIN_DIR)
