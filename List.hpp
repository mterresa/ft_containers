//
// Created by Moaney Terresa on 2/24/21.
//

//max_size

#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <iostream>
#include "Node.hpp"
#include "Iterator.hpp"

namespace   ft {
    template < class T, class Alloc = std::allocator<T> >
    class List {
    public:                                         //Member types
        typedef T           value_type;
        typedef Alloc       allocator_type;
        typedef T           &reference;
        typedef const T     &const_reference;
        typedef T           *pointer;
        typedef const T     *const_pointer;
        typedef ptrdiff_t   difference_type;
        typedef size_t      size_type;
//        class               iterator;
//        class               const_iterator;
//        class               reverse_iterator;
//        class               const_reverse_iterator;
    private:
        Node<T>         *head;
		Node<T>         *last_ptr;
        allocator_type  alloc;
        size_type       len;
    public:
        explicit List(const allocator_type &alloc = allocator_type()) : alloc(alloc), len(0) {
            this->head = new Node<T>();
			this->head->data = 0;
			this->head->next = this->head;
			this->head->prev = this->head;
			this->last_ptr = this->head;
        }
        explicit List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : alloc(alloc) {
            for (size_t i = 0; i < n; i++)
                this->push_back(val);
        }
		List& operator= (const List& x) {
			this->clear();
			this->head = x.head;
			this->last_ptr = x.last_ptr;
			this->len = x.len;
			return *this;
		}
		~List() {
			this->clear();
			delete this->last_ptr;
        }
		void 	clear() {
			while (this->len)
				this->pop_back();
        }
		bool	empty () const {
			return this->len == 0;
        }
		size_type size() const {
			return this->len;
        }
		size_type	max_size() const {
			return (std::numeric_limits<size_type>::max() / (sizeof(Node<value_type>)));
		}
//        ____BACK____
        void    push_back(const value_type& val) {
        	Node<T> *ptr = this->last_ptr->prev;
			this->head = new Node<T>(val);
			this->head->next = ptr->next;
			this->head->prev = ptr;
			this->last_ptr->prev = this->head;
			ptr->next = this->head;
			this->len++;
        }
        void    pop_back() {
            if (this->len > 0) {
                Node<T> *ptr = this->last_ptr->prev;
                this->head = this->head->prev;
                this->head->next = ptr->next;
				this->last_ptr->prev = this->last_ptr->prev->prev;
                delete ptr;
                this->len--;
            }
        }
		reference	back() {
			return this->last_ptr->prev->data;
		}
		const_reference	back() const {
			return this->last_ptr->prev->data;
		}
//        ____FRONT____
		void 	push_front(const value_type& val) {
			Node<T> *ptr = this->last_ptr->next;
			this->head = new Node<T>(val);
			this->head->prev = ptr->prev;
			this->head->next = ptr;
			this->last_ptr->next = this->head;
			ptr->prev = this->head;
			this->len++;
        }
		void pop_front() {
        	if (this->len > 0) {
				Node<T> *ptr = this->last_ptr->next;
				this->last_ptr->next = ptr->next;
				ptr->next->prev = this->last_ptr;
				delete ptr;
				this->len--;
			}
        }
		reference	front() {
			return this->last_ptr->next->data;
        }
		const_reference	front() const {
			return this->last_ptr->next->data;
		}
//		  ____ITERATOR____
        ListIterator<T>		begin() {
			return ListIterator<T>(this->last_ptr->next);
        }
		ListIterator<T>		end() {
			return ListIterator<T>(this->last_ptr);
		}
		template <class InputIterator>
		void	assign (InputIterator first, InputIterator last) {
			this->clear();
			while (first != last) {
				this->push_back(*first);
				first++;
			}
		}
		void	assign (size_type n, const value_type& val) {
			this->clear();
			while (n > 0) {
				this->push_back(val);
				n--;
			}
        }
    };
}
#endif //FT_CONTAINERS_LIST_HPP
