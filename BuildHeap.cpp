#include <bits/stdc++.h>
using namespace std;
class Builder
{
public:
    void heapify(int *Array, int i, int Size)
    {
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;

        if (l < Size && Array[l] < Array[i])
        {
            swap(Array[l], Array[i]);
            heapify(Array, l, Size);
        }
        if (r < Size && Array[i] > Array[r])
        {
            swap(Array[r], Array[i]);
            heapify(Array, r, Size);
        }
    }
    void buildHeap(int *Array, int Size)
    {

        for (int i = (Size / 2)-1; i >= 0; i--)
        {
            heapify(Array, i, Size);
        }
    }
    void printHeap(int *Array, int Size)
    {
        for (int i = 0; i < Size; i++)
        {
            cout << Array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Builder builder;
    int Array[100] = {0};
    for (int i = 0; i < 10; i++)
    {
        cin >> Array[i];
    }
    builder.printHeap(Array, 10);
    builder.buildHeap(Array, 10);
    builder.printHeap(Array, 10);
}