#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>

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
	return v;
}

//sort a vector of 2 elements
void	insertSortTwo(std::vector<int> v)
{
	if (v[0] > v[1])
	{
		int tmp = v[0];
		v[0] = v[1];
		v[1] = tmp;
	}
}

void	insertSort(std::vector<int> v)
{
	for (unsigned long i = 1; i < v.size(); i++)
	{
		unsigned long j = i;
		while (j > 0 && v[j] < v[j - 1])
		{
			int tmp = v[j];
			v[j] = v[j - 1];
			v[j - 1] = tmp;
			j--;
		}
	}
}

void	insertMergesort(std::vector<int> v, int left, int right, unsigned long k)
{
	if (v.size() == k)
	{
		if (k == 2)
			insertSortTwo(v);
		else
			insertSort(v);
	}
	else
	{
		int mid = (left + right) / 2;
		insertMergesort(v, left, mid, k);
		insertMergesort(v, mid + 1, right, k);
		std::vector<int> leftSubArray(v.begin(), v.begin() + mid + 1);
		std::vector<int> rightSubArray(v.begin() + mid + 1, v.end());
		std::vector<int> mergedSubarray = merge(leftSubArray, rightSubArray);
		std::copy(mergedSubarray.begin(), mergedSubarray.end(), v.begin() + left);
	}
}

//print the vector
void	printVector(std::vector<int> v)
{
	for (unsigned long i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	clock_t start, end;
    start = clock();
	//if no int is given, throw an errorcontact@42entrepreneurs.fr

	try
	{
	if (argc < 2)
	{
        throw   std::runtime_error("ERROR\n");
	}
	//take all the args, transform them to int and add them to the vector
	std::vector<int> v;
	std::cout << "Before: ";
	printVector(v);
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
	//sort the vector
	insertMergesort(v, 0, v.size() - 1, 2);
	//print the vector
	std::cout << "After: ";
	printVector(v);
	std::cout << std::endl;
    end = clock();
    double	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of" << argc - 1 << " elements with std::vector: "<< cpu_time_used * pow(10,6) << " us" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}
