
#include "vector.h"

namespace ctl {

template <typename T>
Vector<T>::Vector() {
}

template <typename T>
Vector<T>::Vector(size_t n) {}

template <typename T>
Vector<T>::Vector(size_t n, T default_data) {}

template <typename T>
Vector<T>::Vector(const Vector &other) {}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other) {}

template <typename T>
Vector<T>::Vector(Vector &&other) {}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector &&other) {}

} // namespace ctl