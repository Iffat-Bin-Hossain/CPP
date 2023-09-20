#include<iostream>
using namespace std;
void Xtest(int i)
{
    cout<<"Inside the Xtest function i="<<i<<endl;
    try
    {
        cout<<"Inside Try block of Xtest function"<<endl;
        if(i)throw i;
        else throw "Value is Zero";
    }
    catch(int i)
    {
        cout<<"One value caught....."<<endl;
        cout<<"Caught Value:"<<i<<endl;

    }
    catch(const char* s)
    {
        cout<<"One string caught....."<<endl;
        cout<<"Caught String:"<<s<<endl;

    }
}
int main()
{
    cout<<"Start....."<<endl;
    Xtest(0);
    Xtest(1);
    Xtest(2);

}
