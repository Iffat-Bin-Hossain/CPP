#include<iostream>
using namespace std;
void f(const double &i)
{
    double &d=const_cast<double &>(i);
    d=100;
}
int main(){
double x=98.76;
cout<<"Before calling f() x:"<<x<<endl;
f(x);
cout<<"After calling f() x:"<<x<<endl;
}
