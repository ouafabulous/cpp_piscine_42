#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define NB_PUSH 1000000

int main()
{
	std::cout << "\nTESTS FROM SUBJECT :" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << s.size() << std::endl;



	// std::cout << "\nADDITIONNAL TESTS :\n" << std::endl;
	// std::cout << "Push and print stack :" << std::endl;
	// for (int i = 0 ; i < NB_PUSH ; i++) {
	// 	mstack.push(i);
	// }
	// for (MutantStack<int>::iterator it = mstack.begin() ; it < mstack.end() ; it++) {
	// 	std::cout << *it << "|";
	// }
	// std::cout << std::endl;

	// std::cout << "\n\nCOPY STACK AND PRINT IT :" << std::endl;
	// std::cout << "\nWith copy constructor :" << std::endl;
	// MutantStack<int> cpyConstructor(mstack);
	// for (MutantStack<int>::iterator it = cpyConstructor.begin() ; it < cpyConstructor.end() ; it++) {
	// 	std::cout << *it << "|";
	// }
	// std::cout << "\nWith assignement operator :" << std::endl;
	// MutantStack<int> cpyAssignation = mstack;
	// for (MutantStack<int>::iterator it = cpyAssignation.begin() ; it < cpyAssignation.end() ; it++) {
	// 	std::cout << *it << "|";
	// }

	return 0;
}
