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
	ft::Node<int>			ptr(10);
    ft::ListIterator<int>	it(&ptr);
    std::cout << *it++ << "\n";
	std::cout << *it << "\n";
//    std::string c = "fjkjd";
//    *reinterpret_cast<int*>(&c) += 102;
//    std::cout << c << std::endl;
	return (0);
}
