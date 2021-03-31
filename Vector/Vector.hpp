//
// Created by Moaney Terresa on 3/30/21.
//

#ifndef VECTOR_VECTOR_HPP
#define VECTOR_VECTOR_HPP

#include <string>
#include <iostream>
#include "VectorIterator.hpp"

namespace   ft {
	template<class T, class Alloc = std::allocator<T> >
	class 	Vector {
	public:
		typedef T           value_type;
		typedef Alloc       allocator_type;
		typedef T           &reference;
		typedef const T     &const_reference;
		typedef T			 *pointer;
		typedef const T     *const_pointer;
		typedef ptrdiff_t   difference_type;
		typedef size_t      size_type;
		typedef VectorIterator<T>              iterator;
//		typedef ConstListIterator<T>         const_iterator;
//		typedef ReverseListIterator<T>       reverse_iterator;
//		typedef ReverseConstListIterator<T>  const_reverse_iterator;
	private:
		pointer			_array;
		size_type		len;
		size_type		_capacity;
		allocator_type	alloc;
		std::allocator<value_type> *_alloc;
	public:
		explicit Vector (const allocator_type	&alloc = allocator_type()) : alloc(alloc), len(0), _array(0), _capacity(0) {}
		explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : alloc(alloc), len(0), _capacity(n) {
			this->_array = _alloc->allocate(this->_capacity, 0);
			for (size_type i = 0 ; i < n ; ++i)
				this->push_back(val);
		}
		template <class InputIterator>
		Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : len(0), _capacity(0) {
			this->template assign(first, last);
		}
		Vector (const Vector& x) : len(0), _capacity(0) {
			this->template assign(x.begin(), x.end());
		}
		Vector&	operator=(const Vector& x) {
			if (*this == x)
				return *this;
			this->template assign(x.begin(), x.end());
			return *this;
		}
		~Vector() {
			this->clear();
			_alloc->deallocate(this->_array, this->_capacity);
		}
//		Iterators:
		iterator	begin() {
			return VectorIterator<T>(this->_array);
		}
		iterator	begin() const{
			return VectorIterator<T>(this->_array);
		}
//		const_iterator begin() const;
		iterator	end() {
			return VectorIterator<T>(this->_array + this->len);
		}
		iterator	end() const{
			return VectorIterator<T>(this->_array + this->len);
		}
//		const_iterator end() const;
//		Capacity:
		size_type	size() const { return this->len; }
		size_type	max_size() const {
			return this->_alloc->max_size();
		}
		void	resize (size_type n, value_type val = value_type ()) {
			while (this->len < n)
				this->push_back(val);
			while (this->len > n)
				this->pop_back();
		}
		size_type	capacity() const {
			return this->_capacity;
		}
		bool	empty () const {
			return this->len == 0;
		}
		void	reserve (size_type n) {
			if (n > this->_capacity)
				this->rewrite2(n);
		}
//		Modifiers:
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL) {
			this->clear();
			for (; first != last ; ++first)
				this->push_back(*first);
		}
		void	assign (size_type n, const value_type& val) {
			this->clear();
			for (size_type i = 0; i < n; ++i)
				this->push_back(val);
		}
		iterator	insert (iterator position, const value_type& val) {
			this->insert(position, 1, val);
		}
		void	insert (iterator position, size_type n, const value_type& val) {
			size_type dist = this->distance(position, this->end());
			if (this->_capacity <= this->len + n)
				this->rewrite2(this->len + n);
			for (size_type i = 0; i < dist; ++i)
				_alloc->template construct(this->_array + this->len + n - 1 - i, *(this->_array + this->len - 1 - i));
			for (size_type i = 0; i < n; ++i) {
				_alloc->template construct(this->_array + this->len - dist + i, val);
			}
			this->len += n;
		}
		template <class InputIterator>
		void	insert (iterator position, InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL) {
			size_type dist = this->distance(position, this->end());
			size_type n = this->distance(first, last);
			if (this->_capacity <= this->len + n)
				this->rewrite2(this->len + n);
			for (size_type i = 0; i < dist; ++i)
				_alloc->template construct(this->_array + this->len + n - 1 - i, *(this->_array + this->len - 1 - i));
			for (size_type i = 0; i < n; ++i) {
				_alloc->template construct(this->_array + this->len - dist + i, *(first + i));
			}
			this->len += n;
		}
		iterator	erase (iterator position) {
			iterator  ptr = position;
			for (; position != this->end(); ++position)
				*position = *(position + 1);
			this->len--;
			return ptr;
		}
		iterator	erase (iterator first, iterator last) {
			iterator 	ptr = first;
			for (; last != this->end(); ++last, ++first)
				*first = *last;
			this->len -= this->template distance(first, last);
			return first;
		}
		void	swap (Vector& x) {
			this->template swap_tmp(this->_array, x._array);
			this->template swap_tmp(this->_capacity, x._capacity);
			this->template swap_tmp(this->len, x.len);
			this->template swap_tmp(this->alloc, x.alloc);
			this->template swap_tmp(this->_alloc, x._alloc);
		}

		void	push_back (const value_type& val) {
			if (this->len == this->_capacity) {
				if (this->len == 0) {
					this->_array = _alloc->allocate(this->_capacity = 1, 0);
					_alloc->template construct(this->_array, val);
				}
				else if (this->len == this->_capacity) {
					this->rewrite();
				}
			}
			this->_array[this->len] = val;
			this->len++;
		}
		void	pop_back() {
			if (this->len) {
				_alloc->destroy(this->_array + this->len - 1);
				this->len--;
			}
		}
		void	clear() {
			for ( ; this->len ; )
				this->pop_back();
		}

//		Element access:
		reference		operator[](size_type n) {
			return this->_array[n];
		}
		const_reference	operator[](size_type n) const {
			return this->_array[n];
		}
		reference	at (size_type n) {
			if (n >= this->len)
				throw std::out_of_range("out_of_range");
			return this->_array[n];
		}
		const_reference at (size_type n) const {
			if (n >= this->len)
				throw std::out_of_range("out_of_range");
			return this->_array[n];
		}
		reference	front() {
			return this->_array[0];
		}
		const_reference front() const {
			return this->_array[0];
		}
		reference back() {
			if (this->len)
				return this->_array[this->len - 1];
			return this->_array[this->len];
		}
		const_reference back() const {
			if (this->len)
				return this->_array[this->len - 1];
			return this->_array[this->len];
		}
//		Allocator:
		allocator_type	get_allocator() const {
			return alloc;
		}
	private:
		void 	rewrite() {
			pointer 	tmp;
			tmp = _alloc->allocate(this->_capacity * 2, 0);
			for (size_type i = 0 ; i < this->len ; ++i)
				_alloc->template construct(tmp + i, *(this->_array + i));
			_alloc->destroy(this->_array);
			_alloc->deallocate(this->_array, this->_capacity);
			this->_array = tmp;
			this->_capacity = this->_capacity * 2;
		}
		void 	rewrite2(size_type new_cap) {
			pointer 	tmp;
			tmp = _alloc->allocate(new_cap, 0);
			for (size_type i = 0 ; i < this->len ; ++i)
				_alloc->template construct(tmp + i, *(this->_array + i));
			_alloc->destroy(this->_array);
			_alloc->deallocate(this->_array, this->_capacity);
			this->_array = tmp;
			this->_capacity = new_cap;
		}
		template <class InputIterator>
		int 	distance(InputIterator position, InputIterator last) {
			int i = 0;
			InputIterator rmp = position;
			while (rmp != last) {
				i++;
				rmp++;
			}
			return i;
		}
		template<class tmp>
		void 	swap_tmp(tmp &first, tmp &second) {
			tmp		cpy = first;
			first = second;
			second = cpy;
		}
	};
}

#endif //VECTOR_VECTOR_HPP
