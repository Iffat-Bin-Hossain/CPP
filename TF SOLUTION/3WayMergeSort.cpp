#include <bits/stdc++.h>
using namespace std;
void Merge(int left, int firstTrisect, int secondTrisect, int right, int A[])
{
    int len1 = firstTrisect - left + 1;
    int len2 = secondTrisect - firstTrisect;
    int len3 = right - secondTrisect;
    int leftArr[len1], midArr[len2], rightArr[len3];
    for (int i = 0; i < len1; i++)
    {
        leftArr[i] = A[left + i];
    }
    for (int i = 0; i < len2; i++)
    {
        midArr[i] = A[firstTrisect + 1 + i];
    }
    for (int i = 0; i < len3; i++)
    {
        rightArr[i] = A[secondTrisect + 1 + i];
    }
    int i = 0, j = 0, k = 0, l = left;
    while (i < len1 && j < len2 && k < len3)
    {
        if (leftArr[i] <= midArr[j])
        {
            if (leftArr[i] <= rightArr[k])
            {
                A[l++] = leftArr[i++];
            }
            else
            {
                A[l++] = rightArr[k++];
            }
        }
        else
        {
            if (midArr[j] <= rightArr[k])
            {
                A[l++] = midArr[j++];
            }
            else
            {
                A[l++] = rightArr[k++];
            }
        }
    }
    while (i < len1 && j < len2)
    {
        if (leftArr[i] <= midArr[j])
        {
            A[l++]=leftArr[i++];
        }
        else
        {
            A[l++]=midArr[j++];
        }
    }
    while (k < len3 && j < len2)
    {
        if (midArr[j] <= rightArr[k])
        {
            A[l++]=midArr[j++];
        }
        else
        {
            A[l++]=rightArr[k++];
        }
    }
    while (i < len1 && k < len3)
    {
        if (leftArr[i] <= rightArr[k])
        {
            A[l++]=leftArr[i++];
        }
        else
        {
            A[l++]=rightArr[k++];
        }
    }
    while(i<len1)
    {
        A[l++]=leftArr[i++];
    }
    while(j<len2)
    {
        A[l++]=midArr[j++];
    }
    while(k<len3)
    {
        A[l++]=rightArr[k++];
    }
}
void MergeSort(int left, int right, int A[])
{
    if (right == left)
    {
        return;
    }
    if(right == left+1)
    {
     if(A[left]>A[right])
     {
      swap(A[left],A[right]);
     }
     return;
    }
    int firstTrisect = ((2 * left) + right) / 3;
    int secondTrisect = (left + (2 * right)) / 3;
    MergeSort(left, firstTrisect, A);
    MergeSort(firstTrisect + 1, secondTrisect, A);
    MergeSort(secondTrisect + 1, right, A);
    Merge(left, firstTrisect, secondTrisect, right, A);
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
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    MergeSort(0, n - 1, A);
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
