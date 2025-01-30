SRCS = main.cpp Intern.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Default target
all: intern

# Create the final executable
intern: $(OBJS)
	$(CC) $(OBJS) -o intern

# Compile each .cpp file into an object file
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up both object files and the executable
fclean: clean
	rm -f intern

# Rebuild everything (clean + all)
re: fclean all
