//
// Created by Moaney Terresa on 4/1/21.
//

#ifndef MAP_MAP_HPP
#define MAP_MAP_HPP

#include <string>
#include <iostream>
#include "MapIterator.hpp"
//#include "tree.hpp"
#include "new_tree.hpp"
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
		typedef ft::pair<Key, T>				value_type;
		typedef std::less<mapped_type>			value_compare;
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
		typedef ft::avl_tree_node<Key, T>				*my_node;
	private:
		allocator_type  					alloc;
		key_compare 						k_comp;
		value_compare 						v_comp;
		avl_tree<key_type, mapped_type>		tree;
		my_node 							node;
		my_node 							_end;
		size_type 							_size;
	public:
		explicit Map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) : alloc(alloc), k_comp(comp), node(NULL) {
			this->_end = tree.create_node(ft::make_pair<key_type, mapped_type>(key_type(), mapped_type()), NULL);
		}
		template <class InputIterator>
		Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : alloc(alloc), k_comp(comp), node(NULL) {
			this->_end = tree.create_node(ft::make_pair<key_type, mapped_type>(key_type(), mapped_type()), NULL);
			this->insert(first, last);
		}
		Map (const Map& x) {
			*this = x;
		}

		~Map() {
			this->clear();
		}

		Map&	operator=(const Map& x) {
			if (this != &x) {
				this->alloc = x.alloc;
				this->k_comp = x.k_comp;
				tree.clear(this->node);
				this->node = x.node;
				tree.delete_node(this->_end);
				this->_end = x._end;
			}
			return *this;
		}

		key_compare key_comp() const {
			return k_comp;
		}

		value_compare value_comp () const {
			return v_comp;
		}

		void swap (Map& x) {
			Map		tmp(x);
			x = *this;
			*this = tmp;
		}

		void clear() {
			tree.clear(node);
		}

		iterator begin() {
			if (!tree.min_node(this->node))
				return iterator(_end);
			return iterator(tree.min_node(this->node));
		}
		const_iterator begin() const {
			if (!tree.min_node(this->node))
				return iterator(_end);
			return const_iterator(tree.min_node(this->node));
		}

		iterator end() {
			return iterator(_end);
		}
		const_iterator end() const {
			return const_iterator(_end);
		}

		reverse_iterator rbegin() {
			if (!tree.max_node(this->node))
				return reverse_iterator(_end);
			return reverse_iterator(tree.max_node(this->node));
		}
		const_reverse_iterator rbegin() const {
			if (!tree.max_node(this->node))
				return reverse_iterator(_end);
			return const_reverse_iterator(tree.max_node(this->node));
		}

		reverse_iterator rend() {
			return reverse_iterator(_end);
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator(_end);
		}

		bool empty() const {
			return this->_size == 0;
		}

		size_type size() const {
			return this->_size;
		}

		size_type max_size() const {
			return tree.max_size();
		}

		mapped_type& operator[] (const key_type& k) {
			return tree.find_node(&node, k)->second;
		}

		void erase (iterator position) {
			tree.erase(&node, position->first);
		}
		size_type erase (const key_type& k) {
			return tree.erase(&node, k);
		}
		void erase (iterator first, iterator last) {
			iterator tmp = first;
			while (tmp != last) {
				tree.erase(&node, tmp->first);
				++tmp;
			}
		}

		ft::pair<iterator,bool> insert(const value_type& val) {
			bool t = tree.insert(&node, tree.create_node(val, _end));
			ft::pair<iterator, bool>	pair = ft::make_pair(iterator(tree.find_node(&node, val.first)), t);
			return pair;
		}

		ft::pair<iterator,bool> insert(const std::pair<key_type, mapped_type>& val) {
			ft::pair<key_type,mapped_type>	pr(val.first, val.second);
			bool t = tree.insert(&node, tree.create_node(pr, _end));
			ft::pair<iterator, bool>	pair = ft::make_pair(iterator(tree.find_node(&node, pr.first)), t);
			return pair;
		}


		iterator 				insert(iterator position, const value_type& val) {
			tree.insert(&node, tree.create_node(val, _end));
			return iterator(tree.find_node(&node, val.first));
		}

		iterator 				insert(iterator position, const std::pair<key_type, mapped_type>& val) {
			ft::pair<key_type,mapped_type>	pr(val.first, val.second);
			tree.insert(&node, tree.create_node(pr, _end));
			return iterator(tree.find_node(&node, pr.first));
		}

		iterator find (const key_type& k) {
			return iterator(tree.find_node(&node, k));
		}
		const_iterator find (const key_type& k) const {
			return const_iterator(tree.find_node(&node, k));
		}

		size_type count (const key_type& k) const {
			my_node tmp = node;
			if (tree.find_node(&tmp, k))
				return 1;
			return 0;
		}

		iterator lower_bound (const key_type& k) {
			my_node f_node = tree.find_node(&node, k);
			if (f_node && f_node->left)
				return iterator (f_node->left);
			if (f_node)
				return iterator(f_node);
			return iterator(_end);
		}

		const_iterator lower_bound (const key_type& k) const {
			my_node f_node = tree.find_node(&node, k);
			if (f_node && f_node->left)
				return const_iterator (f_node->left);
			if (f_node)
				return const_iterator(f_node);
			return const_iterator(_end);
		}

		iterator upper_bound (const key_type& k) {
			my_node f_node = tree.find_node(&node, k);
			if (f_node && f_node->right)
				return iterator (f_node->right);
			if (f_node)
				return iterator(f_node);
			return iterator(_end);
		}

		const_iterator upper_bound (const key_type& k) const {
			my_node f_node = tree.find_node(&node, k);
			if (f_node && f_node->right)
				return const_iterator (f_node->right);
			if (f_node)
				return const_iterator(f_node);
			return const_iterator(_end);
		}

		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return ft::make_pair<key_type, mapped_type>(this->lower_bound(k), this->upper_bound(k));
		}

		ft::pair<iterator,iterator>             equal_range (const key_type& k) {
			return ft::make_pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k));
		}

		template <class InputIterator>
		void 					insert(InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL) {
			InputIterator tmp = first;
			while (tmp != last) {
				this->insert(*tmp);
				tmp++;
			}
		}
	};
}

#endif //MAP_MAP_HPP
