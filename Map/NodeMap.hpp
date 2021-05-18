//
// Created by Moaney Terresa on 4/1/21.
//

#ifndef MAP_NODEMAP_HPP
#define MAP_NODEMAP_HPP

namespace ft {
	template<typename Key, typename  T>
	class NodeMap {
	public:
		T		second;
		Key		first;
		NodeMap *parent;
		NodeMap *left;
		NodeMap *right;
		bool 	is_red;
		bool 	is_left;

	public:
		explicit NodeMap(const Key &key = Key(), const T &val = T()) : second(val), parent(0), left(0), right(0), is_red(true), first(key) {}
		NodeMap *getParent() {
			return (parent);
		}
		Key		getFirst() {
			return first;
		}
	};
}
#endif //MAP_NODEMAP_HPP
