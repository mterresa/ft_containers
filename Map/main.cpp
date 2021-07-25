#include <iostream>
//#include "Map.hpp"
#include <string>
#include <map>
#include <list>
#include "tree.hpp"
#include "MapIterator.hpp"
#include "Map.hpp"

int main() {
//	std::map<int, int>	test;
//	std::cout << test.end()->first << std::endl;
	ft::tree<int, int>	test;
	test.NodeCreate(ft::make_pair<int, int>(500, 500));
	test.NodeCreate(ft::make_pair<int, int>(400, 400));
	test.NodeCreate(ft::make_pair<int, int>(450, 450));
	test.NodeCreate(ft::make_pair<int, int>(700, 700));
//	test.NodeDelete(500);
	ft::Map<int, int> map;
	map.insert(ft::make_pair<int, int>(500, 500));
	map.insert(ft::make_pair<int, int>(400, 500));
	map.insert(ft::make_pair<int, int>(450, 500));
	map.insert(ft::make_pair<int, int>(700, 500));
	ft::MapIterator<int, int> it(test.min);
	ft::Map<int, int>::iterator it1 = map.begin();
	std::cout << (*it1).first << std::endl;
	++it1;
	std::cout << it1->first << std::endl;
	it1++;
	std::cout << it1->first << std::endl;
	it1++;
	std::cout << it1->first << std::endl;
	it1++;
	ft::MapIterator<int, int> it2 = map.end();
	std::cout << std::boolalpha << (it1 == map.end()) << "_________" << it1->first << &it1 << &it2 << std::endl;
//	ft::Map<int, int> map1(map.begin(), map.end());

//	map.erase(map.begin());
	std::cout << (*it).first << std::endl;
	++it;
	std::cout << (*it).first << std::endl;
	++it;
	std::cout << (*it).first << std::endl;
	++it;
	std::cout << (*it).first << std::endl;
	++it;
	std::cout << (*it).first << std::endl;
	++it;
	std::cout << (*it).first << std::endl;
//	++it;
	return 0;
}
