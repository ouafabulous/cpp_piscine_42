CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)
NAME = btc

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)
