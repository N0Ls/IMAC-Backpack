#include <iostream>
#include <iomanip>
#include <cmath>

#include <random>
#include <chrono>
#include <functional> // for bind

bool fight(const std::vector<int> &dice1, const std::vector<int> &dice2, const unsigned int nbRolls){

    // select a random generator engine and a distribution
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distrib(0,5);
    auto dice = std::bind(distrib, generator);

    // roll dices
    unsigned int nbWinDice1 = 0;
    unsigned int nbWinDice2 = 0;
    for(unsigned int i=0; i<nbRolls; ++i){
        if(dice1[dice()] > dice2[dice()]) nbWinDice1++;
        else nbWinDice2++;
    }

    return nbWinDice1 > nbWinDice2;
}

bool fightExtention(const std::vector< int> &dice1a,
                    const std::vector< int> &dice1b,
                    const std::vector< int> &dice2a,
                    const std::vector< int> &dice2b,
                    const unsigned int nbRolls){

    // select a random generator engine and a distribution
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distrib(0,5);
    auto dice = std::bind(distrib, generator);

    // roll dices
    unsigned int nbWinDice1 = 0;
    unsigned int nbWinDice2 = 0;
    for(unsigned int i=0; i<nbRolls; ++i){
        if( (dice1a[dice()] + dice1b[dice()]) > (dice2a[dice()] + dice2b[dice()])) nbWinDice1++;
        else nbWinDice2++;
    }

    return nbWinDice1 > nbWinDice2;
}


int main(){


		std::vector<int> diceA {3,3,3,3,3,6};
		std::vector<int> diceB {2,2,2,5,5,5};
		std::vector<int> diceC {1,4,4,4,4,4};

		const unsigned int nbRolls = 1000000;
    std::cout << "A vs. B : the winner is " << (fight(diceA,diceB,nbRolls) ? "A" : "B") << " !" << std::endl;
    std::cout << "B vs. C : the winner is " << (fight(diceB,diceC,nbRolls) ? "B" : "C") << " !" << std::endl;
    std::cout << "C vs. A : the winner is " << (fight(diceC,diceA,nbRolls) ? "C" : "A") << " !" << std::endl;

		std::cout << "AB vs. AC : the winner is " << (fightExtention(diceA,diceB,diceA,diceC,nbRolls) ? "AB" : "AC") << " !" << std::endl;
   	std::cout << "BC vs. AC : the winner is " << (fightExtention(diceB,diceC,diceA,diceC,nbRolls) ? "BC" : "AC") << " !" << std::endl;
   	std::cout << "AB vs. BC : the winner is " << (fightExtention(diceA,diceB,diceB,diceC,nbRolls) ? "AB" : "BC") << " !" << std::endl;



	return 0;
}
