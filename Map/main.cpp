#include <iostream>
#include "Map.hpp"
#include <string>
#include <map>
#include <list>

int main() {
//	std::map<int, std::string>		test;
//	test.insert ( std::pair<int,std::string>(1,"1") );
//	test.insert ( std::pair<int,std::string>(10,"10") );
//	test.insert ( std::pair<int,std::string>(5,"5") );
//	test.insert ( std::pair<int,std::string>(3,"3") );
//	test.insert ( std::pair<int,std::string>(11,"11") );
//	test.insert ( std::pair<int,std::string>(2,"yy") );
//	auto	it = test.begin();
//	auto	it2 = test.end();
//	for (; it != it2; ++it)
//		std::cout << (*it).first << std::endl;
//	{
//		std::list<int> test2;
//		test2.push_back(1);
//		std::list<int>::iterator  it = test2.begin();
//
//	}
	{
		ft::Map<int, std::string> my_test;
		my_test.insert(std::pair<int, std::string>(100, "100"));
		std::cout << "--1-" << std::endl;
		my_test.insert(std::pair<int, std::string>(90, "90"));
		std::cout << "--2-" << std::endl;
		my_test.insert(std::pair<int, std::string>(8, "8"));
		std::cout << "--3-" << std::endl;
//		my_test.insert(std::pair<int, std::string>(15, "15"));
		auto it = my_test.begin();
		std::cout << it->second << std::endl;
		++it;
		std::cout << it->second << std::endl;
		++it;
		std::cout << it->second << std::endl;
//		++it;
//		std::cout << it->second << std::endl;



	}

	return 0;
}
