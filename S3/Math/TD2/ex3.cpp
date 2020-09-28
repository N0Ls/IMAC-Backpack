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

Eigen::MatrixXd matProduct(const Eigen::MatrixXd &m1,const Eigen::MatrixXd &m2){
  //assert(m1.cols()==m2.rows() && "Dimension problem");
  if(m1.cols() != m2.rows()){
    std::cout << "Pb size" << '\n';
  }

  Eigen::MatrixXd m3(m1.rows(),m2.cols());

  //complexité O(n³)
  for (unsigned int i = 0; i < m1.rows(); i++) { //O(n)
    for (unsigned int j = 0; j < m2.cols(); j++) {//O(n²)
      //m3(i,j)= dotProduct(m1.row(i),m2.col(j));//O(n³)

      //autre méthode
      m3(i,j)=0.0;
      for (unsigned int k = 0; k < m1.cols(); k++) {
        m3(i,j) += m1(i,k)*m2(k,j);
      }
    }
  }
  return m3;
}

double errorMatrix(const Eigen::MatrixXd &m1,const Eigen::MatrixXd &m2){
  return (m1-m2).norm()/(m1.cols()*m1.cols());
}

int main()
{
  srand(time(0));

  //Const
  const unsigned int dimension=3;

  //Init and filling vectors

  Eigen::MatrixXd m1 = Eigen::MatrixXd::Random(dimension,dimension);
  Eigen::MatrixXd m2 = Eigen::MatrixXd::Random(dimension,dimension);

  //Homemade dot product call
  clock_t begin = clock();
  Eigen::MatrixXd resMatProd = matProduct(m1,m2) ;
  clock_t end = clock();
  double tempsCalc = double(end - begin) / CLOCKS_PER_SEC;

  std::cout << std::setprecision(20)<<"Homemade mat product : " << tempsCalc << std::endl;

  //Eigen dot product call
  begin = clock();
  Eigen::MatrixXd resMatProdEigen = m1*m2;
  end = clock();
  tempsCalc = double(end - begin) / CLOCKS_PER_SEC;

  std::cout << std::setprecision(20)<<"Eigen mat product    : " << tempsCalc << std::endl;

  std::cout <<  std::setprecision(20) <<"Error Matrix " << errorMatrix(resMatProd,resMatProdEigen)<< '\n';

  return 0;
}
