#include <iostream>
#include <iomanip>
#include <functional>
#include <cmath>
#include <cassert>



double trapeze(std::function<double(const double&)> &f,
               const double &lowerBound,
               const double &upperBound,
               const int NbIntervals){

    const double step = (upperBound-lowerBound)/NbIntervals;
    float sum=0;
    for (int i = 1; i < NbIntervals; i++) {
      sum+=f(lowerBound+i*step);
    }
    return step/2*(f(lowerBound)+f(upperBound)+2*sum);
}


double simpson(std::function<double(const double&)> &f,
               const double &lowerBound,
               const double &upperBound,
               const int NbIntervals){

    const double step = (upperBound-lowerBound)/NbIntervals;
    float evenSum = 0;
    float oddSum = 0;

    for(unsigned int i=1; i<NbIntervals; i+=2)
        oddSum += f(lowerBound +i*step);

    for(unsigned int i=2; i<NbIntervals-1; i+=2)
        evenSum += f(lowerBound +i*step);

    return step/3*(f(lowerBound)+f(upperBound)+4*oddSum+2*evenSum);
}


double gaussLegendre3pts(std::function<double(const double&)> &f)
{
    const double A0 = 5.0 / 9.0;
    const double A1 = 8.0 / 9.0;
    const double A2 = 5.0 / 9.0;

    const double x0 = - sqrt(3.0 / 5.0);
    const double x1 =   0.0;
    const double x2 =   sqrt(3.0 / 5.0);

    return f(x0)*A0+f(x1)*A1+f(x2)*A2;
}


void mainTrapezeSimpson()
{
    std::function<double(const double&)> f, F;
    // f = [](const double&x){return 3*x*x + 2*x -1 ;};  // 3x^2 + 2x -1
    // F = [](const double&x){return x*x*x + x*x -x ;};  //  x^3 + x^2 -x
    f = [](const double&x){return (16.0*x*x*x - 42.0*x*x + 2.0*x) / (sqrt(-16.0*std::pow(x,8) + 112.0*std::pow(x,7) - 204.0*std::pow(x,6) + 28.0*std::pow(x,5) -x*x*x*x + 1.0))  ;};
    F = [](const double&x){return asin(4.0*x*x*x*x -14.0*x*x*x + x*x) ;};

    const unsigned int nbSubdivisions = 100;
    const int nbDigits = 20;
    const double lowerBound =  -0.2;
    const double upperBound =   0.3;

    std::cout << "nb subdivisions  : " << nbSubdivisions << std::endl;
    std::cout << "trapèzes         : " << std::setprecision(nbDigits) << trapeze(f,lowerBound, upperBound, nbSubdivisions) << std::endl;
    std::cout << "simpson          : " << std::setprecision(nbDigits) << simpson(f,lowerBound, upperBound, nbSubdivisions) << std::endl;
    std::cout << "solution exacte  : " << std::setprecision(nbDigits) << F(upperBound) - F(lowerBound) << std::endl;
    std::cout << std::endl << std::endl;
}


void mainGaussLegendre()
{
    std::function<double(const double&)> f, g, F, G;
    f = [](const double&x){return -x*x*x*x + 2.0*x*x*x + 3.0 ;};  // -x^4 + 2x^3 +3
    F = [](const double&x){return (-x*x*x*x*x)/5+0.5*x*x*x*x+3.0*x;};
    g = [](const double&x){return -x*x*x*x + 2.0*x*x*x + 3.0 + 0.2*cos(3.0*M_PI*x) ;};  //  f(x) + 0.2 cos(3 pi x)
    G = [](const double&x){return (-x*x*x*x*x)/5+0.5*x*x*x*x+3.0*x + (0.2/(3.0*M_PI))*sin(3.0*M_PI*x) ;};

    const int nbDigits = 20;
    const int nbSubdivisions = 100;

    std::cout << "solution exacte   : " << std::setprecision(nbDigits) << F(1) - F(-1) << std::endl;
    std::cout << "Gauss-Legendre f  : " << std::setprecision(nbDigits) << gaussLegendre3pts(f) << std::endl;
    std::cout << "trapèzes f        : " << std::setprecision(nbDigits) << trapeze(f,-1.0, 1.0, nbSubdivisions) << std::endl;
    std::cout << "simpson f         : " << std::setprecision(nbDigits) << simpson(f,-1.0, 1.0, nbSubdivisions) << std::endl << std::endl;

    std::cout << "solution exacte   : " << std::setprecision(nbDigits) << G(1) - G(-1) << std::endl;
    std::cout << "Gauss-Legendre g  : " << std::setprecision(nbDigits) << gaussLegendre3pts(g) << std::endl;
    std::cout << "trapèzes g        : " << std::setprecision(nbDigits) << trapeze(g,-1.0, 1.0, nbSubdivisions) << std::endl;
    std::cout << "simpson g         : " << std::setprecision(nbDigits) << simpson(g,-1.0, 1.0, nbSubdivisions) << std::endl;
}


int main()
{
    mainTrapezeSimpson();

    mainGaussLegendre();

    return 0;
}
