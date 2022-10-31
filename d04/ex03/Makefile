CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
SRCS = main.cpp \
		AMateria.cpp \
		Ice.cpp \
		Cure.cpp
HEADERS = AAnimal.hpp \
		AMateria.hpp \
		Ice.hpp \
		Cure.hpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = abstract_class

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
