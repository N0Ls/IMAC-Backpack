#include <iostream>
#include <iomanip>
#include <functional>
#include <cmath>


double dichotomy(std::function<double(const double&)> &f,
                  double lowerBound,
                  double upperBound,
                  const unsigned int nbIterations){
    double mid;
    for (size_t i = 0; i < nbIterations; i++) {
      mid = (lowerBound + upperBound)*0.5;
      if(f(lowerBound)*f(mid) < 0){
        upperBound=mid;
      }
      else{
        lowerBound=mid;
      }
    }
    return (lowerBound + upperBound)*0.5;
}

unsigned int dichotomyNbIteration(const double &lowerBound, const double &upperBound, const double &precision){
    return (log((upperBound-lowerBound)/precision)/log(2))-1;
}


double Newton(std::function<double(const double&)> &f,
              std::function<double(const double&)> &derivative,
              const double &input,
              const double &threshold,
              int &maxIterations) // ref just to get back the number of iterations
{
  double x = input;
  int i = 0;

  while (std::abs(f(x))>threshold && i<maxIterations) {
    x-=(f(x)/derivative(x));
    i++;
  }
  maxIterations = i;
  return x;
}


void mainDichotomy()
{
    std::function<double(const double&)> f = [](const double&x){return cos(x) - 2*x;};
    const double precision = 1.0e-7;
    const unsigned int nbIterations = dichotomyNbIteration(-M_PI,M_PI,precision);

    std::cout << "requested precision  : " << precision << std::endl;
    std::cout << "suggested iterations : " << nbIterations << std::endl;
    double root = dichotomy(f,-M_PI,M_PI,nbIterations);
    std::cout << "dichotomy            : " << root << std::endl;
    std::cout << "f(root)              : " << f(root) << std::endl << std::endl;
}

void mainNewton()
{
    std::function<double(const double&)> f, derivative;
    // f = [](const double&x){return ((exp(x)-1.0)/(exp(x)+1.0)) + (3.0/4.0) ;};
    // derivative = [](const double&x){return 2.0*exp(x) / ((exp(x)+1.0)*(exp(x)+1.0)) ;};
    f = [](const double&x){return cos(x) - 2*x;};
    derivative = [](const double&x){return -sin(x) - 2;};

    const double precision = 1.0e-7;
    int maxIterations = 24;
    const double x = 0.0;

    std::cout << "requested precision  : " << precision << std::endl;
    std::cout << "input estimattion    : " << x << std::endl;
    double root = Newton(f,derivative,x,precision,maxIterations);
    std::cout << "Newton               : " << root << std::endl;
    std::cout << "f(root)              : " << f(root) << std::endl;
    std::cout << "nb iterations        : " << maxIterations << std::endl;
}


int main()
{
    mainDichotomy();

    mainNewton();

    return 0;
}
