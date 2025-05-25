# ┌───────────────────────────────────────────────────────────────────────┐
# │ 1. Toolchain & flags                                                  │
# └───────────────────────────────────────────────────────────────────────┘

# Which compiler to use:
CXX      := g++

# Flags for compiling:
#   -std=c++17   → enforce C++17 standard
#   -Wall        → enable all common warnings
#   -Wextra      → enable extra warnings
#   -Iinclude    → add your headers directory to the search path
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude


# ┌───────────────────────────────────────────────────────────────────────┐
# │ 2. Directory layout                                                   │
# └───────────────────────────────────────────────────────────────────────┘

SRC_DIR   := src
BUILD_DIR := build

# Final executable name:
TARGET    := $(BUILD_DIR)/terminal_chess

# Find all .cpp files under src/:
SRCS      := $(wildcard $(SRC_DIR)/*.cpp)

# For each foo.cpp, we’ll build build/foo.o
OBJS      := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))


# ┌───────────────────────────────────────────────────────────────────────┐
# │ 3. “phony” targets (not real files)                                  	│
# └───────────────────────────────────────────────────────────────────────┘

.PHONY: all clean run


# ┌───────────────────────────────────────────────────────────────────────┐
# │ 4. Default target: build the executable                               │
# └───────────────────────────────────────────────────────────────────────┘

all: $(TARGET)


# ┌───────────────────────────────────────────────────────────────────────┐
# │ 5. Link step: take all .o files and link them into your binary        │
# └───────────────────────────────────────────────────────────────────────┘

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
	# $^ = all prerequisites (the .o files)
	# $@ = the target (build/terminal_chess)


# ┌───────────────────────────────────────────────────────────────────────┐
# │ 6. Compile step: turn each .cpp into a .o                             │
# └───────────────────────────────────────────────────────────────────────┘

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	# $< = the single prerequisite (e.g. src/main.cpp)
	# -c    = compile only, don’t link


# ┌───────────────────────────────────────────────────────────────────────┐
# │ 7. Convenience targets                                                │
# └───────────────────────────────────────────────────────────────────────┘

# make run → build if needed, then execute
run: all
	@$(TARGET)

# make clean → remove build artifacts
clean:
	@rm -rf $(BUILD_DIR)/*


