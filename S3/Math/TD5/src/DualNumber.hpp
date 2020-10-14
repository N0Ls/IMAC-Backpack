#pragma once

#include <fstream>
#include <cmath>

template <typename T>
class DualNumber{

	private :
		T _real;
		T _dual;

	public :
		DualNumber() = default;
		DualNumber(const T& real, const T &dual) : _real(real), _dual(dual) {};
		~DualNumber() = default;

		inline T & real() {return _real;};
		inline T & dual() {return _dual;};
		inline const T & real() const {return _real;};
		inline const T & dual() const {return _dual;};


		DualNumber operator+(const DualNumber &dn) const;
		DualNumber operator-(const DualNumber &dn) const;
		DualNumber operator*(const DualNumber &dn) const;
		DualNumber operator/(const DualNumber &dn) const;
		DualNumber operator+(const T &value) const;
		DualNumber operator-(const T &value) const;
		DualNumber operator*(const T &value) const;
		DualNumber operator/(const T &value) const;

	 	inline friend DualNumber operator+(const T &value, const DualNumber &dn) {return dn+value;}
		inline friend DualNumber operator-(const T &value, const DualNumber &dn) {return dn-value;}
	 	inline friend DualNumber operator*(const T &value, const DualNumber &dn) {return dn*value;}
		inline friend DualNumber operator/(const T &value, const DualNumber &dn) {return dn/value;}
		inline friend DualNumber operator-(const DualNumber &dn) {return DualNumber(-dn._real,-dn._dual);} // unary minus


		static DualNumber sin(const DualNumber & dn);
		static DualNumber cos(const DualNumber & dn);
		// static DualNumber tan(const DualNumber & dn);
		static DualNumber exp(const DualNumber & dn);
		static DualNumber log(const DualNumber & dn);
		static DualNumber abs(const DualNumber & dn);
		static DualNumber pow(const DualNumber & dn, const T &n);
		static DualNumber sqrt(const DualNumber & dn);

		template<typename U>
        friend std::ostream& operator<< (std::ostream& stream, const DualNumber<U> &dn);
};


template<typename U>
std::ostream& operator<< (std::ostream& stream, const DualNumber<U> &dn){
	stream << "(" << dn._real << ", " << dn._dual << ")";
    return stream;
}

template <typename T>
DualNumber<T> DualNumber<T>::operator+(const DualNumber &dn) const {
	return DualNumber(this->_real + dn._real, this->_dual + dn._dual);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator-(const DualNumber &dn) const {
	return DualNumber(this->_real - dn._real, this->_dual - dn._dual);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator*(const DualNumber &dn) const {
	return DualNumber(this->_real * dn._real, this->_dual*dn._real + this->_real*dn._dual);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator/(const DualNumber &dn) const {
	return DualNumber(this->_real / dn._real, -(this->_real/dn._dual)/pow(this->_dual,2));
}

template <typename T>
DualNumber<T> DualNumber<T>::operator+(const T &value) const {
	return DualNumber(this->_real + value, this->_dual+value);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator-(const T &value) const {
	return DualNumber(this->_real - value, this->_dual-value);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator*(const T &value) const {
	return DualNumber(this->_real * value, this->_dual*value);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator/(const T &value) const {
	return DualNumber(this->_real / value, this->_dual/value);
}

template <typename T>
DualNumber<T> DualNumber<T>::sin(const DualNumber<T> & dn){
	return DualNumber<T>(std::sin(dn._real),dn._dual*std::cos(dn._real));
}

template <typename T>
DualNumber<T> DualNumber<T>::cos(const DualNumber<T> & dn){
	return DualNumber<T>(std::cos(dn._real),dn._dual*std::sin(dn._real));
}

template <typename T>
DualNumber<T> DualNumber<T>::exp(const DualNumber<T> & dn){
	return DualNumber<T>(std::exp(dn._real),dn._dual*std::exp(dn._real));
}

template <typename T>
DualNumber<T> DualNumber<T>::log(const DualNumber<T> & dn){
	return DualNumber<T>(std::log(dn._real),dn._dual/dn._real);
}

template <typename T>
DualNumber<T> DualNumber<T>::pow(const DualNumber<T> & dn,const T &k){
	return DualNumber<T>(std::pow(dn._real,k),k*std::pow(dn._real,k-1)*dn._dual);
}

template <typename T>
DualNumber<T> DualNumber<T>::sqrt(const DualNumber<T> & dn){
	return DualNumber<T>(std::sqrt(dn._real),dn._dual/(2*std::sqrt(dn._real)));
}

template <typename T>
DualNumber<T> DualNumber<T>::abs(const DualNumber<T> & dn){
	return DualNumber<T>(std::abs(dn._real),dn._dual * (dn._real >= 0 ? 1: -1));
}
