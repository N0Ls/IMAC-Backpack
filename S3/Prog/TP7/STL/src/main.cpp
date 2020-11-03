
#include<iostream>
#include<vector>
#include <functional>

int main(){

	/////////////////////////////////////////////////////////
	try{
			std::vector<long double> vec(100000000000000000);
	} catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
			std::cerr << "... but I can handle this exception, let's continue." << std::endl << std::endl;
	}


	/////////////////////////////////////////////////////////
	std::vector<double> vec2(5,0.0);
	double value;
	try{
			value = vec2.at(10);
	} catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
			 std::cerr << "... but I can handle this exception, let's continue." << std::endl << std::endl;
	}


	/////////////////////////////////////////////////////////
	std::function<int(int,int)> plop;  // function declared but not defined
	int a;
	try{
			a = plop(42,42);
	} catch(const std::exception &e){
			std::cerr << e.what() << std::endl;
			 std::cerr << "... but I can handle this exception, let's continue." << std::endl << std::endl;
	}


	std::cout << "end of program" << std::endl;

	return 0;
}
