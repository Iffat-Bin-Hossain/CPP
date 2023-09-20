#include<iostream>
#include<conio.h>
using namespace std;
namespace X
{
float x=55.34;
}
int x=20;

int main()
{
    int x=10;
    ::x=60;
    cout<<x<<endl;
    cout<<::x<<endl;
    cout<<X::x<<endl;


}
