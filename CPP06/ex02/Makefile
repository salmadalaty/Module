# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable name
EXEC = identify_real_type

# Source files
SRC = main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJ)

# Clean everything (including executable)
fclean: clean
	rm -f $(EXEC)

# Rebuild everything from scratch
re: fclean all

# Run the program
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean fclean re run
