//
// Created by Moaney Terresa on 4/1/21.
//

#ifndef MAP_MAP_HPP
#define MAP_MAP_HPP

#include <string>
#include <iostream>
#include "MapIterator.hpp"
#include "tree.hpp"

namespace ft {

	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
	>
	class 	Map {
	public:
		typedef Key							key_type;
		typedef T							mapped_type;
		typedef std::pair<const Key, T>		value_type;
		typedef	Compare						key_compare;
		typedef Alloc						allocator_type;
		typedef	value_type&					reference;
		typedef	const value_type&			const_reference;
		typedef	value_type*					pointer;
		typedef	const value_type*			const_pointer;
		typedef	ptrdiff_t					difference_type;
		typedef	size_t						size_type;
		typedef	MapIterator<Key, T>			iterator;
		typedef ft::NodeMap<Key, T>				*my_node;
	private:
//		NodeMap<Key, T>						*head;
//		key_type 							_key;
//		std::allocator<NodeMap<Key, T> > 	*_alloc;
		allocator_type  					alloc;
		key_compare 						k_comp;
//		NodeMap<Key, T>						*root;
		tree<key_type, mapped_type>			node;
	public:
		explicit Map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) : alloc(alloc), k_comp(comp) {
//			this->head = _alloc->allocate(1, 0);
//			_alloc->construct(this->head, 0);
		}
		template <class InputIterator>
		Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : alloc(alloc), k_comp(comp) {
			this->insert(first, last);
		}
		Map (const Map& x) {
			*this = x;
		}

		Map&	operator=(const Map& x) {
			this->alloc = x.alloc;
			this->k_comp = x.k_comp;
			this->node = x.node;
			return *this;
		}
//		____Iterators:
//		____Modifiers:
		ft::pair<iterator,bool> insert (const value_type& val) {
			node.NodeCreate(val);
			return
		}
	public:
//		iterator insert (iterator position, const value_type& val);
//		range (3)
//		template <class InputIterator>
//		void insert (InputIterator first, InputIterator last);
	};
}

#endif //MAP_MAP_HPP
