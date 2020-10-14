#include <iostream>

template <typename T>
class Point3D{
  private :
    T _x;
    T _y;
    T _z;
  public :
    Point3D():_x(0),_y(0),_z(0)
    {}

    Point3D(const T &x,const T &y,const T &z):_x(x),_y(y),_z(z)
    {}

    Point3D(const Point3D &point):_x(point._x),_y(point._y),_z(point._z)
    {}

    ~Point3D()
    {
    }

    const T &x() const {return _x;}
    T &x(){return _x;}

    const T &y() const {return _y;}
    T &y(){return _y;}

    const T &z() const {return _z;}
    T &z(){return _z;}

    Point3D operator=(const Point3D operand){
      _x=operand._x;
      _y=operand._y;
      _z=operand._z;

      return *this;
    }

    // Point3D operator+(const T &s){
    //   _x=_x+s;
    //   _y=_y+s;
    //   _z=_z+s;
    //
    //   return *this;
    // }

    Point3D operator+(const T &s){
      return Point3D(_x+s,_y+s, _z+s);
    }


    Point3D operator+(const Point3D &pt){
      return Point3D(_x+pt._x,_y+pt._y,_z+pt._z);
    }

    //Constructeur de conversion
    template<typename U>
    Point3D<T>(const Point3D<U> &pt):Point3D<T>(static_cast<T>(pt.x()),static_cast<T>(pt.y()),static_cast<T>(pt.z()))
    {}

    friend std::ostream& operator<< (std::ostream& stream, const Point3D& pt){
      stream << "(" << pt._x << ", " << pt._y << ", " << pt._z << ")";
      return stream;
    }

    void print(){
      std::cout << _x << '\n';
      std::cout << _y << '\n';
      std::cout << _z << '\n';
    }


};
