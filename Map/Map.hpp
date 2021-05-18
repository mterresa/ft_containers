//
// Created by Moaney Terresa on 4/1/21.
//

#ifndef MAP_MAP_HPP
#define MAP_MAP_HPP

#include <string>
#include <iostream>
#include "NodeMap.hpp"
#include "MapIterator.hpp"

namespace ft {

	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
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
		typedef NodeMap<Key, T>				*my_node;
	private:
		NodeMap<Key, T>						*head;
		key_type 							_key;
		std::allocator<NodeMap<Key, T> > 	*_alloc;
		allocator_type  					alloc;
		key_compare 						k_comp;
		NodeMap<Key, T>						*root;

	public:
		explicit Map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) : alloc(alloc), k_comp(comp) {
//			this->head = _alloc->allocate(1, 0);
//			_alloc->construct(this->head, 0);
		}
//		template <class InputIterator>
//		map (InputIterator first, InputIterator last,
//		const key_compare& comp = key_compare(),
//		const allocator_type& alloc = allocator_type());
//		map (const map& x);
//		____Iterators:
		iterator begin() {
			NodeMap<Key, T>		*ptr = this->head;
			while (ptr->left != NULL)
				ptr = ptr->left;
			return ptr;
		}
//		const_iterator begin() const {
//			NodeMap<Key, T>		*ptr = this->head;
//			while (ptr->left != NULL)
//				ptr = ptr->left;
//			return ptr;
//		}
		iterator end() {

			while (this->head->getParent())
				this->head = this->head->getParent();
			NodeMap<Key, T>		*ptr = this->head;

			while (ptr->right != NULL)
				ptr = ptr->right;
			return ptr;
		}
//		const_iterator end() const {
//			NodeMap<Key, T>		*ptr = this->head;
//			while (ptr->right != NULL)
//				ptr = ptr->right;
//			return ptr;
//		}
//		_________Modifiers:
		std::pair<iterator,bool>		insert (const value_type& val) {
			if (!this->head) {
				this->head = _alloc->allocate(1, 0);
				_alloc->construct(this->head, val.first, val.second);
				this->head->is_red = false;
				return std::make_pair(this->head, false);
			}
			while (this->head->getParent())
				this->head = this->head->getParent();
			my_node ptr = this->head;

			my_node n_head;
			while (1) {
				if (val.first < ptr->first) {
					if (!ptr->left) {
						n_head = _alloc->allocate(1, 0);
						_alloc->construct(n_head, val.first, val.second);
						ptr->left = n_head;
						n_head->is_left = true;
						n_head->parent = ptr;
						break ;
					}
					ptr = ptr->left;
				}
				if (val.first > ptr->first) {
					if (!ptr->right) {
						n_head = _alloc->allocate(1, 0);
						_alloc->construct(n_head, val.first, val.second);
						ptr->right = n_head;
						n_head->is_left = false;
						n_head->parent = ptr;
						break ;
					}
					ptr = ptr->right;
				}
			}
			balance_tree(n_head);
			return std::make_pair(ptr->left, false);
		}
	private:
		void 	balance_tree(my_node target) {
			my_node cpy = target;
			// Левосторонний поворот
			if (!cpy->is_left && cpy->is_red && (!cpy->parent->left || !cpy->parent->left->is_red)) {
				my_node t_left = target->left;
				my_node t_par = target->parent;
				my_node t_gpar = target->parent->parent;
				target->parent->parent = target;
				target->parent = t_gpar;
				target->left = t_par;
				std::cout << "left rot" << std::endl;
				t_par->right = t_left;
				if (t_par->right)
					t_par->right->is_left = false;
				if (!target->parent)
					target->is_red = false;
			}
			// Правосторонний поворот
			if (cpy->is_left && cpy->is_red && cpy->parent->is_red) {
				my_node t_right = target->right;
				my_node t_par = target->parent;
				my_node t_gpar = target->parent->parent;
				target->parent->parent = target;
				target->parent = t_gpar;
				target->right = t_par;
				std::cout << "right rot" << std::endl;
				t_par->left = t_right;
				if (t_par->left)
					t_par->left->is_left = true;
				if (!target->parent)
					target->is_red = false;
			}
		}
		void 	recolor(my_node target) {
			target->is_red = !target->is_red;
		}

	public:
//		iterator insert (iterator position, const value_type& val);
//		range (3)
//		template <class InputIterator>
//		void insert (InputIterator first, InputIterator last);
	};
}

#endif //MAP_MAP_HPP
