CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp
HEADERS = ClapTrap.hpp \
		ScavTrap.hpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = claptrap

all: $(NAME)

%.o: %.cpp $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $^ -o $(NAME)
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
