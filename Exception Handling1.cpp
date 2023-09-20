#include<iostream>
using namespace std;
void Xtest(int i)
{
    cout<<"Inside the Xtest function i="<<i<<endl;
    if(i)throw i;
    //else throw "Value is Zero....";
}
int main()
{
    cout<<"Start....."<<endl;
    try
    {
        cout<<"Inside Try Block....."<<endl;
        Xtest(0);
        Xtest(2);
        Xtest(1);
        throw 23;
        throw 10.56;

        cout<<"This won't be executed"<<endl;

    }
    catch(char* s)
    {
        cout<<"One string caught....."<<endl;
        cout<<"Caught String:"<<s<<endl;

    }
    catch(int i)
    {
        cout<<"One value caught....."<<endl;
        cout<<"Caught Value:"<<i<<endl;

    }
}
