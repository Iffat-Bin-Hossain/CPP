#include<iostream>
using namespace std;
class Base{
    protected:
int a;
public:
    void setA(int a){
    this->a=a;
    }
    int getA(){
    return a;
    }

};
class Derived:public Base{
int b;
public :
    setab(int x,int y){
  a=x;
    b=y;
    }
    void getab(){
    cout<<a<<" "<<b<<endl;

    }
};
int main(){

Derived d1;
d1.setA(9);
cout<<d1.getA()<<endl;
d1.setab(2,4);
d1.getab();

}
