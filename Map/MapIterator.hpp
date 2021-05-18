//
// Created by Moaney Terresa on 4/5/21.
//

#ifndef MAP_MAPITERATOR_HPP
#define MAP_MAPITERATOR_HPP

#include <iterator>
#include "NodeMap.hpp"

namespace   ft {
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator {
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template<class Key, class T>
	class MapIterator : public iterator<std::bidirectional_iterator_tag, T> {
	private:
		NodeMap <Key, T> *ptr;
	public:
		MapIterator() {
			ptr = NULL;
		}

		MapIterator<Key, T> &operator=(const MapIterator<Key, T> &cpy) {
			if (this != &cpy) {
				this->ptr = cpy.ptr;
			}
			return *this;
		}

		MapIterator(NodeMap <Key, T> *ptr) {
			this->ptr = ptr;
		}

		~MapIterator() {}

		T &operator*() const {
			return (this->ptr->second);
		}
//
		NodeMap<Key, T> *operator->() const {
			return (this->ptr);
		}
//
//		Key &operator->(Key key) const {
//			return &(this->ptr->first);
//		}

//		MapIterator<Key, T> operator++(int) {
//			MapIterator<Key, T> old = *this;
//
//			if ()
//
//			return (old);
//		}
//
		MapIterator<Key, T> operator++() {
			if (this->ptr->right && this->ptr->right->first > this->ptr->first) {
				this->ptr = this->ptr->right;
				while (this->ptr->left)
					this->ptr = this->ptr->left;
			}
			else if (this->ptr->parent && this->ptr->parent->first > this->ptr->first)
				this->ptr = this->ptr->parent;
			else if (this->ptr->parent->first < this->ptr->first) {
				Key tmp = this->ptr->first;
				while (this->ptr->parent) {
					this->ptr = this->ptr->parent;
					if (this->ptr->first > tmp)
						return *this;
					if (this->ptr->right->first > tmp)
						return MapIterator<Key, T>(this->ptr = this->ptr->right);
				}
			}

			else
				return NULL;
			return *this;
		}
//
//		MapIterator<Key, T> operator--(int) {
//			MapIterator<Key, T> old = *this;
//			this->ptr = ptr->prev;
//			return (old);
//		}
//
//		MapIterator<Key, T> operator--() {
//			this->ptr = ptr->prev;
//			return (*this);
//		}

		bool operator!=(const MapIterator<Key, T> &cpy) const {
			return (this->ptr != cpy.ptr);
		}

		bool operator==(const MapIterator<Key, T> &cpy) const {
			return (this->ptr == cpy.ptr);
		}

		NodeMap <Key, T> *getPtr() {
			return ptr;
		}
	};
}

#endif //MAP_MAPITERATOR_HPP
