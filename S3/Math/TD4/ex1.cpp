//Ex2 Question 1
//Non à cause la 2eme ligne 0 < 2+9

//Ex2 Question 2
//On permute ligne 2 et 3

//3
//à partir de n



//Question 4

#include <iostream>
#include <iomanip>
#include <Eigen/Dense>
#include <ctime>
#include <cassert>
#include <cstdlib>

Eigen::MatrixXd MatDiagoDominante(const unsigned int size){
  Eigen::MatrixXd m(size,size);
  m=Eigen::MatrixXd::Random(size,size)+size*Eigen::MatrixXd::Identity(size,size);
  return m;
}

Eigen::VectorXd gaussSeidel(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const uint nbIter){

  Eigen::VectorXd x = Eigen::VectorXd::Zero(b.size());

  for(uint iter=0; iter<nbIter; iter++){
    for (int i = 0; i < A.rows(); i++) {
      double sum = 0.0;
      for (int j = 0; j < A.cols(); j++) {
        if(i !=j) sum+= A(i,j)*x(j);
      }
      x(i) = (b(i)-sum)/A(i,i);
    }
  }

  return x;
}

int main(int argc, char const *argv[]) {
  Eigen::MatrixXd matTest= MatDiagoDominante(3);
  std::cout <<  matTest<< '\n';
  Eigen::VectorXd vTest = Eigen::VectorXd::Random(3);

  Eigen::VectorXd res = gaussSeidel(matTest,vTest,12);

  std::cout << res << '\n';
  return 0;
}
