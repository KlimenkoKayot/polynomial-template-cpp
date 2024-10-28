#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Polynomial {
private:
	std::vector<T> data;
	inline static const T defaultValue{ 0 };

	void Normalize() {
		while (!data.empty() && data.back() == defaultValue) {
			data.pop_back();
		}
	}

public:
	const std::vector<T>& Data() const {
		return data;
	}

	using const_iterator = typename std::vector<T>::const_iterator;

	explicit Polynomial(const std::vector<T>& k = {}) : data(k) {
		Normalize();
	}

	explicit Polynomial(const T& kf) : data{ kf } {
		Normalize();
	}

	template <typename Iter>
	Polynomial(Iter begin, Iter end) : data(begin, end) {
		Normalize();
	}
	Polynomial<T>& operator += (const Polynomial<T>& rhs);
	Polynomial<T>& operator += (const T& rhs);

	Polynomial<T>& operator -= (const Polynomial<T>& rhs);
	Polynomial<T>& operator -= (const T& rhs);

	Polynomial<T>& operator *= (const Polynomial<T>& rhs);
	Polynomial<T>& operator *= (const T& rhs);

	const T& operator [] (int i) const;

	// Степень многочлена
	int Degree() const;

	// Вычисление многочлена в точке
	T operator () (const T& point) const;

	// Начиная с первого НЕ нуля
	const_iterator begin() const {
		return data.cbegin();
	}
	const_iterator end() const {
		return data.cend();
	}
};


template <typename T>
bool operator == (const Polynomial<T>& lhs, const Polynomial<T>& rhs);

template <typename T>
bool operator == (const Polynomial<T>& lhs, const T& rhs);

template <typename T>
bool operator == (const T& lhs, const Polynomial<T>& rhs);


template <typename T>
bool operator != (const Polynomial<T> &lhs, const Polynomial<T>& rhs);

template <typename T>
bool operator != (const Polynomial<T> &lhs, const T& rhs);

template <typename T>
bool operator != (const T& lhs, const Polynomial<T> &rhs);


template <typename T>
Polynomial<T> operator + (Polynomial<T> lhs, const Polynomial<T>& rhs);

template <typename T>
Polynomial<T> operator + (Polynomial<T> lhs, const T& rhs);

template <typename T>
Polynomial<T> operator + (const T& lhs, Polynomial<T> rhs);


template <typename T>
Polynomial<T> operator - (Polynomial<T> lhs, const Polynomial<T>& rhs);

template <typename T>
Polynomial<T> operator - (Polynomial<T> lhs, const T& rhs);

template <typename T>
Polynomial<T> operator - (const T& lhs, Polynomial<T> rhs);


template <typename T>
Polynomial<T> operator * (Polynomial<T> lhs, const Polynomial<T>& rhs);

template <typename T>
Polynomial<T> operator * (Polynomial<T> lhs, const T& rhs);

template <typename T>
Polynomial<T> operator * (const T& lhs, Polynomial<T> rhs);


// Вывод от старшей степени к младшей (reversed)
template <typename T>
std::ostream& operator << (std::ostream& out, const Polynomial<T>& val);