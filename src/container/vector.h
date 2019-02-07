
#pragma once

#include <cstddef>

namespace ctl {

template <typename T>
class Vector {
private:
	T *data;
	uint8_t *mem;
	size_t size;
	size_t capacity;

public:
	Vector();
	Vector(size_t n);
	Vector(size_t n, T default_data);
	Vector(const Vector &other);
	Vector &operator=(const Vector &other);
	Vector(Vector &&other);
	Vector &operator=(Vector &&other);

	~Vector();

	void Reserve(size_t newCapacity);
	size_t Capacity() const { return capacity; }

	void Resize(size_t newSize);
	size_t Size() const { return size; }

	bool Empty() const;

	T &operator[](size_t index);
	T &At(size_t index);
	T &Get(size_t index);
	T &Front();
	T &Back();

	void PushBack(const T &val);
	T PopBack();

public:
	class Iterator {
	private:
		T *ptr;

	public:
		Iterator(T *ptr);

		Iterator operator++();
		Iterator operator--();

		T &operator*();
		const T &operator*() const;
		T *operator->();

		bool operator==(const Iterator &rhs);
		bool operator!=(const Iterator &rhs);
	};

	Vector<T>::Iterator begin();
	Vector<T>::Iterator end();
};

} // namespace ctl