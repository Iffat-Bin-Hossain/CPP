#include<iostream>
using namespace std;
int main(){
int *ptr1,*ptr2;
int p=20;
ptr1=&p;
cout<<&p<<" "<<ptr1<<" "<<p<<endl;
ptr1=0;
cout<<&p<<" "<<ptr1<<" "<<p<<endl;
ptr2=ptr1;
cout<<ptr1<<" "<<ptr2;
}
