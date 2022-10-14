CC = g++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
SRCS = PhoneBook.cpp\
		Conact.cpp\
		main.cpp
HEADERS = PhoneBook.hpp\
		Contact.hpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = phonebook

all: $(NAME)

%.o: %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME)
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
