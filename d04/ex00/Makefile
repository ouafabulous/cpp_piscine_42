CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
SRCS = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp
HEADERS = Animal.hpp \
		Dog.hpp \
		Cat.hpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = fucking_animals

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
