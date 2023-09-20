#include<iostream>
using namespace std;
int main()
{
    int i,j,t,a,b,c,A[4];
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>a>>b>>c;
        if(a>b && a>c){
                if(b>c){
                    cout<<b<<endl;
                }
                else{
                    cout<<c<<endl;
                }

        }
        if(b>a && b>c){
                if(a>c){
                    cout<<a<<endl;
                }
                else{
                    cout<<c<<endl;
                }

        }
        if(c>a && c>b){
                if(a>b){
                    cout<<a<<endl;
                }
                else{
                    cout<<b<<endl;
                }

        }




    }

}
