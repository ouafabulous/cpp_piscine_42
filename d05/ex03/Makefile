CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
SRCS = main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp

SHRB = *_shruberry

OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)
NAME = intern

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME) $(SHRB)

re: fclean all

-include $(DEPS)
