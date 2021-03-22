//
// Created by Moaney Terresa on 3/10/21.
//

#include "List.hpp"
#include <list>
#include "Iterator.hpp"

int main () {
//    ft::List<int> asd (6, 7);
//    std::list<std::string>::iterator it;
//    std::list<std::string>	l;
//    l.push_back("dhj");
//    it = l.begin();
//    it++;
//    it++;
//	ft::Node<int>			ptr(10);
//    ft::ListIterator<int>	it(&ptr);
//
//    std::cout << *it++ << "\n";
//	std::cout << *it << "\n";
//    std::string c = "fjkjd";
//    *reinterpret_cast<int*>(&c) += 102;
//    std::cout << c << std::endl;
//	-----------------------------------TEST_BACK----------------------------------
//	ft::List<int>	test;
//
//	test.push_back(10);
//	test.push_back(11);
//	test.push_back(12);
//	ft::List<int>	test2;
//	test2.push_back(2);
//	test2 = test;
//	ft::ListIterator<int>	it = test2.begin();
//	it++;
//	it++;
//	std::cout << *it << "\n";
//	ft::ListIterator<int>	it2 = test.end();
//	std::cout << *it2 << "\n";
//	-----------------------------------TEST_FRONT----------------------------------
	ft::List<int>	test3;
	ft::List<int>	test4;

	test3.push_front(1);
	test3.push_front(2);
	test3.push_front(3);
//	test3.pop_front();
//	test3.push_back(99);
	ft::ListIterator<int>	it = test3.begin();
	ft::ListIterator<int>	it2 = test3.end();

//	test4.assign(it, it2);
	size_t n = 1;
	test4.assign(n, 1);
	std::cout << test4.front() << std::endl;
	std::cout << test4.back() << std::endl;
//	std::cout << *it << std::endl;
//	it++;
//	std::cout << *it << std::endl;
//	test3.clear();
//	std::cout << test3.size() << std::endl;
//	it++;
//	test3.push_back(99);
//	std::cout << test3.front() << std::endl;
//	std::cout << test3.back() << std::endl;
//	it++;
//	std::cout << *it << std::endl;
//	it++;
//	std::cout << *it << std::endl;
//	it++;
//	if (test3.empty())
//		std::cout << test3.max_size() << "    " << test4.max_size() << std::endl;
	return (0);
}
