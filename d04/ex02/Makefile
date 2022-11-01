CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
SRCS = main.cpp \
		AAnimal.cpp \
		WrongAAnimal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongCat.cpp \
		Brain.cpp
HEADERS = AAnimal.hpp \
		WrongAAnimal.hpp \
		Dog.hpp \
		Cat.hpp \
		WrongCat.hpp \
		Brain.hpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = abstract_class

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
