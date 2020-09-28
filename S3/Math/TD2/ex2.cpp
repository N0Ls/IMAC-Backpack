#include <iostream>
#include <iomanip>
#include <Eigen/Dense>
#include <ctime>
#include <cassert>
#include <cstdlib>

double dotProduct(const Eigen::VectorXd &v1,const Eigen::VectorXd &v2){
  if (v1.size()!=v2.size()) {return 0;}

  double sum=0;
  for (int i = 0; i < v1.size(); i++) {
    sum += v1[i]*v2[i];
  }
  return sum;
}

int main()
{
  srand(time(0));

  //Const
  const unsigned int dimension=10000;

  //Init and filling vectors
  Eigen::VectorXd v1 = Eigen::VectorXd::Random(dimension);
  Eigen::VectorXd v2 = Eigen::VectorXd::Random(dimension);

  //Alternate filling
  v2.fill(1);

  //Homemade dot product call
  clock_t begin = clock();
  double resProdScalMaison = dotProduct(v1,v2) ;
  clock_t end = clock();
  double tempsCalc = double(end - begin) / CLOCKS_PER_SEC;

  std::cout << std::setprecision(20)<<"Homemade dot product : " << resProdScalMaison << " in : " <<tempsCalc <<"s "<<std::endl;

  //Eigen dot product call
  begin = clock();
  double resProdScalEigen = v1.dot(v2);
  end = clock();
  tempsCalc = double(end - begin) / CLOCKS_PER_SEC;

  std::cout << std::setprecision(20)<<"Eigen dot product    : " << resProdScalEigen << " in : " <<tempsCalc <<"s "<<std::endl;

  return 0;
}
