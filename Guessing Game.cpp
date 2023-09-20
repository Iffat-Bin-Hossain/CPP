#include<iostream>
#include<cstdlib>
#include<conio.h>

using namespace std;

int main()
{
 int n;
 int Random_Number=rand()%10+1;
 for(int i=0; ;i++)
  {
    cout<<"Enter a number between 1 to 10: ";
    cin>>n;
    if(n!=Random_Number)
    {
        cout<<"You have lost.Try again."<<endl;
    }
    else
    {
      cout<<"Congratulation!!!You have won."<<endl;
      break;
    }
  }
}
