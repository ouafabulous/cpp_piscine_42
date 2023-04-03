#include <stack>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>

void	getAB(std::stack<int> &stack, int &a, int &b)
{
	if (stack.size() < 2)
		throw std::runtime_error("Not enough arguments");
	b = stack.top();
	stack.pop();
	a = stack.top();
	stack.pop();
}

void	splitBySpace(std::string &str, std::vector<std::string> &tokens)
{
	std::string token;
	std::istringstream tokenStream(str);
	while (std::getline(tokenStream, token, ' '))
		tokens.push_back(token);
}

int main(int argc, char const *argv[])
{
	try
	{
	if (argc < 2)
		throw std::runtime_error("./RPN [int] [int] [operator] ...");;
	std::vector<std::string> tokens;
	std::string argv1(argv[1]);
	splitBySpace(argv1, tokens);
	std::stack<int> stack;
		int a,b;
		for (size_t i = 0; i < tokens.size(); ++i)
	{
		std::string arg = tokens[i];
		if (arg == "+")
		{
			getAB(stack, a, b);
			stack.push(a + b);
		}
		else if (arg == "-")
		{
			getAB(stack, a, b);
			stack.push(a - b);
		}
		else if (arg == "*")
		{
			getAB(stack, a, b);
			stack.push(a * b);
		}
		else if (arg == "/")
		{
			getAB(stack, a, b);
			//handle division by zero
			if (b == 0)
				throw std::runtime_error("Division by zero");
			stack.push(a / b);
		}
		else
		{
			std::stringstream ss(arg);
			int n;
			ss >> n;
			if (strlen(ss.str().c_str()) > 1 || ss.fail() || !ss.eof())
				throw std::runtime_error("Error");
			stack.push(n);
		}
	}
	std::cout << stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
