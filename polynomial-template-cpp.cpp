#include "polynomial-template-cpp.h"

#include <vector>

//std::vector<T> data;
//const T defaultValue{ 0 };
// 
// Data() -> возвращает std::vector<T> data;
// Normalize() -> уничтожает нули в конце data;

template <typename T>
bool operator == (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
	return lhs.Data() == rhs.Data();
}

template <typename T>
bool operator == (const Polynomial<T>& lhs, const T& rhs) {
	return lhs.Data() == std::vector<T>{rhs};
}

template <typename T>
bool operator == (const T& lhs, const Polynomial<T>& rhs) {
	return rhs == lhs;
}

template <typename T>
bool operator != (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator != (const Polynomial<T>& lhs, const T& rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator != (const T& lhs, const Polynomial<T>& rhs) {
	return !(rhs == lhs);
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator += (const Polynomial<T>&rhs){
	if (rhs.Degree() > Degree()) {
		data.resize(rhs.Degree() + 1);
	}
	for (int i = 0; i <= Degree(); ++i) {
		data[i] += rhs[i];
	}
	Normalize();
	return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator += (const T& rhs) {
	for (int i = 0; i <= Degree(); ++i) {
		data[i] += rhs;
	}
	Normalize();
	return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator -= (const Polynomial<T>&rhs){
	if (rhs.Degree() > Degree()) {
		data.resize(rhs.Degree() + 1);
	}
	for (int i = 0; i <= Degree(); ++i) {
		data[i] -= rhs[i];
	}
	Normalize();
	return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator -= (const T& rhs) {
	for (int i = 0; i <= Degree(); ++i) {
		data[i] -= rhs;
	}
	Normalize();
	return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator *= (const Polynomial<T>&rhs){
	if (rhs.Degree() > Degree()) {
		data.resize(rhs.Degree() + 1);
	}
	for (int i = 0; i <= Degree(); ++i) {
		data[i] *= rhs[i];
	}
	Normalize();
	return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator *= (const T& rhs) {
	for (int i = 0; i <= Degree(); ++i) {
		data[i] *= rhs;
	}
	Normalize();
	return *this;
}

template <typename T>
Polynomial<T> operator + (Polynomial<T> lhs, const Polynomial<T>& rhs) {
	return lhs += rhs;
}

template <typename T>
Polynomial<T> operator + (Polynomial<T> lhs, const T& rhs) {
	return lhs += rhs;
}

template <typename T>
Polynomial<T> operator + (const T& lhs, Polynomial<T> rhs) {
	return rhs += lhs;
}

template <typename T>
Polynomial<T> operator - (Polynomial<T> lhs, const Polynomial<T>& rhs) {
	return lhs -= rhs;
}

template <typename T>
Polynomial<T> operator - (Polynomial<T> lhs, const T& rhs) {
	return lhs -= rhs;
}

template <typename T>
Polynomial<T> operator - (const T& lhs, Polynomial<T> rhs) {
	return rhs -= lhs;
}

template <typename T>
Polynomial<T> operator * (Polynomial<T> lhs, const Polynomial<T>& rhs) {
	return lhs *= rhs;
}

template <typename T>
Polynomial<T> operator * (Polynomial<T> lhs, const T& rhs) {
	return lhs *= rhs;
}

template <typename T>
Polynomial<T> operator * (const T& lhs, Polynomial<T> rhs) {
	return rhs *= lhs;
}

template <typename T>
int Polynomial<T>::Degree() const {
	return static_cast<int>(data.size()) - 1;
}

template <typename T>
const T& Polynomial<T>::operator [] (int i) const {
	if (i > Degree()) {
		return defaultValue;
	}
	return data[i];
}

template <typename T>
T Polynomial<T>::operator () (const T& point) const {
	T result = defaultValue;
	for (int i = Degree(); i >= 0; --i) {
		result *= point;
		result += data[static_cast<size_t>(i)];
	}
	return result;
}

// Вывод от старшей степени к младшей (reversed)
template <typename T>
std::ostream& operator << (std::ostream& out, const Polynomial<T>& val) {
	for (int i = val.Degree(); i >= 0; --i) {
		out << val[i];
		if (i != 0) {
			out << ' ';
		}
	}
	return out;
}
