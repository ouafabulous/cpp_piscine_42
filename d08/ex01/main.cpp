#include "Span.hpp"

int main()
{
	Span new_span(5);
	int arr[] = {102, 105, 76, 1800, 5094};
	// int arr[] = {};
	unsigned int size_arr = sizeof(arr) / sizeof(arr[0]);
	try
	{
		new_span.addNumber(1);
		new_span.addNumber(&(arr[0]), &(arr[size_arr]));
		std::cout << new_span;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what();
	}
	try
	{
		std::cout << "Shortest span: " << new_span.shortestSpan() << std::endl;
		std::cout << "longuest span: " << new_span.longestSpan() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what();
	}
	return 0;
}
