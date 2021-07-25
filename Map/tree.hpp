//
// Created by Moaney Terresa on 7/21/21.
//

#ifndef MAP_TREE_HPP
#define MAP_TREE_HPP

//#include "Map.hpp"

namespace ft{
	template<typename Key, typename  T>
	class pair {
	public:
		Key				first;
		T				second;
		typedef Key 	first_type;
		typedef T		second_type;
		pair() {}
		template<class U, class V>
		pair (const pair<U,V>& pr) {
			*this = pr;
		};
		pair (const first_type& a, const second_type& b) : first(a), second(b){};
		pair& operator= (const pair& pr) {
			this->first = static_cast<first_type>(pr.first);
			this->second = static_cast<second_type>(pr.second);
			return *this;
		};

	};
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}

	template<typename Key, typename  T>
	class NodeMap {
	public:
		T		second;
		Key		first;
		ft::pair<Key, T> m_pair;
		NodeMap *parent;
		NodeMap *left;
		NodeMap *right;
		bool 	is_left;

	public:
		explicit NodeMap(const Key &key = Key(), const T &val = T(),const  ft::pair<Key, T>&tmp = ft::pair<Key, T>()) : second(val), parent(0), left(0), right(0), first(key), m_pair(tmp) {}
		NodeMap *getParent() {
			return (parent);
		}
		Key		getFirst() {
			return first;
		}
	};

	template<typename Key, typename  T>
	class tree {
	private:
		NodeMap<Key, T> 					*m_node;
		std::allocator<NodeMap<Key, T> > 	*_alloc;
	public:
		NodeMap<Key, T> 					*max;
		NodeMap<Key, T> 					*min;
		NodeMap<Key, T> 					*end;
		size_t 								size;
		tree() : m_node(NULL), max(NULL), min(NULL), end(NULL) {
			NodeCreate(ft::make_pair<Key, T>(Key(), T()));
			end = m_node;
			m_node = max = min = NULL;
			size = 0;
		};
		tree(NodeMap<Key, T> *ptr) : m_node(NULL), max(NULL), min(NULL), end(NULL) {
			NodeCreate(ft::make_pair<Key, T>(Key(), T()));
			end = m_node;
			m_node = max = min = NULL;
			while (ptr->parent)
				ptr = ptr->parent;
			m_node = ptr;
			while (ptr->right)
				ptr = ptr->right;
			max = ptr;
			ptr = m_node;
			while (ptr->left)
				ptr = ptr->left;
			min = ptr;
			size = 0;
		}

		void 	clear() {
			while (m_node)
				NodeDelete(m_node->first);
//			NodeDelete(end->first);
		}

		typedef NodeMap<Key, T>				*node;

		bool	NodeCreate(const ft::pair<Key, T> &node) {
			NodeMap<Key, T>*	root;
			NodeMap<Key, T> *new_node = _alloc->allocate(1, 0);
			NodeMap<Key, T> tmp(node.first, node.second, node);
			_alloc->construct(new_node, tmp);
			return this->NodePaste(new_node,  root);
		};

		bool	NodePaste(node paste_node, node root) {
			if (root == NULL)
				root = paste_node;
			else {
				node	tmp = root;
				while (tmp) {
					if (paste_node->first == tmp->first) {
						_alloc->destroy(paste_node);
						_alloc->deallocate(paste_node, 1);
						return false;
					}
					else if (paste_node->first < tmp->first && !tmp->left) {
						tmp->left = paste_node;
						paste_node->parent = tmp;
						paste_node->is_left = true;
						break;
					}
					else if (paste_node->first < tmp->first) {
						tmp = tmp->left;
						continue;
					}
					else if (paste_node->first > tmp->first && !tmp->right) {
						tmp->right = paste_node;
						paste_node->parent = tmp;
						paste_node->is_left = false;
						break;
					}
					else if (paste_node->first > tmp->first) {
						tmp = tmp->right;
						continue;
					}
				}
			}
			size++;
			return true;
		}

		void	NodeDelete(Key delete_node, node root) {
			node	tmp = root;
			while (tmp) {
				if (delete_node == tmp->first) {
					this->FindReplace(tmp);
					_alloc->destroy(tmp);
					_alloc->deallocate(tmp, 1);
					break;
				}
				else if (delete_node < tmp->first) {
					tmp = tmp->left;
					continue;
				}
				else if (delete_node > tmp->first) {
					tmp = tmp->right;
					continue;
				}
			}
		}

		size_t	max_size() {
			_alloc->max_size();
		}

		void	FindReplace(node cpy, node root) {
			node copycpy;
			if (cpy->left) {
				copycpy = cpy->left;
				while (copycpy->right)
					copycpy = copycpy->right;
				if (!cpy->parent)
					this->root = copycpy;
				else if (cpy->is_left)
					cpy->parent->left = copycpy;
				else
					cpy->parent->right = copycpy;
				copycpy->parent = cpy->parent;
			}
			else if (cpy->right) {
				copycpy = cpy->right;
				while (copycpy->left)
					copycpy = copycpy->left;
				if (!cpy->parent)
					this->root = copycpy;
				else if (cpy->is_left)
					cpy->parent->left = copycpy;
				else
					cpy->parent->right = copycpy;
				copycpy->parent = cpy->parent;
			}
			else {
				if (!cpy->parent)
					this->root = NULL;
				else if (cpy->is_left)
					cpy->parent->left = NULL;
				else
					cpy->parent->right = NULL;
			}
			if (root == cpy) {
				*root = *copycpy;
				root->parent = NULL;
			}
		}

		node	FindNode(Key fnd) {
			node	tmp = m_node;
			while (tmp) {
				if (fnd == tmp->first) {
					return tmp;
				}
				else if (fnd < tmp->first) {
					tmp = tmp->left;
					continue;
				}
				else if (fnd > tmp->first) {
					tmp = tmp->right;
					continue;
				}
			}
			return NULL;
		}
		tree	&operator=(const tree &cpy) {
			this->clear();
			this->m_node = cpy.m_node;
			this->_alloc = cpy._alloc;
			this->end = cpy.end;
			this->max = cpy.max;
			this->min = cpy.min;
			this->size = cpy.size;
			return *this;
		}
	};
}


#endif //MAP_TREE_HPP
