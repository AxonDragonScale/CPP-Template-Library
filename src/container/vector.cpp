
#include "vector.h"

namespace ctl {

template <typename T>
Vector<T>::Vector() :
		data(nullptr),
		mem(nullptr),
		size(0),
		capacity(0) {
}

template <typename T>
Vector<T>::Vector(size_t n) :
		mem(new uint8_t[n * sizeof(T)]),
		size(n),
		capacity(n) {
	data = reinterpret_cast<T *>(mem);
}

template <typename T>
Vector<T>::Vector(size_t n, T default_data) :
		mem(new uint8_t[n * sizeof(T)]),
		size(n),
		capacity(n) {
	data = reinterpret_cast<T *>(mem);
	for (int i = 0; i < n; i++) {
		data[i] = default_data;
	}
}

template <typename T>
Vector<T>::Vector(const Vector &other) {
	// delete original data
	for (int i = 0; i < size; i++) {
		(data + i)->~T();
	}
	delete mem;

	size = other.size;
	capacity = other.capacity;

	mem = new uint8_t[size * sizeof(T)];
	data = reinterpret_cast<T *>(mem);
	for (int i = 0; i < size; i++) {
		data[i] = other[i];
	}
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
	for (int i = 0; i < size; i++) {
		(data + i)->~T();
	}
	delete mem;

	size = other.size;
	capacity = other.capacity;

	mem = new uint8_t[size * sizeof(T)];
	data = reinterpret_cast<T *>(mem);
	for (int i = 0; i < size; i++) {
		data[i] = other[i];
	}
}

template <typename T>
Vector<T>::Vector(Vector &&other) {
	for (int i = 0; i < size; i++) {
		(data + i)->~T();
	}
	delete mem;

	size = other.size;
	capacity = other.capacity;
	data = other.data;
	mem = other.mem;

	other.mem = nullptr;
	other.data = nullptr;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector &&other) {
	for (int i = 0; i < size; i++) {
		(data + i)->~T();
	}
	delete mem;

	size = other.size;
	capacity = other.capacity;
	data = other.data;
	mem = other.mem;

	other.mem = nullptr;
	other.data = nullptr;
}

template <typename T>
Vector<T>::~Vector() {
	for (int i = 0; i < size; i++) {
		(data + i)->~T();
	}

	data = nullptr;
	delete mem;
	mem = nullptr;
}

template <typename T>
void Vector<T>::Reserve(size_t newCapacity) {
	if (newCapacity > capacity) {
		uint8_t newMem = new uint8_t[newCapacity * sizeof(T)];

		if (size != 0) {
			memcpy(newMem, mem, size * sizeof(T));
		}

		if (mem != nullptr) delete mem;
		mem = newMem;
		data = reinterpret_cast<T *>(mem);
		capacity = newCapacity;
	} else {
		return;
	}
}

template <typename T>
void Vector<T>::Resize(size_t newSize) {
	if (newSize < size) {
		for (int i = newSize; i < size; i++) {
			(data + i)->~T();
		}
	} else if (newSize > size) {
		if (capacity < newSize) {
			this->Reserve(newSize);
		}

		for (int i = size; i < newSize; i++) {
			data[i] = T();
		}
	}
	size = newSize;
}

template <typename T>
bool Vector<T>::Empty() const {
	return size == 0;
}

template <typename T>
T &Vector<T>::operator[](size_t index) {
	return data[index];
	// TODO: policy based implementation
}

template <typename T>
T &Vector<T>::At(size_t index) {
	if (index < size) {
		return data[index];
	} else {
		// TODO: throw exception
	}
}

template <typename T>
T &Vector<T>::Get(size_t index) {
	return data[index];
}

template <typename T>
T &Vector<T>::Front() {
	return data[0];
}

template <typename T>
T &Vector<T>::Back() {
	return data[size - 1];
}

template <typename T>
void Vector<T>::PushBack(const T &val) {
	if (size == capacity) {
		if (capacity == 0) {
			this->Reserve(10);
		} else {
			this->Reserve(2 * capacity);
		}
	}

	data[size++] = val;
}

template <typename T>
T Vector<T>::PopBack() {
	size--;
	return data[size - 1];
}

// begin and end iterator for using range based for loop
template <typename T>
Vector<T>::Iterator Vector<T>::begin() {
	return Vector<T>::Iterator(data);
}

template <typename T>
Vector<T>::Iterator Vector<T>::end() {
	return Vector<T>::Iterator(data + n);
}

// Inner Iterator class code
template <typename T>
Vector<T>::Iterator::Iterator(T *ptr) :
		ptr(ptr) {}

template <typename T>
Vector<T>::Iterator Vector<T>::Iterator::operator++() {
	++ptr;
	return *this;
}

template <typename T>
Vector<T>::Iterator Vector<T>::Iterator::operator--() {
	--ptr;
	return *this;
}

template <typename T>
T &Vector<T>::Iterator::operator*() {
	return *ptr;
}

template <typename T>
const T &Vector<T>::Iterator::operator*() const {
	return *ptr;
}

template <typename T>
T *Vector<T>::Iterator::operator->() {
	return ptr;
}

template <typename T>
bool Vector<T>::Iterator::operator==(const Iterator &rhs) {
	return ptr == rhs.ptr;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const Iterator &rhs) {
	return ptr != rhs.ptr;
}

} // namespace ctl
