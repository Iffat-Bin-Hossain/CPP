#include<iostream>
#include<cstdlib>
#include<conio.h>

using namespace std;

int main()
{
  for(int i=0;i<10;i++)
  {
  int RandomNumber=rand()%5+1;
  cout<<RandomNumber<<endl;
  }
}
