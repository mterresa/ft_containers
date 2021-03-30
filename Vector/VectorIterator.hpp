//
// Created by Moaney Terresa on 3/30/21.
//

#ifndef VECTOR_VECTORITERATOR_HPP
#define VECTOR_VECTORITERATOR_HPP

#include <iterator>

namespace   ft {
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator {
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template<class T>
	class VectorIterator : public iterator<std::random_access_iterator_tag, T> {
	private:
		T		*array;
	public:
		VectorIterator() : array(0) {}
		VectorIterator(T *cpy) {
			this->array = cpy;
		}
		VectorIterator(const VectorIterator &cpy) : array(cpy.array) {}
		~VectorIterator() {};
		VectorIterator<T>	&operator=(const VectorIterator<T> &cpy) {
			if (this != &cpy) {
				this->array = cpy.array;
			}
			return *this;
		}
		T	&operator*() const{
			return *(this->array);
		}
		T	&operator->() const{
			return &(this->array);
		}
		VectorIterator<T>	operator++(int) {
			VectorIterator<T> old = *this;
			this->array++;
			return old;
		}
		VectorIterator<T>&	operator++() {
			this->array++;
			return *this;
		}
		VectorIterator<T>	operator--(int) {
			VectorIterator<T> old = *this;
			this->array--;
			return(old);
		}
		VectorIterator<T>&	operator--() {
			this->array--;
			return(*this);
		}
		VectorIterator<T>	operator+(ptrdiff_t n) const {
			VectorIterator<T> old = *this;
			old.array += n;
			return old;
		}
		VectorIterator<T>	&operator+=(ptrdiff_t n) {
			this->array += n;
			return *this;
		}
		VectorIterator<T>	operator-(ptrdiff_t n) const {
			VectorIterator<T> old = *this;
			old.array -= n;
			return old;
		}
		VectorIterator<T>	&operator-=(ptrdiff_t n) {
			this->array -= n;
			return *this;
		}
		bool		operator!=(const VectorIterator<T> &cpy) const{
			return (this->array != cpy.array);
		}
		bool		operator==(const VectorIterator<T> &cpy) const{
			return (this->array == cpy.array);
		}
		bool		operator<(const VectorIterator<T> &cpy) const{
			return (this->array < cpy.array);
		}
		bool		operator<=(const VectorIterator<T> &cpy) const{
			return (this->array <= cpy.array);
		}
		bool		operator>(const VectorIterator<T> &cpy) const{
			return (this->array > cpy.array);
		}
		bool		operator>=(const VectorIterator<T> &cpy) const{
			return (this->array >= cpy.array);
		}
		T		&operator[](ptrdiff_t n) {
			return this->array[n];
		}
//		template<typename T2, typename P, typename R, class C>
//		friend inline bool operator==(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs) {
//			return (lhs.array == rhs.array);
//		}
//		template<typename T2, typename P, typename R, class C>
//		friend inline bool operator!=(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs) {
//			return (lhs != rhs);
//		}
	};
}

#endif //VECTOR_VECTORITERATOR_HPP
