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
		T	*operator->() const{
			return (this->array);
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
	};

	template<class T>
	class ReverseVectorIterator : public iterator<std::random_access_iterator_tag, T> {
	private:
		T		*array;
	public:
		ReverseVectorIterator() : array(0) {}
		ReverseVectorIterator(T *cpy) {
			this->array = cpy;
		}
		ReverseVectorIterator(const ReverseVectorIterator &cpy) : array(cpy.array) {}
		~ReverseVectorIterator() {};
		ReverseVectorIterator<T>	&operator=(const ReverseVectorIterator<T> &cpy) {
			if (this != &cpy) {
				this->array = cpy.array;
			}
			return *this;
		}
		T	&operator*() const{
			return *(this->array);
		}
		T	*operator->() const{
			return (this->array);
		}
		ReverseVectorIterator<T>	operator++(int) {
			ReverseVectorIterator<T> old = *this;
			this->array--;
			return old;
		}
		ReverseVectorIterator<T>&	operator++() {
			this->array--;
			return *this;
		}
		ReverseVectorIterator<T>	operator--(int) {
			ReverseVectorIterator<T> old = *this;
			this->array++;
			return(old);
		}
		ReverseVectorIterator<T>&	operator--() {
			this->array++;
			return(*this);
		}
		ReverseVectorIterator<T>	operator+(ptrdiff_t n) const {
			ReverseVectorIterator<T> old = *this;
			old.array -= n;
			return old;
		}
		ReverseVectorIterator<T>	&operator+=(ptrdiff_t n) {
			this->array -= n;
			return *this;
		}
		ReverseVectorIterator<T>	operator-(ptrdiff_t n) const {
			ReverseVectorIterator<T> old = *this;
			old.array += n;
			return old;
		}
		ReverseVectorIterator<T>	&operator-=(ptrdiff_t n) {
			this->array += n;
			return *this;
		}
		bool		operator!=(const ReverseVectorIterator<T> &cpy) const{
			return (this->array != cpy.array);
		}
		bool		operator==(const ReverseVectorIterator<T> &cpy) const{
			return (this->array == cpy.array);
		}
		bool		operator<(const ReverseVectorIterator<T> &cpy) const{
			return (this->array < cpy.array);
		}
		bool		operator<=(const ReverseVectorIterator<T> &cpy) const{
			return (this->array <= cpy.array);
		}
		bool		operator>(const ReverseVectorIterator<T> &cpy) const{
			return (this->array > cpy.array);
		}
		bool		operator>=(const ReverseVectorIterator<T> &cpy) const{
			return (this->array >= cpy.array);
		}
		T		&operator[](ptrdiff_t n) {
			ReverseVectorIterator<T>	cmp(this->array);
			cmp += n;
			return *cmp;
		}
	};

	template<class T>
	class ConstVectorIterator : public iterator<std::random_access_iterator_tag, const T> {
	private:
		T		*array;
	public:
		ConstVectorIterator() : array(0) {}
		ConstVectorIterator(T *cpy) {
			this->array = cpy;
		}
		ConstVectorIterator(const ConstVectorIterator &cpy) : array(cpy.array) {}
		~ConstVectorIterator() {};
		ConstVectorIterator<T>	&operator=(const ConstVectorIterator<T> &cpy) {
			if (this != &cpy) {
				this->array = cpy.array;
			}
			return *this;
		}
		T	&operator*() const{
			return *(this->array);
		}
		T	*operator->() const{
			return (this->array);
		}
		ConstVectorIterator<T>	operator++(int) {
			ConstVectorIterator<T> old = *this;
			this->array++;
			return old;
		}
		ConstVectorIterator<T>&	operator++() {
			this->array++;
			return *this;
		}
		ConstVectorIterator<T>	operator--(int) {
			ConstVectorIterator<T> old = *this;
			this->array--;
			return(old);
		}
		ConstVectorIterator<T>&	operator--() {
			this->array--;
			return(*this);
		}
		ConstVectorIterator<T>	operator+(ptrdiff_t n) const {
			ConstVectorIterator<T> old = *this;
			old.array += n;
			return old;
		}
		ConstVectorIterator<T>	&operator+=(ptrdiff_t n) {
			this->array += n;
			return *this;
		}
		ConstVectorIterator<T>	operator-(ptrdiff_t n) const {
			ConstVectorIterator<T> old = *this;
			old.array -= n;
			return old;
		}
		ConstVectorIterator<T>	&operator-=(ptrdiff_t n) {
			this->array -= n;
			return *this;
		}
		bool		operator!=(const ConstVectorIterator<T> &cpy) const{
			return (this->array != cpy.array);
		}
		bool		operator==(const ConstVectorIterator<T> &cpy) const{
			return (this->array == cpy.array);
		}
		bool		operator<(const ConstVectorIterator<T> &cpy) const{
			return (this->array < cpy.array);
		}
		bool		operator<=(const ConstVectorIterator<T> &cpy) const{
			return (this->array <= cpy.array);
		}
		bool		operator>(const ConstVectorIterator<T> &cpy) const{
			return (this->array > cpy.array);
		}
		bool		operator>=(const ConstVectorIterator<T> &cpy) const{
			return (this->array >= cpy.array);
		}
		T		&operator[](ptrdiff_t n) {
			return this->array[n];
		}
	};

	template<class T>
	class ConstReverseVectorIterator : public iterator<std::random_access_iterator_tag, const T> {
	private:
		T		*array;
	public:
		ConstReverseVectorIterator() : array(0) {}
		ConstReverseVectorIterator(T *cpy) {
			this->array = cpy;
		}
		ConstReverseVectorIterator(const ConstReverseVectorIterator &cpy) : array(cpy.array) {}
		~ConstReverseVectorIterator() {};
		ConstReverseVectorIterator<T>	&operator=(const ConstReverseVectorIterator<T> &cpy) {
			if (this != &cpy) {
				this->array = cpy.array;
			}
			return *this;
		}
		T	&operator*() const{
			return *(this->array);
		}
		T	*operator->() const{
			return (this->array);
		}
		ConstReverseVectorIterator<T>	operator++(int) {
			ConstReverseVectorIterator<T> old = *this;
			this->array--;
			return old;
		}
		ConstReverseVectorIterator<T>&	operator++() {
			this->array--;
			return *this;
		}
		ConstReverseVectorIterator<T>	operator--(int) {
			ConstReverseVectorIterator<T> old = *this;
			this->array++;
			return(old);
		}
		ConstReverseVectorIterator<T>&	operator--() {
			this->array++;
			return(*this);
		}
		ConstReverseVectorIterator<T>	operator+(ptrdiff_t n) const {
			ConstReverseVectorIterator<T> old = *this;
			old.array -= n;
			return old;
		}
		ConstReverseVectorIterator<T>	&operator+=(ptrdiff_t n) {
			this->array -= n;
			return *this;
		}
		ConstReverseVectorIterator<T>	operator-(ptrdiff_t n) const {
			ConstReverseVectorIterator<T> old = *this;
			old.array += n;
			return old;
		}
		ConstReverseVectorIterator<T>	&operator-=(ptrdiff_t n) {
			this->array += n;
			return *this;
		}
		bool		operator!=(const ConstReverseVectorIterator<T> &cpy) const{
			return (this->array != cpy.array);
		}
		bool		operator==(const ConstReverseVectorIterator<T> &cpy) const{
			return (this->array == cpy.array);
		}
		bool		operator<(const ConstReverseVectorIterator<T> &cpy) const{
			return (this->array < cpy.array);
		}
		bool		operator<=(const ConstReverseVectorIterator<T> &cpy) const{
			return (this->array <= cpy.array);
		}
		bool		operator>(const ConstReverseVectorIterator<T> &cpy) const{
			return (this->array > cpy.array);
		}
		bool		operator>=(const ConstReverseVectorIterator<T> &cpy) const{
			return (this->array >= cpy.array);
		}
		T		&operator[](ptrdiff_t n) {
			ConstReverseVectorIterator<T>	cmp(this->array);
			cmp += n;
			return *cmp;
		}
	};
}

#endif //VECTOR_ReverseVectorIterator_HPP
