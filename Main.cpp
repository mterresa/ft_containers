//
// Created by Moaney Terresa on 3/10/21.
//

#include "List.hpp"
#include <list>
#include "Iterator.hpp"

bool single_digit (const int& value) { return (value>10); }

bool same_integral_part (int first, int second)
{ return ( first > second ); }

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

	test3.push_back(1);
	test3.push_back(4);
	test3.push_back(2);
	test3.push_back(9);
	test3.push_back(17);
	test3.push_back(3);
//	test3.pop_front();
//	test3.push_back(99);
//	test3.resize(5, 5);
//	test3.unique(same_integral_part);
	test3.sort(same_integral_part);
	ft::ListIterator<int>	it = test3.begin();
	ft::ListIterator<int>	it2 = test3.end();

//	test4.push_back(99);
//	test4.push_back(100);
//	test3.swap(test4);
//	ft::ListIterator<int>	it = test3.begin();
//	ft::ListIterator<int>	it2 = test3.end();

//	ft::ListIterator<int>	it4 = test4.begin();
//	ft::ListIterator<int>	it5 = test4.end();
//	it4++;
//	test4.splice(it4, test3, it);
//	it = test3.begin();
//	it2 = test3.end();
	while (it != it2) {
		std::cout << *it << " ";
		it++;
	}
//	it++;
//	std::cout << "size = " <<test3.size() <<"\n";
//	test4.remove(99);
//	test4.remove_if(single_digit);
//	it4 = test4.begin();
//	it5 = test4.end();
//
//	while (it4 != it5) {
//		std::cout << *it4 << " ";
//		it4++;
//	}
//	std::cout << "size = " <<test4.size() <<"\n";

//	test3.erase(it);
//	it = test3.begin();
//	std::cout << *it << std::endl;
//	//---------
//	std::list<int>		er;
//	er.push_back(1);
//	er.push_back(2);
//	std::list<int>::iterator		sts = er.begin();
//	er.erase(sts);
//	sts = er.begin();
//	std::cout << *sts << std::endl;
	//----------
//	test4.assign(it, it2);
//	size_t n = 1;
//	test4.assign(1, 1);
//	ft::ListIterator<int>	it3 = test4.begin();
//	it3++;
//	test4.insert(it3, 2, 99);
//
//	std::cout << *it3 << std::endl;
//	std::cout << test4.size() << std::endl;
//	std::list<int>		st;
//	st.push_back(8);
//	std::list<int>::iterator		sts = st.begin();
//	st.insert(sts, 2);
//	std::cout << *sts << std::endl;
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
