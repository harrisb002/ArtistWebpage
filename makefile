# Define the compiler
CXX = g++

# Define the flags
CXXFLAGS = -std=c++11 -Wall

# Define the target executable
TARGET = main

# Define the directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Define the source files
SRCS = $(wildcard $(SRC_DIR)/Album/*.cpp $(SRC_DIR)/Album/Images/*.cpp \
                $(SRC_DIR)/Artist/*.cpp $(SRC_DIR)/Artist/Images/*.cpp \
                $(SRC_DIR)/JSON/*.cpp $(SRC_DIR)/Tokenizer/*.cpp \
                $(SRC_DIR)/Tokenizer/Data/*.cpp $(SRC_DIR)/Tracks/*.cpp \
                main.cpp)

# Define the object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Define the include directories
INCLUDES = -I$(SRC_DIR) -I$(SRC_DIR)/Album -I$(SRC_DIR)/Album/Images \
            -I$(SRC_DIR)/Artist -I$(SRC_DIR)/Artist/Images \
            -I$(SRC_DIR)/JSON -I$(SRC_DIR)/Tokenizer \
            -I$(SRC_DIR)/Tokenizer/Data -I$(SRC_DIR)/Tracks

# Define the rules
all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

run: $(BIN_DIR)/$(TARGET)
	$(BIN_DIR)/$(TARGET) JSON/artists_human_readable.json JSON/artist_images_human_readable.json JSON/albums_human_readable.json JSON/album_images_human_readable.json JSON/tracks_human_readable.json

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(TARGET)

.PHONY: all clean run
