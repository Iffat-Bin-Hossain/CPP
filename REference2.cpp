#include <iostream>
using namespace std;
class samp {
        int i;
public:
      samp(int n) { i = n; }
      ~samp()
      {
          cout<<"Destructing"<<endl;
      }
      void seti (int n) { i = n; }
      int geti() { return i; }
};

void sqr_it(samp o) {
     o.seti(o.geti() *o.geti() );
     cout << "copy: value of i: " << o.geti() << endl;
}
int main() {
     samp a(10);
        cout<<a.geti()<<endl;
     sqr_it(a);
     cout << "main: value of i: "<< a.geti() << endl;

     return 0;
}

