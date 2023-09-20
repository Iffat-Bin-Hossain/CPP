#include<iostream>
using namespace std;
void XTest()
{
    cout<<"Inside XTest Function"<<endl;
    try
    {
        cout<<"Inside Try Block of XTest Function"<<endl;
        throw "Throwing String";
    }
    catch(const char * S)
    {
        cout<<S<<endl;
        throw S;
    }

}


int main()
{
    cout<<"Inside Main Function"<<endl;
    try
    {
        cout<<"Inside Try Block of Main Function"<<endl;
        XTest();
    }
    catch(const char *S)
    {
        cout<<S<<endl;
    }
    return 0;
}
