//Ex2 Question 1
//Non à cause la 2eme ligne 0 < 2+9

//Ex2 Question 2
//On permute ligne 2 et 3

//3
//à partir de n



//Question 4

#include <iostream>
#include <Eigen/Dense>
#include <cassert>
#include <iomanip>
#include <chrono>

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

unsigned int getRank(const Eigen::MatrixXd &A){
  Eigen::FullPivLU<Eigen::MatrixXd>lu_decomp(A) ;
  return lu_decomp.rank();

}

int main(int argc, char const *argv[]) {
  unsigned int MatrixSize = 50;
  unsigned int timeNbDigits = 50;

  Eigen::MatrixXd A=MatDiagoDominante(MatrixSize);

  if(getRank(A) != MatrixSize){
    std::cout << "Matrice pas de rang plein" << '\n';
    return 1;
  }

  Eigen::VectorXd b = Eigen::VectorXd::Random(MatrixSize);

  // gauss siedel
    const uint nbIterations = 200;
    auto start = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd x_gs = gaussSeidel(A,b,nbIterations);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "GS  : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_gs).norm() << std::endl;


    // LU
    start = std::chrono::high_resolution_clock::now();
    Eigen::PartialPivLU<Eigen::MatrixXd> lu(A);
    Eigen::VectorXd x_lu = lu.solve(b);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "LU  : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_lu).norm() << std::endl;


    // QR
    start = std::chrono::high_resolution_clock::now();
    Eigen::ColPivHouseholderQR<Eigen::MatrixXd> qr(A);
    Eigen::VectorXd x_qr = qr.solve(b);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "QR  : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_qr).norm() << std::endl;

    // SVD
    start = std::chrono::high_resolution_clock::now();
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);
    Eigen::VectorXd x_svd = svd.solve(b);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "SVD : " << std::setw(timeNbDigits) << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " micro-sec | error : " << std::setprecision(3) << (b-A*x_svd).norm() << std::endl;

  return 0;
}
