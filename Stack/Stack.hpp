//
// Created by Moaney Terresa on 5/13/21.
//

#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include <deque>
#include <iostream>

namespace ft {
	template<class T, class Container = std::deque<T> >
	class Stack {
	public:
		typedef T				value_type;
		typedef Container		container_type;
		typedef std::size_t		size_type;
	private:
		container_type			m_ctnr;
	public:
		explicit 				Stack(const container_type & ctnr = container_type()) : m_ctnr(ctnr) {}

		bool					empty() const {	return m_ctnr.empty(); }

		size_type				size() const { return m_ctnr.size(); }

		value_type 				&top() { return m_ctnr.back(); }

		const value_type 		&top() const { return m_ctnr.back(); }

		void					push(const value_type & val) { m_ctnr.push_back(val); }

		void					pop() { m_ctnr.pop_back(); }

		template <class s_type, class c_type>
		friend bool 			operator==(const Stack<s_type,c_type>& lhs, const Stack<s_type,c_type>& rhs) {
			return (lhs.m_ctnr == rhs.m_ctnr);
		}

		template <class s_type, class c_type>
		friend bool				operator<(const Stack<s_type,c_type>& lhs, const Stack<s_type,c_type>& rhs) {
			return (lhs.m_ctnr < rhs.m_ctnr);
		}

		template <class s_type, class c_type>
		friend bool 			operator!=(const Stack<s_type,c_type> & lhs, const Stack<s_type,c_type> & rhs) {
			return !operator==(lhs, rhs);
		}

		template <class s_type, class c_type>
		friend bool 			operator<=(const Stack<s_type,c_type> & lhs, const Stack<s_type,c_type> & rhs) {
			return !operator<(rhs, lhs);
		}

		template <class s_type, class c_type>
		friend bool 			operator>(const Stack<s_type,c_type> & lhs, const Stack<s_type,c_type> & rhs) {
			return operator<(rhs, lhs);
		}

		template <class s_type, class c_type>
		friend bool 			operator>=(const Stack<s_type,c_type> & lhs, const Stack<s_type,c_type> & rhs) {
			return !operator<(lhs, rhs);
		}
	};
}

#endif //STACK_STACK_HPP
