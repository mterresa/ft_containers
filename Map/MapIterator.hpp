//
// Created by Moaney Terresa on 4/5/21.
//

#ifndef MAP_MAPITERATOR_HPP
#define MAP_MAPITERATOR_HPP

#include <iterator>
#include "tree.hpp"

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
	private:
		NodeMap <Key, T> *ptr;
		tree<Key, T>	tree;
	public:
		MapIterator() : tree() {
			ptr = tree.end;
		}

		MapIterator(const MapIterator<Key, T> &cpy) : tree(cpy.tree) {
			*this = cpy;
		}

		MapIterator<Key, T> &operator=(const MapIterator<Key, T> &cpy) {
			if (this != &cpy) {
				this->ptr = cpy.ptr;
				this->tree = cpy.tree;
			}
			return *this;
		}

		MapIterator(NodeMap<Key, T> *ptr) : tree(ptr) {
			this->ptr = ptr;
		}

		~MapIterator() {}

		ft::pair<Key, T>	&operator*() const {
			return (ptr->m_pair);
		}
//
		ft::pair<Key, T>	*operator->() const {
			return (&ptr->m_pair);
		}
//
		MapIterator<Key, T> &operator++() {
			if (this->ptr->first == tree.max->first)
				this->ptr = tree.end;
			else if (this->ptr == tree.end)
				this->ptr = tree.min;
			else if (this->ptr->right && this->ptr->right->first > this->ptr->first) {
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
					if (this->ptr->right->first > tmp) {
						this->ptr = this->ptr->right;
						break;
					}
				}
			}
			return *this;
		}

		MapIterator<Key, T> operator++(int) {
			MapIterator<Key, T> cpy = ptr;
			if (this->ptr->first == tree.max->first)
				this->ptr = tree.end;
			else if (this->ptr == tree.end)
				this->ptr = tree.min;
			else if (this->ptr->right && this->ptr->right->first > this->ptr->first) {
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
						return cpy;
					if (this->ptr->right->first > tmp) {
						this->ptr = this->ptr->right;
						break;
					}
				}
			}
			return cpy;
		}

		MapIterator<Key, T> operator--() {
			if (this->ptr->first == tree.min->first)
				return this->ptr = tree.end;
			else if (this->ptr == tree.end)
				return this->ptr = tree.max;
			else if (this->ptr->left && this->ptr->left->first < this->ptr->first) {
				this->ptr = this->ptr->left;
				while (this->ptr->right)
					this->ptr = this->ptr->right;
			}
			else if (this->ptr->parent && this->ptr->parent->first < this->ptr->first)
				this->ptr = this->ptr->parent;
			else if (this->ptr->parent->first > this->ptr->first) {
				Key tmp = this->ptr->first;
				while (this->ptr->parent) {
					this->ptr = this->ptr->parent;
					if (this->ptr->first < tmp)
						return *this;
					if (this->ptr->left->first < tmp)
						return this->ptr = this->ptr->left;
				}
			}
			else
				return NULL;
			return *this;
		}

		MapIterator<Key, T> operator--(int) {
			MapIterator<Key, T> cpy = ptr;
			if (this->ptr->first == tree.min->first)
				this->ptr = tree.end;
			else if (this->ptr == tree.end)
				this->ptr = tree.max;
			else if (this->ptr->left && this->ptr->left->first < this->ptr->first) {
				this->ptr = this->ptr->left;
				while (this->ptr->right)
					this->ptr = this->ptr->right;
			}
			else if (this->ptr->parent && this->ptr->parent->first < this->ptr->first)
				this->ptr = this->ptr->parent;
			else if (this->ptr->parent->first > this->ptr->first) {
				Key tmp = this->ptr->first;
				while (this->ptr->parent) {
					this->ptr = this->ptr->parent;
					if (this->ptr->first < tmp)
						return cpy;
					if (this->ptr->left->first < tmp) {
						this->ptr = this->ptr->left;
						break;
					}
				}
			}
			else
				return NULL;
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
		reference &operator*() const {
			return *n_it;
		}

		reference *operator->() const {
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
