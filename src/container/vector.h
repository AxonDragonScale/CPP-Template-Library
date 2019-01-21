
#pragma once

#include <cstddef>

namespace ctl {
template <typename T>
class Vector {
private:
	T *m_data;
	size_t m_Size;
	size_t m_Capacity;

public:
	Vector();
	Vector(size_t n);
	Vector(size_t n, T default_data);
	Vector(const Vector &other);
	Vector &operator=(const Vector &other);
	Vector(Vector &&other);
	Vector &operator=(Vector &&other);

	void Resize(size_t size);
	size_t Size() const { return m_Size; }

	void Reserve(size_t size);
	size_t Capacity() const { return m_Capacity; }

	// TODO: Add iterators
};
} // namespace ctl
