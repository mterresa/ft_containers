//
// Created by Moaney Terresa on 5/13/21.
//

#ifndef QUEUE_QUEUE_HPP
#define QUEUE_QUEUE_HPP

#include <deque>

namespace ft {
	template<class T, class Container = std::deque <T> >
	class Queue {
	public:
		typedef T 				value_type;
		typedef Container 		container_type;
		typedef std::size_t 	size_type;
	private:
		container_type 			m_ctnr;
	public:
		explicit 				Queue(const container_type& ctnr = container_type()) : m_ctnr(ctnr) {}

		bool					empty() const {	return m_ctnr.empty(); }

		size_type				size() const { return m_ctnr.size(); }

		value_type 				&front() { return m_ctnr.front(); }

		const value_type 		&front() const { return m_ctnr.front(); }

		value_type 				&back() { return m_ctnr.back(); }

		const value_type 		&back() const { return m_ctnr.back(); }

		void					push(const value_type & val) { m_ctnr.push_back(val); }

		void					pop() { m_ctnr.pop_front();	}

		template <class s_type, class c_type>
		friend bool 			operator==(const Queue<s_type,c_type>& lhs, const Queue<s_type,c_type>& rhs) {
			return (lhs.m_ctnr == rhs.m_ctnr);
		}

		template <class s_type, class c_type>
		friend bool				operator<(const Queue<s_type,c_type>& lhs, const Queue<s_type,c_type>& rhs) {
			return (lhs.m_ctnr < rhs.m_ctnr);
		}

		template <class s_type, class c_type>
		friend bool 			operator!=(const Queue<s_type,c_type> & lhs, const Queue<s_type,c_type> & rhs) {
			return !operator==(lhs, rhs);
		}

		template <class s_type, class c_type>
		friend bool 			operator<=(const Queue<s_type,c_type> & lhs, const Queue<s_type,c_type> & rhs) {
			return !operator<(rhs, lhs);
		}

		template <class s_type, class c_type>
		friend bool 			operator>(const Queue<s_type,c_type> & lhs, const Queue<s_type,c_type> & rhs) {
			return operator<(rhs, lhs);
		}

		template <class s_type, class c_type>
		friend bool 			operator>=(const Queue<s_type,c_type> & lhs, const Queue<s_type,c_type> & rhs) {
			return !operator<(lhs, rhs);
		}
	};
}

#endif //QUEUE_QUEUE_HPP
