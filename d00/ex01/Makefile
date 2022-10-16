CC = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
SRCS = PhoneBook.cpp\
		Contact.cpp\
		main.cpp
HEADERS = PhoneBook.hpp\
		Contact.hpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = phonebook

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
