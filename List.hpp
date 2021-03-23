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

#define _ENABLE_INPUT(type_name) \
			typename std::enable_if< std::__is_input_iterator<type_name>::value,type_name >::type

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
                this->head = ptr->prev;
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
//		____ASSIGN____
		template <class InputIterator>
		void	assign (InputIterator first, _ENABLE_INPUT(InputIterator) last) {
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
//        ____INSERT____
		ListIterator<T> insert (ListIterator<T> position, const value_type& val) {
        	Node<T>	*ptr = new Node<T>(val);
        	ptr->next = position.getPtr();
        	ptr->prev = position.getPtr()->prev;
        	position.getPtr()->prev->next = ptr;
        	position.getPtr()->prev = ptr;
        	this->len++;
			return ListIterator<T>(position);
        }
		void insert (ListIterator<T> position, size_type n, const value_type& val) {
			while (n) {
				this->insert(position, val);
				n--;
			}
        }
		template <class InputIterator>
		void	insert (ListIterator<T> position, InputIterator first, _ENABLE_INPUT(InputIterator) last) {
			while (first != last) {
				this->insert(position, *first);
				first++;
			}
        }
//        ____ERASE____
		ListIterator<T>	erase (ListIterator<T> position) {
        	Node<T>	*ptr = position.getPtr();
        	position.getPtr()->prev->next = position.getPtr()->next;
        	position.getPtr()->next->prev = position.getPtr()->prev;
        	position++;
        	delete ptr;
			this->len--;
			return ListIterator<T>(ptr);
        }
		ListIterator<T> erase (ListIterator<T> first, ListIterator<T> last) {
			while (first != last) {
				this->erase(first);
				first++;
			}
			return first;
        }
		void	swap (List& x) {
			Node<T>         *tmp_head;
			Node<T>         *tmp_last_ptr;
			allocator_type  tmp_alloc;
			size_type       tmp_len;

			tmp_head = this->head;
			tmp_last_ptr = this->last_ptr;
			tmp_alloc = this->alloc;
			tmp_len = this->len;
			this->head = x.head;
			this->last_ptr = x.last_ptr;
			this->alloc = x.alloc;
			this->len = x.len;
			x.head = tmp_head;
			x.last_ptr = tmp_last_ptr;
			x.alloc = tmp_alloc;
			x.len = tmp_len;
        }
		void	resize (size_type n, value_type val = value_type ()) {
			while (this->len < n)
				this->push_back(val);
			while (this->len > n)
				this->pop_back();
        }
    };
}
#endif //FT_CONTAINERS_LIST_HPP
