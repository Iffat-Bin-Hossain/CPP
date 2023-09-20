#include <iostream>
#include <cstdlib>
using namespace std;
class dyna {
        int *p;
public:
       dyna(int i);
      ~dyna() {free(p); cout << "Freeing"<<endl;}
       int get() { return *p;}
};
dyna:: dyna(int i){
       p = (int *) malloc(sizeof(int));
       if (!p) {
            cout << "Allocation problem";
            exit(1);
       }
      *p = i;
}
int neg (dyna &ob) {
      return -ob.get();
}
int main()
{
     dyna o(-10);

     cout << o.get() << endl;
     cout << neg(o) << endl;
     cout<<o.get()<<endl;

     return 0;
}
