
#include "vector.h"

namespace ctl {

template <typename T>
Vector<T>::Vector() :
		data(nullptr),
		size(0),
		capacity(0) {
}

template <typename T>
Vector<T>::Vector(size_t n) :
		size(n),
		capacity(n) {
	data = new T[n];
}

template <typename T>
Vector<T>::Vector(size_t n, T default_data) :
		size(n),
		capacity(n) {
	data = new T[n];
	for (int i = 0; i < n; i++) {
		data[i] = default_data;
	}
}

template <typename T>
Vector<T>::Vector(const Vector &other) {
	delete data;
	size = other.size();
	capacity = other.capacity();

	data = new T[size];
	for (int i = 0; i < size; i++) {
		data[i] = other[i];
	}
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
	delete data;
	size = other.size;
	capacity = other.capacity;

	data = new T[size];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template <typename T>
Vector<T>::Vector(Vector &&other) {
	delete data;

	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullprt;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector &&other) {
	delete data;

	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullprt;
}

} // namespace ctl
