#include "polynomial-template-cpp.h"

#include <vector>

template <typename T>
Polynomial<T>::Polynomial(const std::vector<T>& k) {

}

template <typename T>
Polynomial<T>::Polynomial(const T& kf) {

}

template <typename T>
template <typename Iter>
Polynomial<T>::Polynomial(Iter begin, Iter end) {

}

template <typename T>
bool Polynomial<T>::operator == (const Polynomial<T>& rhs) const {
	return false;
}

template <typename T>
bool Polynomial<T>::operator == (const T& rhs) const  {
	return false;
}

template <typename T>
bool Polynomial<T>::operator != (const Polynomial<T>& rhs) const {
	return false;
}

template <typename T>
bool Polynomial<T>::operator != (const T& rhs) const {
	return false;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator += (const Polynomial<T>& rhs) {

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator += (const T& rhs) {

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator -= (const Polynomial<T>& rhs) {

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator -= (const T& rhs) {

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator *= (const Polynomial<T>& rhs) {

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator *= (const T& rhs) {

}

template <typename T>
Polynomial<T> Polynomial<T>::operator + (const Polynomial<T>& rhs) const {

}

template <typename T>
Polynomial<T> Polynomial<T>::operator + (const T& rhs) const {

}

template <typename T>
Polynomial<T> Polynomial<T>::operator - (const Polynomial<T>& rhs) const {

}

template <typename T>
Polynomial<T> Polynomial<T>::operator - (const T& rhs) const {

}

template <typename T>
Polynomial<T> Polynomial<T>::operator * (const Polynomial<T>& rhs) const {

}

template <typename T>
Polynomial<T> Polynomial<T>::operator * (const T& rhs) const {

}

template <typename T>
const T& Polynomial<T>::operator [] (size_t i) const {

}

template <typename T>
int Polynomial<T>::Degree() const {

}

template <typename T>
T Polynomial<T>::operator () (const T& point) const {

}

/*
	Дальше методы переопределяются, чтобы все работало нормально
*/

template <typename T>
bool operator == (const T& lhs, const Polynomial<T>& rhs) {

}

template <typename T> 
bool operator != (const T& lhs, const Polynomial<T>& rhs) {

}

template <typename T>
Polynomial<T> operator + (const T& lhs, const Polynomial<T>& rhs) {

}

template <typename T>
Polynomial<T> operator - (const T& lhs, const Polynomial<T>& rhs) {

}

template <typename T>
Polynomial<T> operator * (const T& lhs, const Polynomial<T>& rhs) {

}

// Вывод от старшей степени к младшей (reversed)
template <typename T>
std::ostream& operator << (std::ostream& out, const Polynomial<T>& val) {

}
