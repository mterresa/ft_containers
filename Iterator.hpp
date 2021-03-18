//
// Created by Moaney Terresa on 3/11/21.
//

#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP

#include <iterator>
#include "Node.hpp"

namespace   ft {
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator {
		typedef T 			value_type;
		typedef Distance 	difference_type;
		typedef Pointer 	pointer;
		typedef Reference 	reference;
		typedef Category 	iterator_category;
	};

	template<class T>
	class ListIterator : public iterator<std::bidirectional_iterator_tag, T> {
	private:
		Node<T>		*ptr;
	public:
		ListIterator() {
			ptr = NULL;
		}
		ListIterator(const Node<T> *ptr) {
			this->ptr = ptr;
		}
		~ListIterator() {}
		T	&operator*() {
			return (this->ptr->data);
		}
		ListIterator<T>		operator++(int) {
			ListIterator<T> old = *this;
			this->ptr++;
			return(old);
		}
		ListIterator<T>	operator++() {
			this->ptr++;
			return(*this);
		}
		ListIterator<T>	operator--(int) {
			ListIterator<T> old = *this;
			this->ptr--;
			return(old);
		}
		ListIterator<T>	operator--() {
			this->ptr--;
			return(*this);
		}
		T	&operator->() {
			return &(this->ptr->data);
		}
		bool		operator!=(const ListIterator<T> &cpy) {
			return (this->ptr != cpy.ptr);
		}
		bool		operator==(const ListIterator<T> &cpy) {
			return (this->ptr == cpy.ptr);
		}
	};
}

#endif //FT_CONTAINERS_ITERATOR_HPP
