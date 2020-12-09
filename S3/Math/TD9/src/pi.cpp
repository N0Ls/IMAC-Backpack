#include <iostream>
#include <iomanip>
#include <cmath>

#include <random>
#include <chrono>
#include <functional> // for bind

const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651L; // 110 first digit

template<typename T>
T bad_pi(const unsigned int & n){
	return T(3.14);
}





int main(){

    std::cout << "Bad pi" << std::endl;
		std::cout << std::setprecision(30) << " error : " << PI - bad_pi<long double>(10) << std::endl;

		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::cout << "seed : " << seed << std::endl;

		std::default_random_engine generator(seed);
		std::uniform_real_distribution<float> uniformRealDistribution(0,1);


		int N = 10000000;
		int nb_point_in_circle = 0;
		for (size_t i = 0; i < N; i++) {

			float x = uniformRealDistribution(generator);
			float y = uniformRealDistribution(generator);

			if((std::pow(x,2)+std::pow(y,2))<1){
				nb_point_in_circle ++;
			}
		}

		std::cout << 4.0 * nb_point_in_circle / (double)N;

	return 0;
}
