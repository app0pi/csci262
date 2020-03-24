#ifndef _Queue_h
#define _Queue_h

template <class T>
class Queue {
public:
	Queue() { //constructor
		_front = 0;
		_back = 0;
		_size = 0;
		_capacity = 1;
		_data = new T[_capacity];
	}

	Queue(const Queue& qu){ //copy constructor
		_front = qu._front;
		_back = qu._back;
		_size = qu._size;
		_capacity = qu._capacity;
		for(int i=qu._front; i<qu._front+qu._size; i++) {
			_data[i%_capacity] = qu._data[i%qu._capacity];
		}
    };

    ~Queue(){ // destructor
		delete[] _data;
    };

    Queue& operator=(const Queue& qu) { // assignment operator
		if(this==&qu) return *this;
		delete[] _data;
		_front = qu._front;
		_back = qu._back;
		_size = qu._size;
		_capacity = qu._capacity;
		_data = new T[_capacity];
		for(int i=qu._front; i<qu._front+qu._size; i++) {
			_data[i%_capacity] = qu._data[i%qu._capacity];
		}
		return *this;
    }

	bool enqueue(T c) {
        if (_size == _capacity) {
        	T* temp = new T[_capacity*2];
        	for(int i=0; i<_size; i++) {
        		temp[i] = _data[(i+_front)%_capacity];
        	}
        	_front = 0;
        	_size++;
			_back = _size;
        	temp[_back-1] = c;
			delete[] _data;
        	_data = temp;
        	_capacity = _capacity*2;
        }
		else {
			_size++;
			_data[_back] = c;
			_back = (_back+1)%_capacity;
		}
		return true;
	}

	bool dequeue()  { 
		if (is_empty()) return false;
		_front = (_front+1)%_capacity;
        _size--;
		return true;
	}

	T get_front() { return _data[_front]; }
	T get_back() { return _data[_back]; }
	bool is_empty() { return _size == 0; }
	int get_size() {return _size; }

private:
	T *_data;
    int _size;
	int _front;
	int _back;
	int _capacity;
};

#endif