
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)


TARGET = Zombie


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(TARGET)


fclean: clean
	rm -f $(TARGET)


re: fclean all

.PHONY: all clean fclean re
