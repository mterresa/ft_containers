//
// Created by Moaney Terresa on 3/2/21.
//

#ifndef FT_CONTAINERS_NODE_HPP
#define FT_CONTAINERS_NODE_HPP

namespace ft {
    template<typename T>
    class Node {
    public:
        T       data;
        Node    *next;
        Node    *prev;
        explicit Node(const T &val = T()) : data(val), next(0), prev(0) {}
        Node(const Node &cpy) {
            this->data = cpy.data;
            this->next = cpy.next;
            this->prev = cpy.prev;
        }
        ~Node() {}
        Node	*operator++(){
			return (this->next);
        }
		Node	*operator--(){
			return (this->prev);
		}
		bool		operator!=(const Node<T> *cpy) {
			return (this->data != cpy->data);
		}
		bool		operator==(const Node<T> *cpy) {
			return (this->data == cpy->data);
		}


    };
}

#endif //FT_CONTAINERS_NODE_HPP
