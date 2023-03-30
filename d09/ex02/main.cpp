#include <iostream>
#include <time.h>
#include <vector>
#include <list>
#include <iomanip>
#include <sstream>
#include <cmath>

//VECTOR HANDLING
//----------------------------------------------------------------------

std::vector<int>	merge(std::vector<int> v1, std::vector<int> v2)
{
	std::vector<int> v;
	unsigned long i = 0;
	unsigned long j = 0;
	while (i < v1.size() && j < v2.size())
	{
		if (v1[i] < v2[j])
		{
			v.push_back(v1[i]);
			i++;
		}
		else
		{
			v.push_back(v2[j]);
			j++;
		}
	}
	while (i < v1.size())
	{
		v.push_back(v1[i]);
		i++;
	}
	while (j < v2.size())
	{
		v.push_back(v2[j]);
		j++;
	}
	return (v);
}

void	insertSort(std::vector<int> &v, unsigned long left, unsigned long right)
{
	for (unsigned long i = left + 1; i <= right; i++)
	{
		unsigned long j = i;
		while (j > left && v[j] < v[j - 1])
		{
			int tmp = v[j];
			v[j] = v[j - 1];
			v[j - 1] = tmp;
			j--;
		}
	}
}


void insertMergesort(std::vector<int>& v, unsigned long left, unsigned long right, unsigned long k) {
  if (right - left + 1 <= k) {
	insertSort(v, left, right);
  } else if (left < right) {
    int mid = (left + right) / 2;
    insertMergesort(v, left, mid, k);
    insertMergesort(v, mid + 1, right, k);
    std::vector<int> leftSubArray(v.begin() + left, v.begin() + mid + 1);
    std::vector<int> rightSubArray(v.begin() + mid + 1, v.begin() + right + 1);
    std::vector<int> mergedSubarray = merge(leftSubArray, rightSubArray);
    std::copy(mergedSubarray.begin(), mergedSubarray.end(), v.begin() + left);
  }
}

//print the vector
void	printVector(std::vector<int> &v)
{
	for (unsigned long i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

//----------------------------------------------------------------------

//LIST HANDLING
//----------------------------------------------------------------------

std::list<int>	merge(std::list<int> l1, std::list<int> l2)
{
	std::list<int> l;
	std::list<int>::iterator i = l1.begin();
	std::list<int>::iterator j = l2.begin();
	while (i != l1.end() && j != l2.end())
	{
		if (*i < *j)
		{
			l.push_back(*i);
			i++;
		}
		else
		{
			l.push_back(*j);
			j++;
		}
	}
	while (*i != *(l1.end()))
	{
		l.push_back(*i);
		i++;
	}
	while (*j != *(l2.end()))
	{
		l.push_back(*j);
		j++;
	}
	return l;
}

//sort a list of 2 elements
void	insertSortTwo(std::list<int> &l)
{
	std::list<int>::iterator begin = l.begin();
	std::list<int>::iterator next = begin;
	next++;
	if (*begin > *next)
	{
		int tmp = *begin;
		*begin = *next;
		*next = tmp;
	}
}

void	insertSort(std::list<int> &l, unsigned long left, unsigned long right)
{
	std::list<int>::iterator i=l.begin();
	std::advance(i,left+1);
	std::list<int>::iterator rightIt=l.begin();
	std::advance(rightIt,right+1);
	for (i; i != rightIt; i++)
	{
		std::list<int>::iterator j = i;
		while (*j > *(.begin()+left) && *j < *(j - 1))
		{
			int tmp = *j;
			*j = *(j-1);
			*(j - 1) = tmp;
			j--;
		}
	}
}


void insertMergesort(std::list<int>& l, unsigned long left, unsigned long right, unsigned long k)
{
  if (right - left + 1 <= k) {
	insertSort(l, left, right);
  }
  else if (left < right) {
    int mid = (left + right) / 2;
    insertMergesort(l, left, mid, k);
    insertMergesort(l, mid + 1, right, k);
    std::list<int> leftSubArray(l.begin() + left, l.begin() + mid + 1);
    std::list<int> rightSubArray(l.begin() + mid + 1, l.begin() + right + 1);
    std::list<int> mergedSubarray = merge(leftSubArray, rightSubArray);
    std::copy(mergedSubarray.begin(), mergedSubarray.end(), l.begin() + left);
  }
}

//print the list
void	printlist(std::list<int> &l)
{
	for (unsigned long i = 0; i < l.size(); i++)
		std::cout << l[i] << " ";
	std::cout << std::endl;
}

//----------------------------------------------------------------------


int main(int argc, char const *argv[])
{
	clock_t start, end;
    start = clock();

	try
	{
	if (argc < 2)
	{
        throw   std::runtime_error("ERROR\n");
	}
	//take all the args, transform them to int and add them to the vector
	std::vector<int> v;
	std::cout << std::endl;
	    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        int n;
        ss >> n;
		if (!ss.eof() || ss.fail()) {
			throw   std::runtime_error("ERROR\n");
		}
		else {
			v.push_back(n);
		}
    }
	std::cout << "Before: ";
	printVector(v);
	if (v.size() == 2)
		insertSortTwo(v);
	else if (v.size() > 2)
		insertMergesort(v, 0, v.size() - 1, 2);
	std::cout << std::endl <<"After: ";
	printVector(v);
	std::cout << std::endl;
    end = clock();
    double	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector is: "<< cpu_time_used * pow(10,6) << " us" << std::endl;
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::endl;
	start = clock();

	end = clock();


	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}
