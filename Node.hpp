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
        Node	*operator++(int){
			return (this->next);
        }
		Node	*operator--(int){
			return (this->prev);
		}
		bool		operator!=(const Node<T> *cpy) {
			return (this->data != cpy->data);
		}
		bool		operator==(const Node<T> *cpy) {
			return (this->data == cpy->data);
		}
		Node&	operator=(const Node& cpy) {
			if (this != &cpy) {
				this->data = cpy.data;
				this->next = cpy.next;
				this->prev = cpy.prev;
			}
			return *this;
		}

    };
}

#endif //FT_CONTAINERS_NODE_HPP
