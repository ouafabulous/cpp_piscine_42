CC = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
SRCS = Account.cpp\
		tests.cpp
HEADERS = Account.hpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = accounts

all: $(NAME)

%.o: %.cpp $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
