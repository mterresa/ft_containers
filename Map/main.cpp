#include <iostream>
//#include "Map.hpp"
#include <string>
#include <map>
#include <list>
//#include "tree.hpp"
#include "MapIterator.hpp"
#include "Map.hpp"

int main() {
//	std::cout << test.end()->
//	first << std::endl;
//	test.NodeDelete(500);
		ft::Map<int, int> map;
		std::cout << "-----" << std::endl;
		map.insert(ft::make_pair<int, int>(500, 500));
		map.insert(ft::make_pair<int, int>(400, 500));
		map.insert(ft::make_pair<int, int>(450, 500));
		map.insert(ft::make_pair<int, int>(700, 500));
		std::cout << "-----" << std::endl;
		ft::Map<int, int>::iterator it1 = map.begin();
		ft::Map<int, int>::reverse_iterator it5 = map.rbegin();
		std::cout << (*it5).first << std::endl;
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
	return 0;
}
