#ifndef CONT_H

#define CONT_H

template <typename T>
class TCont {
private:
	int size;
	T* el;
	int maxsize;
	int step;
public:
	TCont(int maxsize, int step) {
		this->maxsize = maxsize;
		this->step = step;
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
