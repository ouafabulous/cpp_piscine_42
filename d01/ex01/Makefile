CC = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
SRCS = main.cpp \
		Zombie.cpp \
		zombieHorde.cpp
OBJS = $(SRCS:%.cpp=%.o)
HEADERS = Zombie.hpp
NAME = moarbrainz

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
