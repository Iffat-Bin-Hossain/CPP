#include<iostream>
using namespace std;
namespace Demo{
    int a;
}
int x;
namespace Demo{
    int b;
}
int main()
{
    using namespace Demo;
    a=20;
    x=20;
    b=20;
    cout<<a<<" "<<b<<" "<<x<<endl;
    return 0;
}
