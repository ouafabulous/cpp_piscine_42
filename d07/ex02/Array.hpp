#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{

public:
	Array() { _array = NULL; _n = 0;}
	Array(unsigned int n) { _array = new T[n]; _n = n;}
	Array(Array const &src)
	{
		_array = NULL;
		*this = src;
	}
	~Array()
	{
		if (_array) {
			delete [] _array;
		}
	}

	class IndexOutOfBounds : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Index is out of bounds.");
				}
		};

	Array			&operator=(Array const &rhs)
	{
		if (this != &rhs)
		{
			_n = rhs._n;
			if (_array)
			{
				delete [] _array;
			}
			_array = new T[rhs.size()];
			for (unsigned int i = 0; i != rhs.size(); i++)
			{
				_array[i] = rhs._array[i];
			}
		}
		return *this;
	}

	T				&operator[](int index)
	{
		if (index < 0 or (unsigned int)index >= size()) {
			throw IndexOutOfBounds();
		}
		return (_array[index]);
	}

	unsigned int	size() const
	{
		return (_n);
	}

private:
	T				*_array;
	unsigned int	_n;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &i);

#endif /* *********************************************************** ARRAY_H */
