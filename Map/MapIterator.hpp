//
// Created by Moaney Terresa on 4/5/21.
//

#ifndef MAP_MAPITERATOR_HPP
#define MAP_MAPITERATOR_HPP

#include <iterator>
//#include "tree.hpp"
#include "new_tree.hpp"

namespace   ft {
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator {
		typedef T 			value_type;
		typedef Distance 	difference_type;
		typedef Pointer 	pointer;
		typedef Reference 	reference;
		typedef Category 	iterator_category;
	};

	template<class Key, class T>
	class MapIterator : public iterator<std::bidirectional_iterator_tag, T> {
	public:
		typedef Key key_type;
		typedef T value_type;
	private:
		avl_tree_node<Key, T>	*ptr;
		avl_tree<Key, T>		tree;
	public:
		MapIterator() : ptr(NULL) {}

		MapIterator(const MapIterator<Key, T> &cpy){
			*this = cpy;
		}

		MapIterator<Key, T> &operator=(const MapIterator<Key, T> &cpy) {
			if (this != &cpy) {
				this->ptr = cpy.ptr;
			}
			return *this;
		}

		MapIterator(avl_tree_node<Key, T> *ptr) {
			this->ptr = ptr;
		}

		~MapIterator() {}

		ft::pair<Key, T>	&operator*() const {
			return (ptr->pair);
		}
//
		ft::pair<Key, T>	*operator->() const {
			return (&ptr->pair);
		}
//
		MapIterator<Key, T> &operator++() {
			ptr = tree.min_to_max(ptr);
			return *this;
		}

		MapIterator<Key, T> operator++(int) {
			MapIterator<Key, T> cpy = *this;
			ptr = tree.min_to_max(ptr);
			return cpy;
		}

		MapIterator<Key, T> operator--() {
			ptr = tree.max_to_min(ptr);
			return *this;
		}

		MapIterator<Key, T> operator--(int) {
			MapIterator<Key, T> cpy = *this;
			ptr = tree.max_to_min(ptr);
			return cpy;
		}

		bool operator!=(const MapIterator<Key, T> &cpy) const {
			return !(this->ptr == cpy.ptr);
		}

		bool operator==(const MapIterator<Key, T> &cpy) const {
			return (this->ptr == cpy.ptr);
		}
	};

	template<class Iterator>
	class ReverseMapIterator : public iterator<std::bidirectional_iterator_tag, typename Iterator::value_type> {
	private:
		Iterator	n_it;
	public:
		typedef Iterator iterator_type;
		typedef typename Iterator::value_type	reference;
		ReverseMapIterator() {}
		explicit ReverseMapIterator(Iterator it) : n_it(it) {}
		template <class Iter>
		ReverseMapIterator(const ReverseMapIterator<Iter>& rev_it) {
			*this = rev_it;
		}
		ReverseMapIterator	&operator=(const ReverseMapIterator<Iterator> &cpy) {
			this->n_it = cpy.n_it;
			return *this;
		}
		iterator_type base() const  {
			return this->n_it;
		}
		ft::pair<typename Iterator::key_type, typename Iterator::value_type> &operator*() const {
			return *n_it;
		}

		ft::pair<typename Iterator::key_type, typename Iterator::value_type> *operator->() const {
			return &(operator*());
		}

		ReverseMapIterator& operator++() {
			--this->n_it;
			return *this;
		}

		ReverseMapIterator operator++(int) {
			ReverseMapIterator temp = *this;
			++(*this);
			return temp;
		}

		ReverseMapIterator& operator--() {
			++this->n_it;
			return *this;
		}

		ReverseMapIterator operator--(int) {
			ReverseMapIterator temp = *this;
			--(*this);
			return temp;
		}
	};

	template <class Iterator>
	ptrdiff_t operator- (const ReverseMapIterator<Iterator>& lhs, const ReverseMapIterator<Iterator>& rhs) {
		ptrdiff_t n = 0;
		ReverseMapIterator<Iterator> tmp = lhs;
		while (tmp != rhs) {
			tmp++;
			n++;
		}
		return n;
	}
	template <class Iterator>
	bool operator== (const ReverseMapIterator<Iterator>& lhs,
					 const ReverseMapIterator<Iterator>& rhs) {
		return  lhs.base() == rhs.base();
	}
	template <class Iterator>
	bool operator!= (const ReverseMapIterator<Iterator>& lhs,
					 const ReverseMapIterator<Iterator>& rhs) {
		return !(lhs == rhs);
	}

	template <class Iterator>
	bool operator<  (const ReverseMapIterator<Iterator>& lhs,
					 const ReverseMapIterator<Iterator>& rhs) {
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool operator<= (const ReverseMapIterator<Iterator>& lhs,
					 const ReverseMapIterator<Iterator>& rhs) {
		return (lhs == rhs || lhs < rhs);
	}

	template <class Iterator>
	bool operator>  (const ReverseMapIterator<Iterator>& lhs,
					 const ReverseMapIterator<Iterator>& rhs) {
		return !(lhs <= rhs);
	}

	template <class Iterator>
	bool operator>= (const ReverseMapIterator<Iterator>& lhs,
					 const ReverseMapIterator<Iterator>& rhs) {
		return !(lhs < rhs);
	}
}

#endif //MAP_MAPITERATOR_HPP
