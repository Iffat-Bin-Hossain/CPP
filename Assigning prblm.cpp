#include<iostream>
#include<cstring>
using namespace std;
class Dyna{
int *p;
public:
    Dyna(int i){
    cout<<"In Constructor"<<endl;
    p=(int *)malloc(sizeof(int));
    *p=i;
    }
    ~Dyna(){
    cout<<"In Destructor"<<endl;
    free(p);
    }
    int get(){cout<<"In get"<<endl;
    return p;}


};
int neg(Dyna &ob){
        cout<<"In neg"<<endl;
    return -ob.get();
    }

int main(){
Dyna d(-10);
cout<<d.get()<<endl;
cout<<neg(d)<<endl;
cout<<d.get()<<endl;


}
