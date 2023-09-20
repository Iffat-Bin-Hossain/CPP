#include <iostream>
using namespace std;
class samp {
        int i;
public:
       samp(int n);
      ~samp();
       void seti(int n) { i = n;}
       int geti() { return i; }
};
samp::samp(int n){
      i= n;
      cout << "Constructing"<<endl;
}
samp::~samp(){
      cout << "Destructing"<<endl;
}
void sqr_it(samp &o) {
     o.seti(o.geti() * o.geti());
     cout << "Copy: value of a:"<< o.geti() <<endl;
}



int main() {
     samp a(10);
     //cout<<a.geti()<<endl;
     sqr_it(a);
     cout << "Main: value of a:" << a.geti() <<endl;
     //cout<<a.geti()<<endl;

     return 0;
}
