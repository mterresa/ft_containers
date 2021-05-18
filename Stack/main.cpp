#include <iostream>
#include "Stack.hpp"

int main() {
	{
		ft::Stack<int> mystack;
		for (int i = 0; i < 5; ++i) mystack.push(i);
		std::cout << "Popping out elements...";
		while (!mystack.empty()) {
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	{
		ft::Stack<int> mystack;
		int sum (0);
		for (int i=1;i<=10;i++) mystack.push(i);
		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << "total: " << sum << '\n';
	}
	{
		ft::Stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';
		for (int i = 0; i < 5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';
		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	{
		ft::Stack<int> mystack;
		mystack.push(10);
		mystack.push(20);
		mystack.top() -= 5;
		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	{
		ft::Stack<int> mystack;
		for (int i=0; i<5; ++i) mystack.push(i);
		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	return 0;
}
