#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Polynomial {
private:
	std::vector<T> data;

public:
	Polynomial(const std::vector<T>& k);
	Polynomial(const T& kf);

	// по итераторам
	template <typename Iter>
	Polynomial(Iter begin, Iter end);

	bool operator == (const Polynomial<T>& rhs) const;
	bool operator == (const T& rhs) const;

	bool operator != (const Polynomial<T>& rhs) const;
	bool operator != (const T& rhs) const;

	Polynomial<T>& operator += (const Polynomial<T>& rhs);
	Polynomial<T>& operator += (const T& rhs);

	Polynomial<T>& operator -= (const Polynomial<T>& rhs);
	Polynomial<T>& operator -= (const T& rhs);

	Polynomial<T>& operator *= (const Polynomial<T>& rhs);
	Polynomial<T>& operator *= (const T& rhs);

	Polynomial<T> operator + (const Polynomial<T>& rhs) const;
	Polynomial<T> operator + (const T& rhs) const;

	Polynomial<T> operator - (const Polynomial<T>& rhs) const;
	Polynomial<T> operator - (const T& rhs) const;

	Polynomial<T> operator * (const Polynomial<T>& rhs) const;
	Polynomial<T> operator * (const T& rhs) const;

	const T& operator [] (size_t i) const;

	// Степень многочлена
	int Degree() const;

	// Вычисление многочлена в точке
	T operator () (const T& point) const;

	// Константные итераторы
	using const_iterator = decltype(data.cbegin());
	// Начиная с первого НЕ нуля
	const_iterator begin() const {

	}
	const_iterator end() const {

	}
};


template <typename T>
bool operator == (const T& lhs, const Polynomial<T>& rhs);

template <typename T>
bool operator != (const T& lhs, const Polynomial<T>& rhs);

template <typename T>
Polynomial<T> operator + (const T& lhs, const Polynomial<T>& rhs);

template <typename T>
Polynomial<T> operator - (const T& lhs, const Polynomial<T>& rhs);

template <typename T>
Polynomial<T> operator * (const T& lhs, const Polynomial<T>& rhs);

// Вывод от старшей степени к младшей (reversed)
template <typename T>
std::ostream& operator << (std::ostream& out, const Polynomial<T>& val);
