#include <iostream>
#include "Plop.hpp"

int main(){

	Plop<3> myPlop;

	std::cout << myPlop.myPublicPlop() << std::endl;

	return 0;
}