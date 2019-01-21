
#pragma once

#include <cstddef>

namespace ctl {

template <typename T>
class Vector {
private:
	T *data;
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

	void Resize(size_t size);
	size_t Size() const { return size; }

	void Reserve(size_t size);
	size_t Capacity() const { return capacity; }

	// TODO: Add iterators
};

} // namespace ctl