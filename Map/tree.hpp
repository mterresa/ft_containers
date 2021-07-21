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
		bool 	is_red;
		bool 	is_left;

	public:
		explicit NodeMap(const Key &key = Key(), const T &val = T(), ft::pair<Key, T>&tmp = ft::pair<Key, T>()) : second(val), parent(0), left(0), right(0), is_red(true), first(key), m_pair(tmp) {}
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
		int									hight;
		std::allocator<NodeMap<Key, T> > 	*_alloc;
	public:
		tree() : m_node(NULL) {};
		typedef NodeMap<Key, T>				*node;
		bool	NodeCreate(ft::pair<Key, T> node) {
			NodeMap<Key, T> *new_node = _alloc->allocate(1, 0);
			NodeMap<Key, T> tmp(node.first, node.second, node);
			_alloc->construct(new_node, tmp);
			return this->NodePaste(new_node);
		};
		bool	NodePaste(node paste_node) {
			if (m_node == NULL)
				m_node = paste_node;
			else {
				node	tmp = m_node;
				while (tmp) {
					if (paste_node->first == tmp->first) {
						_alloc->destroy(paste_node);
						_alloc->deallocate(paste_node, 1);
						std::cout << "delete " << tmp->first << std::endl << std::endl;
						return false;
					}
					else if (paste_node->first < tmp->first && !tmp->left) {
						tmp->left = paste_node;
						paste_node->parent = tmp;
						paste_node->is_left = true;
						std::cout << "left " << tmp->first << std::endl << std::endl;
						break;
					}
					else if (paste_node->first < tmp->first) {
						tmp = tmp->left;
						std::cout << "step left " << tmp->first << std::endl;
						continue;
					}
					else if (paste_node->first > tmp->first && !tmp->right) {
						tmp->right = paste_node;
						paste_node->parent = tmp;
						paste_node->is_left = false;
						std::cout << "right " << tmp->first << std::endl << std::endl;
						break;
					}
					else if (paste_node->first > tmp->first) {
						tmp = tmp->right;
						std::cout << "step right " << tmp->first << std::endl;
						continue;
					}
				}
			}
			return true;
		}
		void	NodeDelete(Key delete_node) {
			node	tmp = m_node;
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
		void	FindReplace(node cpy) {
			if (!cpy->left) {
				if (cpy->is_left)
					cpy->parent->left = cpy->right;
				else
					cpy->parent->right = cpy->right;
				if (cpy->right)
					cpy->right->parent = cpy->parent;
			}
			else {
				node copycpy = cpy->left;
				while (copycpy->right)
					copycpy = copycpy->right;
				if (cpy->is_left)
					cpy->parent->left = copycpy;
				else
					cpy->parent->right = copycpy;
				copycpy->parent = cpy->parent;
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
			this->m_node = cpy.m_node;
			this->hight = cpy.hight;
			this->_alloc = cpy._alloc;
			return *this;
		}
	};
}


#endif //MAP_TREE_HPP
