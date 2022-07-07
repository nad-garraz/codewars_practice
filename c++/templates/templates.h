#ifndef TEMPLATES_H
#define TEMPLATES_H

template <typename T>
inline void swap(T &x, T &y) {
	T temp = std::move(x);
	x = std::move(y);
	y = std::move(temp);
};


template <typename T>
inline void print_items(T &x) {
	for( auto item : x ) {
		std::cout << "Item: " << item << std::endl;
	}
};

#endif
