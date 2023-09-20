#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class strtype {
char *p;
int len;
public:
strtype(char *ptr); // constructor
~strtype(); // destructor
void show();
};
strtype::~strtype(){
cout << "freeing p..."<<endl;
free(p);
}
void strtype::show(){
cout << p <<endl<< "length: " << len;
cout << endl;
}


strtype::strtype(char *ptr){
len = strlen(ptr);
p = (char *) malloc(len+1);
if (!p) {
cout << "Allocation error\n";
exit(1);
}
strcpy(p, ptr);
}

int main(){
strtype s1("This is a test."), s2("I like C++.");
s1.show();
s2.show();
s2=s1;
//s1.show();
s2.show();
return 0;


}
