CC = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
SRCS = main.cpp \
		Zombie.cpp \
		zombieHorde.cpp
OBJS = $(SRCS:%.cpp=%.o)
HEADERS = Zombie.hpp
NAME = Moarbrainz!

all: $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $^ -o $(NAME)
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
