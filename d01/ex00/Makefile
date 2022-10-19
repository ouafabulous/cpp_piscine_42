CC = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
SRCS = Zombie.cpp \
		main.cpp \
		newZombie.cpp \
		randomChump.cpp
HEADERS = Zombie.hpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = braiiiinnnnnnnnnnnzzzzzzzzzZ

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
