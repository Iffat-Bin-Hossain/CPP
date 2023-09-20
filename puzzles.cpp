#include <bits/stdc++.h>
using namespace std;
void Merge(int Arr[], int left, int mid, int right)
{
    int llen = mid - left + 1;
    int rlen = right - mid;
    int leftArr[llen];
    int rightArr[rlen];
    for (int i = 0; i < llen; i++)
        leftArr[i] = Arr[left + i];
    for (int j = 0; j < rlen; j++)
        rightArr[j] = Arr[mid + 1 + j];
    int i, j;
    int k = left;
    i = 0;
    j = 0;
    while (i < llen && j < rlen)
    {
        if (leftArr[i] <= rightArr[j])
        {
            Arr[k] = leftArr[i];
            k++;
            i++;
        }
        else
        {
            Arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    while (i < llen)
    {
        Arr[k] = leftArr[i];
        k++;
        i++;
    }
    while (j < rlen)
    {
        Arr[k] = rightArr[j];
        k++;
        j++;
    }
}
void MergeSort(int Arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(Arr, left, mid);
    MergeSort(Arr, mid + 1, right);
    Merge(Arr, left, mid, right);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int puzzle[m];
    for (int i = 0; i < m; i++)
    {
        cin >> puzzle[i];
    }
    MergeSort(puzzle, 0, m - 1);
    vector<int> result;
    for(int i=0;i<m-n+1;i++){
        result.push_back(abs(puzzle[i]-puzzle[i+n-1]));
    }
   int Min=result.at(0);
   for(int i=0;i<result.size();i++){
      Min=min(Min,result.at(i));
    }
    cout<<Min<<endl;

}