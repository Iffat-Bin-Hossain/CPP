#include <iostream>
using namespace std;
int main()
{
    int n, p, q;
    cin >> n;
    cin >> p;
    int P[p];
    for (int i = 0; i < p; i++)
    {
        cin >> P[i];
    }
    cin >> q;
    int Q[q];
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i];
    }
    int A[n]={0};
    for (int i = 0; i <p; i++)
    {
        if (A[P[i]-1] == 0)
        {
            A[P[i]-1] = 1;
        }
    }
    for (int i = 0; i <q; i++)
    {
        if (A[Q[i]-1] == 0)
        {
            A[Q[i]-1] = 1;
        }
    }
    int flag=-1;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            flag=0;
            break;
        }
        else{
            flag=1;
        }
    }
    if (flag == 1)
    {
        cout << "I become the guy." << endl;
    }
    else
    {
        cout << "Oh, my keyboard!" << endl;
    }
}