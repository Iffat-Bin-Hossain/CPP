#include <bits/stdc++.h>
using namespace std;
void heapify(int A[], int i)
{
    int p = (i - 1) / 2;
    if (p < 0)
    {
        return;
    }
    if (A[i] > A[p])
    {
        swap(A[i], A[p]);
    }
    heapify(A, p);

}
void heapSort(int A[], int n)
{
    for (int i = n / 2; i < n; i++)
    {
        heapify(A, i);
    }
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    heapSort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
}
