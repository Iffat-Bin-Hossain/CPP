#include<iostream>
using namespace std;
void Xtest(int i)throw()
{


    if(i==0) throw "Value is Zero";
    else if(i==1) throw 1;
    else  throw 'A';

}



int main()
{
    cout<<"Start...."<<endl;
    try
    {
        Xtest(0);
        Xtest(1);
        Xtest(2);
    }
    catch(...)
    {
        cout<<"One Value Caught"<<endl;
    }


}
