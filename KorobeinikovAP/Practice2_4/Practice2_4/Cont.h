#ifndef CONT_H

#define CONT_H

#include 

template <typename T>
class TCont {
private:
	int size;
	T* el;
	int maxsize;
	int step;
	int pos;
public:
	TCont(int size, int maxsize, int step) {
		this->maxsize = maxsize;
		this->step = step;
		this->pos = 
	}
	TCont(const TCont& Container) {
		size = Container.size;
		el = Container.el;
		maxsize = Container.maxsize;
		step = Container.step;
	}
	~TCont() {
		free[] el;
	}
	T& operator [] (int index) {
		return (el[index]);
	}
	void insert(const T& obj) {

	}
};


#endif 
