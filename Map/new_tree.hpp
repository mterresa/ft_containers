#pragma once

#include <cstddef>
#include <cstdio>
#include <ios>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>

namespace ft {

	/*
		FT::PAIR
	*/

	template <class Key, class Value>
	class	pair {
	public:
		typedef Key first_type;
		typedef Value second_type;
		first_type	first;
		second_type	second;
	public:
		pair() {}
		template<class U, class V>
		pair(const pair<U,V>& pr) : first(static_cast<U>(pr.first)), second(static_cast<V>(pr.second)) {}
		pair (const first_type& a, const second_type& b) : first(a), second(b) {}
		pair	&operator=(const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first==rhs.first && lhs.second==rhs.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs==rhs);
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs<lhs);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return rhs<lhs;
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs<rhs);
	}

	template <class T1, class T2>
	pair<T1,T2>	make_pair(T1 x, T2 y) {
		return ft::pair<T1, T2>(x, y);
	}

	/*
		FT::LESS
	*/

	template <class T>
	struct less : std::binary_function<T,T,bool> {
		typedef T first_argument_type;
		typedef T second_argument_type;
		typedef bool result_type;
		bool	operator()(const T& x, const T& y) const {
			return x < y;
		}
	};

	/*
		MAP_NODE
	*/

	template <class Key, class T, class Alloc = std::allocator<ft::pair<Key, T> > >
	class	avl_tree_node {
	public:
		Key		first;
		T		second;
		ft::pair<Key, T>	pair;
		avl_tree_node*	parent;
		avl_tree_node*	left;
		avl_tree_node*	right;
		avl_tree_node*	end;
	public:
		avl_tree_node(ft::pair<Key, T>& pair, avl_tree_node* parent,avl_tree_node* left, avl_tree_node* right) : parent(parent), left(left), right(right) {}
		avl_tree_node() : parent(NULL), left(NULL), right(NULL), end(NULL) {}
		avl_tree_node&	operator=(const avl_tree_node& node) {
			this->first = node.first;
			this->second = node.second;
			this->pair = node.pair;
			this->parent = node.parent;
			this->left = node.left;
			this->right = node.right;
			this->end = node.end;
			return *this;
		}
	};

	/*
		AVL_TREE
	*/

	template <class Key, class T, class Node_Alloc = std::allocator<avl_tree_node<Key, T> > >
	class	avl_tree {
	public:
		typedef Key first_type;
		typedef T second_type;
		typedef avl_tree_node<first_type, second_type> node;
		typedef ft::pair<first_type, second_type> pair;
		typedef Node_Alloc allocator_type;
	private:
		allocator_type	_alloc;
	public:
		node	*create_node(pair new_pair, node* end) {
			node*	new_node = _alloc.allocate(1);
			_alloc.construct(new_node, node());
			new_node->pair = new_pair;
			new_node->first = new_pair.first;
			new_node->second = new_pair.second;
			new_node->end = end;
			return new_node;
		}

		bool	insert(node** root, node* new_node) {
			if (*root == NULL) {
				*root = new_node;
				new_node->end->parent = *root;
			}
			else {
				node*	tmp = *root;
				while (tmp) {
					if (tmp->first == new_node->first) {
						if (tmp != new_node)
							delete_node(new_node);
						return false;
					}
					else if (new_node->first > tmp->first) {
						if (tmp->right)
							tmp = tmp->right;
						else {
							tmp->right = new_node;
							new_node->parent = tmp;
							break;
						}
					}
					else {
						if (tmp->left)
							tmp = tmp->left;
						else {
							tmp->left = new_node;
							new_node->parent = tmp;
							break;
						}
					}
				}
			}
			return true;
		}

		node*	min_node(node* n, bool root = true) {
			if (n) {
				if (root) {
					while (n->parent)
						n = n->parent;
				}
				while (n->left)
					n = n->left;
			}
			return n;
		}

		node*	max_node(node* n, bool root = true) {
			if (n) {
				if (root) {
					while (n->parent)
						n = n->parent;
				}
				while (n->right)
					n = n->right;
			}
			return n;
		}

		void	delete_node(node* n) {
			if (n) {
				_alloc.destroy(n);
				_alloc.deallocate(n, 1);
			}
		}

		node*	find_node(node** root, first_type key) const {
			node*	tmp = *root;
			while (tmp) {
				if (tmp->first == key)
					return tmp;
				else if (key > tmp->first) {
					if (tmp->right)
						tmp = tmp->right;
					else
						break;
				}
				else {
					if (tmp->left)
						tmp = tmp->left;
					else
						break;
				}
			}
			return NULL;
		}

		bool	erase(node** root, first_type key) {
			node*	remove = find_node(root, key);
			bool	ret = false;
			if (remove) {
				node*	replace = NULL;
				ret = true;
				if (remove->left)
					replace = erase_left(remove);
				else
					replace = erase_right(remove);
				if (replace) {
					remove->first = replace->first;
					remove->second = replace->second;
					remove->pair = replace->pair;
				}
				else
					replace = remove;
				if (replace == remove && remove == *root)
					ret = false;
				delete_node(replace);
				return ret;
			}
			return ret;
		}

		node*	erase_left(node* n) {
			node*	replace = max_node(n->left, false);
			if (replace) {
				if (replace == n->left) {
					n->left = replace->left;
					if (replace->left) {
						replace->left->parent = n;
					}
				}
				else {
					node*	left = min_node(replace->left, false);
					if (left) {
						left->left = n->left;
						if (left->left)
							left->left->parent = left;
						n->left = left;
						left->parent = n;
					}
					if (replace->parent) {
						replace->parent->right = NULL;
					}
				}
			}
			return replace;
		}

		node*	erase_right(node* n) {
			node*	replace = min_node(n->right, false);
			if (replace) {
				if (replace == n->right) {
					n->right = replace->right;
					if (replace->right)
						replace->right->parent = n;
				}
				else {
					node*	right = max_node(replace->right, false);
					if (right) {
						right->right = n->right;
						if (right->right)
							right->right->parent = right;
						n->right = right;
						right->parent = n;
					}
					if (replace->parent)
						replace->parent->left = NULL;
				}
			}
			return replace;
		}

		node*	min_to_max(node* n) {
			if (n) {
				if (!n->end)
					n = min_node(n->parent);
				else if (n == max_node(n))
					n = n->end;
				else if (n->right)
					n = min_node(n->right, false);
				else if (n->parent) {
					while (n->parent->right == n)
						n = n->parent;
					n = n->parent;
				}
			}
			return n;
		}

		node*	max_to_min(node* n) {
			if (n) {
				if (n == n->end)
					n = max_node(n->parent);
				else if (n == min_node(n))
					n = n->end;
				else if (n->left)
					n = max_node(n->left, false);
				else if (n->parent) {
					while (n->parent->left == n)
						n = n->parent;
					n = n->parent;
				}
			}
			return n;
		}

		void	clear(node* n, bool root = true) {
			if (n && n->end) {
				if (root) {
					while (n->parent)
						n = n->parent;
				}
				node*	end = n->end;
				while (erase(&n, n->first)) {}
				delete_node(end);
			}
		}
		size_t 		max_size() const {
			return static_cast<size_t>(_alloc.max_size());
		}
	};

}