#include <iostream>

#include "VectorD.hpp"


int main(int argc, char **argv) {

    VectorD v1(3);
    v1[0] = 1.0;
    v1[1] = 0.3;
    v1[2] = 5.2;

    VectorD v2(4);
    v2[0] = -1.0;
    v2[1] =  3.0;
    v2[2] = 42.0;
    v2[3] =  2.0;

    std::cout << "v1 + v2  : " << v1 + v2 << std::endl;
    std::cout << "v1 - v2  : " << v1 - v2 << std::endl;
    std::cout << "v1.v2    : " << v1.dot(v2) << std::endl;

    VectorD v3;
    v3.load("wazoo.vec");



    return 0;
}
