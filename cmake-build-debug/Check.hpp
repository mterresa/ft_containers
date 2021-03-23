//
// Created by Moaney Terresa on 3/23/21.
//

#ifndef FT_CONTAINERS_CHECK_HPP
#define FT_CONTAINERS_CHECK_HPP

namespace ft {
	template<bool Cond, class T = void> struct enable_if {};
	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
}

#endif //FT_CONTAINERS_CHECK_HPP
