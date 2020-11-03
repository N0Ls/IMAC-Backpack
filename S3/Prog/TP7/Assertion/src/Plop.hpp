#pragma once

#include <cmath>
#include <cassert>

template<int N>
class Plop{

private :
	double _data[N];

public :
	Plop() {static_assert(N < 6, "_data should be lower than 6");}
	~Plop() = default;
	double myPublicPlop() const;

private :
	double myPrivatePlop(const double &value) const;

};


template<int N>
double Plop<N>::myPublicPlop() const {

	double a = 42;
	// ask somthing to the user to change variable 'a' ...
	return myPrivatePlop(a*a);
}


template<int N>
double Plop<N>::myPrivatePlop(const double &value) const {
	assert( (value >= 0.0) && "error: Plop::myPrivatePlop: value should be positive");
	return sqrt(value);
}
