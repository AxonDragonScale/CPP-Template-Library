
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

	T &operator[](size_t index);
	T &at(size_t index);
	T &get(size_t index);

	T &Front();
	T &Back();

	// TODO: Add iterators
};

} // namespace ctl