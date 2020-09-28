// ================================
// POO C++ - IMAC 2
// TP 1 - Exercice 4
// ================================

#include <iostream>
#include <vector>
#include "chrono.hpp"

namespace TP_CPP_IMAC2
{
	float mean(const std::vector<int> &vec){
		float res=0;
		for (int i = 0; i < (int)vec.size(); i++) {
			res+=vec[i];
		}
		return res/vec.size();
	}
	float meanCopy(const std::vector<int> vec){
		float res=0;
		for (int i = 0; i < (int)vec.size(); i++) {
			res+=vec[i];
		}
		return res/vec.size();
	}
	int main(int argc, char *argv[])
	{

		Chrono chrono;
		std::vector<int> u_vector;
		int size_vector;

		std::cout << "Entrez la taille du vecteur" << std::endl;
		std::cin >> size_vector;

		for (int i = 0; i < size_vector; i++) {
			u_vector.push_back(i%10);
		}

		std::cout << "Taille du vecteur : " << u_vector.size() << '\n';
		// for (int i = 0; i < (int)u_vector.size(); i++) {
		// 	std::cout << "La valeur " << i << " est " << u_vector[i] << std::endl;
		// }
		for (int i = 0; i < 3; i++) {
			std::cout << "La valeur " << i << " est stockée à l'adresse : " << &u_vector[i] << std::endl;
		}

		chrono.start();
		mean(u_vector);
		chrono.stop();
		std::cout << "Time Mean : " << chrono.timeSpan() << std::endl;

		chrono.start();
		meanCopy(u_vector);
		chrono.stop();
		std::cout << "Time Mean Copy : " << chrono.timeSpan() << std::endl;

		u_vector.pop_back();
		u_vector.clear();
		return 0;
	}
}

// Fonction main classique, point d'entrée du programme
int main(int argc, char *argv[])
{
	// Appel de la fonction main de l'espace de nom TP_CPP_IMAC2
	return TP_CPP_IMAC2::main(argc, argv);
}
