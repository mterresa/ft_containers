//
// Created by Moaney Terresa on 3/11/21.
//

#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP

#include <iterator>
#include "Node.hpp"

namespace   ft {
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator {
		typedef T 			value_type;
		typedef Distance 	difference_type;
		typedef Pointer 	pointer;
		typedef Reference 	reference;
		typedef Category 	iterator_category;
	};

	template<class T>
	class ListIterator : public iterator<std::bidirectional_iterator_tag, T> {
	private:
		Node<T>		*ptr;
	public:
		ListIterator() {
			ptr = NULL;
		}
		ListIterator<T>&	operator=(const ListIterator<T>& cpy) {
			if (this != &cpy) {
				this->ptr = cpy.ptr;
				return *this;
			}
		}
		ListIterator(Node<T> *ptr) {
			this->ptr = ptr;
		}
		~ListIterator() {}
		T	&operator*() const{
			return (this->ptr->data);
		}
		T	&operator->() const{
			return &(this->ptr->data);
		}
		ListIterator<T>		operator++(int) {
			ListIterator<T> old = *this;
			this->ptr = ptr->next;
			return(old);
		}
		ListIterator<T>	operator++() {
			this->ptr = ptr->next;
			return(*this);
		}
		ListIterator<T>	operator--(int) {
			ListIterator<T> old = *this;
			this->ptr = ptr->prev;
			return(old);
		}
		ListIterator<T>	operator--() {
			this->ptr = ptr->prev;
			return(*this);
		}
		bool		operator!=(const ListIterator<T> &cpy) const{
			return (this->ptr != cpy.ptr);
		}
		bool		operator==(const ListIterator<T> &cpy) const{
			return (this->ptr == cpy.ptr);
		}
		Node<T>	*getPtr() {
			return ptr;
		}
	};

	template<class T>
	class ReverseListIterator : public iterator<std::bidirectional_iterator_tag, T> {
	private:
		Node<T>		*ptr;
	public:
		ReverseListIterator() {
			ptr = NULL;
		}
		ReverseListIterator<T>&	operator=(const ReverseListIterator<T>& cpy) {
			if (this != &cpy) {
				this->ptr = cpy.ptr;
				return *this;
			}
		}
		ReverseListIterator(Node<T> *ptr) {
			this->ptr = ptr;
		}
		~ReverseListIterator() {}
		T	&operator*() const{
			return (this->ptr->data);
		}
		T	&operator->() const{
			return &(this->ptr->data);
		}
		ReverseListIterator<T>		operator++(int) {
			ReverseListIterator<T> old = *this;
			this->ptr = ptr->prev;
			return(old);
		}
		ReverseListIterator<T>	operator++() {
			this->ptr = ptr->prev;
			return(*this);
		}
		ReverseListIterator<T>	operator--(int) {
			ReverseListIterator<T> old = *this;
			this->ptr = ptr->next;
			return(old);
		}
		ReverseListIterator<T>	operator--() {
			this->ptr = ptr->next;
			return(*this);
		}
		bool		operator!=(const ReverseListIterator<T> &cpy) const{
			return (this->ptr != cpy.ptr);
		}
		bool		operator==(const ReverseListIterator<T> &cpy) const{
			return (this->ptr == cpy.ptr);
		}
		Node<T>	*getPtr() {
			return ptr;
		}
	};

	template<class T>
	class ConstListIterator : public iterator<std::bidirectional_iterator_tag, const T> {
	private:
		Node <T> *ptr;
	public:
		ConstListIterator() {
			ptr = NULL;
		}

		ConstListIterator<T> &operator=(const ConstListIterator<T> &cpy) {
			this->ptr = cpy.ptr;
			return *this;
		}

		ConstListIterator(Node <T> *ptr) {
			this->ptr = ptr;
		}

		~ConstListIterator() {}

		T &operator*() const {
			return (this->ptr->data);
		}

		T &operator->() const {
			return &(this->ptr->data);
		}

		ConstListIterator<T> operator++(int) {
			ConstListIterator<T> old = *this;
			this->ptr = ptr->next;
			return (old);
		}

		ConstListIterator<T> operator++() {
			this->ptr = ptr->next;
			return (*this);
		}

		ConstListIterator<T> operator--(int) {
			ConstListIterator<T> old = *this;
			this->ptr = ptr->prev;
			return (old);
		}

		ConstListIterator<T> operator--() {
			this->ptr = ptr->prev;
			return (*this);
		}

		bool operator!=(const ConstListIterator<T> &cpy) const{
			return (this->ptr != cpy.ptr);
		}

		bool operator==(const ConstListIterator<T> &cpy) const{
			return (this->ptr == cpy.ptr);
		}

		Node <T> *getPtr() {
			return ptr;
		}
	};

	template<class T>
	class ReverseConstListIterator : public iterator<std::bidirectional_iterator_tag, const T> {
	private:
		Node <T> *ptr;
	public:
		ReverseConstListIterator() {
			ptr = NULL;
		}

		ReverseConstListIterator<T> &operator=(const ReverseConstListIterator<T> &cpy) {
			this->ptr = cpy.ptr;
			return *this;
		}

		ReverseConstListIterator(Node <T> *ptr) {
			this->ptr = ptr;
		}

		~ReverseConstListIterator() {}

		T &operator*() const {
			return (this->ptr->data);
		}

		T &operator->() const {
			return &(this->ptr->data);
		}

		ReverseConstListIterator<T> operator++(int) {
			ReverseConstListIterator<T> old = *this;
			this->ptr = ptr->next;
			return (old);
		}

		ReverseConstListIterator<T> operator++() {
			this->ptr = ptr->next;
			return (*this);
		}

		ReverseConstListIterator<T> operator--(int) {
			ReverseConstListIterator<T> old = *this;
			this->ptr = ptr->prev;
			return (old);
		}

		ReverseConstListIterator<T> operator--() {
			this->ptr = ptr->prev;
			return (*this);
		}

		bool operator!=(const ReverseConstListIterator<T> &cpy) const{
			return (this->ptr != cpy.ptr);
		}

		bool operator==(const ReverseConstListIterator<T> &cpy) const{
			return (this->ptr == cpy.ptr);
		}

		Node <T> *getPtr() {
			return ptr;
		}
	};
}


#endif //FT_CONTAINERS_ITERATOR_HPP
