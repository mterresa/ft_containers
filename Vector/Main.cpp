//
// Created by Moaney Terresa on 3/30/21.
//

#include "Vector.hpp"
#include <vector>

int main() {
//	{
//		ft::Vector<int> test(5, 1);
//		std::cout << test.size() << std::endl;
//		test.clear();
//		test.push_back(99);
//
//		std::cout << test.size() << std::endl;
//		std::vector<int> test2(5, 1);
//		test2.pop_back();
//		test2.pop_back();
//
//		std::cout << test2[4] << std::endl;
//	}
//	___________ASSIGN_TEST_______________
	{
		std::vector<int>	test;
		ft::Vector<int>		my_test;
		ft::Vector<int>::iterator  my_it_begin = my_test.begin();
		std::vector<int>::iterator  it_begin = test.begin();

		test.insert(it_begin, 50, 5);
		test.insert(test.begin(), 12, 5);
		my_test.insert(my_it_begin, 50, 5);
		my_test.insert(my_test.begin(), 12, 5);


		std::cout << "vector" << " capacity: " << test.capacity() << std::endl;
		std::cout << "my_vector" << " capacity: " << my_test.capacity() << std::endl;


		test.push_back(2);
		my_test.push_back(2);
		test.push_back(1);
		my_test.push_back(1);
		std::cout << "vector" << " capacity: " << test.capacity() << std::endl;
		std::cout << "my_vector" << " capacity: " << my_test.capacity() << std::endl;

		std::vector<int>::reverse_iterator it = test.rbegin();
		std::cout << "rev " << *it << " " << it[1] << std::endl;
		ft::Vector<int>::reverse_iterator it2 = my_test.rbegin();
		std::cout << "rev " << *it2 << " " << it2[1] << std::endl;
//		for (int i = 0; i < 2; ++i)
//			my_test.push_back(0);
//		for (int i = 0; i < 4; ++i)
//			my_test2.push_back(1);
//		std::vector<int>::iterator  it_begin = test.begin();
//		std::vector<int>::iterator  it_end = test.end();
//		my_test.assign(it_begin, it_end);
//		ft::Vector<int>::iterator  my_it_begin = my_test.begin();
//		ft::Vector<int>::iterator  my_it_end = my_test.end();

//		my_test.insert(my_it_begin, it_begin, it_end);

//		my_test.swap(my_test2);
//
//		my_it_begin = my_test.begin();
//		my_it_end = my_test.end();
//		for (; my_it_begin != my_it_end; ++my_it_begin)
//			std::cout<< "|" << *my_it_begin << "| - 1" << std::endl;
//		std::cout << "1 size = " << my_test.size() << std::endl;
//
//		my_it_begin = my_test2.begin();
//		my_it_end = my_test2.end();
//		for (; my_it_begin != my_it_end; ++my_it_begin)
//			std::cout<< "|" << *my_it_begin << "| - 2" << std::endl;
//
//		std::cout << "2 size = " << my_test2.size() << std::endl;

	}
	return (0);
}