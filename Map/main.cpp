#include <iostream>
//#include "Map.hpp"
#include <string>
#include <map>
#include <list>
//#include "tree.hpp"

int main() {
	std::map<int, int>	test;
	std::cout << std::boolalpha << test.insert(std::pair<int, int>(1,2)).second;
	std::cout << std::boolalpha << test.insert(std::pair<int, int>(2,2)).second;
	return 0;
}
