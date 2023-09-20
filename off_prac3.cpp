#include <iostream>
#include <cstring>
using namespace std;
class Vector
{
  char *name;
  int x, y, z;

public:
  Vector() {}
  Vector(char *n)
  {
    int l = strlen(n);
    name = new char[l + 1];
    strcpy(name, n);
    x = 0;
    y = 0;
    z = 0;
  }
  Vector(char *n, int a, int b, int c)
  {
    int l = strlen(n);
    name = new char[l + 1];
    strcpy(name, n);
    x = a;
    y = b;
    z = c;
  }
  int setX(int a) { x = a; }
  int setY(int b) { y = b; }
  int setZ(int c) { z = c; }
  void setName(char *n)
  {
    int l = strlen(n);
    name = new char[l + 1];
    strcpy(name, n);
  }

  int getX() { return x; }
  int getY() { return y; }
  int getZ() { return z; }
  char *getName() { return name; }

  void print()
  {
   if(y>0 && z>0)  cout << name << ": " << x << "x+" << y << "y+" << z << 'z' << endl;
   if(y<0 && z<0)  cout << name << ": " << x << "x" << y << "y" << z << 'z' << endl;
   if(y>0 && z<0)  cout << name << ": " << x << "x+" << y << "y" << z << 'z' << endl;
   if(y<0 && z>0)  cout << name << ": " << x << "x" << y << "y+" << z << 'z' << endl;
  }

  Vector operator^(Vector ob)
  {
    Vector temp;

    temp.setX((y * ob.getZ()) - (z * ob.getY()));
    temp.setY(-((x * ob.getZ()) - (z * ob.getX())));
    temp.setZ((x * ob.getY()) - (y * ob.getX()));

    return temp;
  }

  bool operator==(Vector obj)
  {
    return x == obj.getX() && y == obj.getY() && z == obj.getZ();
  }

  Vector operator*(int p)
  {
    x=x*p;
    y=y*p;
    z=z*p;

    return *this;

  }

  friend Vector operator*(int p, Vector obj);

  Vector operator*(Vector p)
  {
    Vector ob;
    ob.setX(x*p.getX());
    ob.setY(y*p.getY());
    ob.setZ(z*p.getZ());
    return ob;
  }

  ~Vector()
  {
    delete [] name;
  }
};

Vector operator*(int p, Vector obj)
{

  obj.setX(p * obj.getX());
  obj.setY(p * obj.getY());
  obj.setZ(p * obj.getZ());
  return obj;
}
int main()
{
  Vector v1("v1", 1, 2, 3), v2("v2", 4, 5, -6), v3("Result1"), v4("Result2", -27, 18, -3);

  v1.print();   /// Print the components of vector v1
  v2.print();   /// Print the components of vector v2
  v3 = v1 ^ v2; /// Calculate the cross product of vector v1 and
  // //vector v2 (Consider ^ as cross product for this assignment

  v3.setName("Result1");
  v3.print(); /// Print the modified components of vector v3
  // //(Name: Result1)

  //  ///Check for equality; if two vectors contain
  // //equal component values (x, y, z), then they are equal.
  if (v3 == v4)
    cout << "Vectors are equal" << endl;
  else
    cout << "Vectors are not equal" << endl;
  v1= v1*2; ///Multiply each component of vector v1 with the given value
  v1.setName("v1");
  v1.print(); ///Print the modified components of vector v1

  v2 = 2 * v2; /// Multiply each component of vector v2 with the
  // // //given value
  v2.setName("v2");
  v2.print(); /// Print the modified components of vector v2
  v3=v1*v2; ///Multiply each component of vector v1 with the
  // // corresponding component of vector v2.
  v3.setName("Result1");
  v3.print(); ///Print the modified components of vector v3
  // // (Name: Result1)
  //   ///Check for equality; if two vectors contain
  // // equal component values (x, y, z), then they are equal.
  if(v3==v4) cout<<"Vectors are equal"<<endl;
  else cout<<"Vectors are not equal"<<endl;
  return 0;
}
