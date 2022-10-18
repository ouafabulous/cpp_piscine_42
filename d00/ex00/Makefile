CC = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = megaphone.cpp
HEADER = megaphone.hpp
OBJ = $(SRC:%.cpp=%.o)
NAME = megaphone

all: $(NAME)

%.o: %.cpp $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $^ -o $(NAME)
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
