//
// Created by Moaney Terresa on 2/24/21.
//

#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <iostream>
#include "Node.hpp"

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
        allocator_type  alloc;
        size_type       len;
    public:
        explicit List(const allocator_type &alloc = allocator_type()) : alloc(alloc), len(0) {
            this->head = new Node<T>();
			this->head->data = 0;
			
        }
        explicit List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : alloc(alloc) {
            for (size_t i = 0; i < n; i++)
                this->push_back(val);
        }
        void    push_back(const value_type& val) {
        	this->head = new Node<T>();
        	Node<T> *ptr = this->head;
        	this->head = new Node<T>(val);
        	ptr->next = this->head;
        	this->len++;
        }
        void    pop_back() {
            if (this->len > 0) {
                Node<T> *ptr = this->head;
                this->head = this->head->prev;
                delete ptr;
                this->len--;
            }
        }
    };
}
#endif //FT_CONTAINERS_LIST_HPP
