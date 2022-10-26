CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -fsanitize=address
SRCS = main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp
HEADERS = Fixed.hpp \
		Point.hpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = fixed

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
