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
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef ft::pair<Key, T>			value_type;
		typedef	Compare							key_compare;
		typedef Alloc							allocator_type;
		typedef	value_type&						reference;
		typedef	const value_type&				const_reference;
		typedef	value_type*						pointer;
		typedef	const value_type*				const_pointer;
		typedef	ptrdiff_t						difference_type;
		typedef	size_t							size_type;
		typedef	MapIterator<Key, T>				iterator;
		typedef	MapIterator<Key, const T>		const_iterator;
		typedef ReverseMapIterator<iterator> 	reverse_iterator;
		typedef ReverseMapIterator<const_iterator> const_reverse_iterator;
		typedef ft::NodeMap<Key, T>				*my_node;
	private:
		allocator_type  					alloc;
		key_compare 						k_comp;
		tree<key_type, mapped_type>			node;
	public:
		explicit Map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) : alloc(alloc), k_comp(comp), node() {
		}
		template <class InputIterator>
		Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : alloc(alloc), k_comp(comp) {
			this->insert(first, last);
		}
		Map (const Map& x) {
			*this = x;
		}

		~Map() {}

		Map&	operator=(const Map& x) {
			this->alloc = x.alloc;
			this->k_comp = x.k_comp;
			this->node = x.node;
			return *this;
		}

		iterator begin() {
			std::cout << "min " << node.min->first << " begin  " << std::endl;
			return iterator(node.min);
		}
		const_iterator begin() const {
			return const_iterator(node.min);
		}

		iterator end() {
			return iterator(node.end);
		}
		const_iterator end() const {
			return const_iterator(node.end);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(node.max);
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(node.max);
		}

		reverse_iterator rend() {
			return reverse_iterator(node.end);
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator(node.end);
		}

		bool empty() const {
			return node.size == 0;
		}

		size_type size() const {
			return node.size;
		}

		size_type max_size() const {
			return node.max_size();
		}

		mapped_type& operator[] (const key_type& k) {
			return node.FindNode(k)->second;
		}

		void erase (iterator position) {
			node.NodeDelete(position->first);
		}
//		size_type erase (const key_type& k);
//		(3)
//		void erase (iterator first, iterator last);

		ft::pair<iterator,bool> insert(const value_type& val) {
			bool t = node.NodeCreate(val);
			ft::pair<iterator, bool>	pair = ft::make_pair(iterator(node.FindNode(val.first)), t);
			return pair;
		}

		iterator 				insert(iterator position, const value_type& val) {
			node.NodeCreate(val);
			return iterator(node.FindNode(val.first));
		}

		template <class InputIterator>
		void 					insert(InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL) {
			InputIterator tmp = first;
			while (tmp != last) {
				node.NodeCreate(*tmp);
				tmp++;
			}
		}
	};
}

#endif //MAP_MAP_HPP
