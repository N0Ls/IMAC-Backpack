#include <iostream>
#include <iomanip>
#include <Eigen/Dense>
#include <ctime>
#include <cassert>
#include <cstdlib>


double evalPolynomial(const Eigen::VectorXd &poly, const double x){
  double evalRes = poly(poly.size()-1);
  for (int i = poly.size()-2; i >=0; --i) {
    evalRes = evalRes * x + poly[i];
  }
  return evalRes;
}

Eigen::VectorXd polynomialFromRoots(const Eigen::VectorXd &roots){
  Eigen::VectorXd polyRes = Eigen::VectorXd::Ones(roots.size()+1);
  polyRes(0)=-roots(0);

  for (int i = 1; i < roots.size(); i++) {
    for(int j=i; j>0; --j){
      polyRes(j)=polyRes(j-1)-roots(i)*polyRes(j);
    }
    polyRes(0)*=-roots(i);
  }
  return polyRes;
}

Eigen::VectorXd findRoots(const Eigen::VectorXd &p, const uint nbIter){
  //build the companion matrix

  Eigen::VectorXd unit_p = p/(-p(p.size()-1));
  Eigen::MatrixXd C = Eigen::MatrixXd::Zero(p.size()-1, p.size()-1);

  C.bottomLeftCorner(C.rows()-1, C.cols()-1).setIdentity();
  C.rightCols(1)= unit_p.head(unit_p.size()-1);

  for(int i=0; i< nbIter; ++i){
    Eigen::HouseholderQR<Eigen::MatrixXd>qr(C);
    Eigen::MatrixXd Q = qr.householderQ();
    Eigen::MatrixXd R = qr.matrixQR().triangularView<Eigen::Upper>();
    C=R*Q;
  }

  return C.diagonal();
}


int main(int argc, char const *argv[]) {
  Eigen::VectorXd vecPoly(3);
  Eigen::VectorXd vecRoots(3);
  Eigen::VectorXd vecPolyMatrix(3);

  for (size_t i = 0; i < 3; i++) {
    vecPoly[i]=i+1;
  }
  vecRoots(0)=1;
  vecRoots(1)=2;
  vecRoots(2)=3;

  vecPolyMatrix(0)=-1;
  vecPolyMatrix(1)=2;
  vecPolyMatrix(2)=3;

  //Test
  // for (size_t i = 0; i < 3; i++) {
  //     std::cout << evalPolynomial(vecPoly,i) << '\n';
  // }
  // std::cout << evalPolynomial(vecPoly,-2) << '\n';

  Eigen::VectorXd vecResRoots=polynomialFromRoots(vecRoots);

  std::cout << "Polynomes Racines" << '\n';
  for (size_t i = 0; i < vecResRoots.size(); i++) {
    std::cout << vecResRoots(i) << '\n';
  }

  std::cout << "Test de vérification" << '\n';
  std::cout << evalPolynomial(vecResRoots,vecRoots(0)) << '\n';
  std::cout << evalPolynomial(vecResRoots,vecRoots(1)) << '\n';
  // std::cout << evalPolynomial(vecResRoots,3) << '\n';
  std::cout << evalPolynomial(vecResRoots,42) << '\n';

  Eigen::VectorXd vecRootsPoly=findRoots(vecPolyMatrix, 4);

  std::cout << vecRootsPoly << '\n';


  return 0;
}
