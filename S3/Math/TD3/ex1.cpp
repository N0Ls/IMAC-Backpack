//Ex1 Question 1
//n³ = 2 * n^2,81
//n^(3-2.81) = 2
//0.19ln(n) = ln(2)
//ln(n)=ln(2)/0.19
//n=exp(ln(2)/0.19) = 38,.....

//Donc au rang 39


//Question 2

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

Eigen::MatrixXd Strassen(const Eigen::MatrixXd &m1, const Eigen::MatrixXd &m2){
  if (m1.cols()<100 || m1.rows()<100 || m2.cols()<100 || m2.rows()<100) {
    return m1*m2;
  }

  const int rows = m1.rows()/2;
  const int cols = m1.cols()/2;

  Eigen::MatrixXd a = m1.topLeftCorner(rows,cols);
  Eigen::MatrixXd b = m1.topRightCorner(rows,cols);
  Eigen::MatrixXd c = m1.bottomLeftCorner(rows,cols);
  Eigen::MatrixXd d = m1.bottomRightCorner(rows,cols);
  Eigen::MatrixXd e = m2.topLeftCorner(rows,cols);
  Eigen::MatrixXd f = m2.topRightCorner(rows,cols);
  Eigen::MatrixXd g = m2.bottomLeftCorner(rows,cols);
  Eigen::MatrixXd h = m2.bottomRightCorner(rows,cols);

  Eigen::MatrixXd p1 = Strassen(a,(f-h));
  Eigen::MatrixXd p2 = Strassen((a+b),h);
  Eigen::MatrixXd p3 = Strassen((c+d),e);
  Eigen::MatrixXd p4 = Strassen(d,(g-e));
  Eigen::MatrixXd p5 = Strassen((a+d),(e+h));
  Eigen::MatrixXd p6 = Strassen((b-d),(g+h));
  Eigen::MatrixXd p7 = Strassen((a-c),(e+f));

  Eigen::MatrixXd matRes;

  //rstu
  matRes.topLeftCorner(rows,cols) = p5 +p4-p2+p6;
  matRes.topRightCorner(rows,cols) = p1+p2;
  matRes.bottomLeftCorner(rows,cols) = p3 + p4;
  matRes.bottomRightCorner(rows,cols) = p1 + p5 - p3 - p7;

  return matRes;
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

  //Homemade mat product call
  clock_t begin = clock();
  Eigen::MatrixXd resMatProd = matProduct(m1,m2) ;
  clock_t end = clock();
  double tempsCalc = double(end - begin) / CLOCKS_PER_SEC;

  std::cout << std::setprecision(20)<<"Homemade mat product : " << tempsCalc << std::endl;

  //Eigen mat product call
  begin = clock();
  Eigen::MatrixXd resMatProdEigen = m1*m2;
  end = clock();
  tempsCalc = double(end - begin) / CLOCKS_PER_SEC;

  std::cout << std::setprecision(20)<<"Eigen mat product    : " << tempsCalc << std::endl;
//  std::cout <<  std::setprecision(20) <<"Error Matrix " << errorMatrix(resMatProd,resMatProdEigen)<< '\n';

  begin = clock();
  Eigen::MatrixXd resMatProdStrassen = Strassen(m1,m2);
  end = clock();
  tempsCalc = double(end - begin) / CLOCKS_PER_SEC;

  std::cout << std::setprecision(20)<<"Eigen mat product    : " << tempsCalc << std::endl;
  return 0;

}
