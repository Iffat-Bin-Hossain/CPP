#include<iostream>
using std::cout;
using std::endl;
void Test()
{
    cout<<"Inside test function"<<endl;//As std namespace is not added,cout can not be executed
}
//using std::cout;
//using std::endl;
int main()
{
 //using namespace std;
 cout<<"Inside main function" <<endl;
 Test();
}
