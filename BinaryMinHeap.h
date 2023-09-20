#include<bits/stdc++.h>
using namespace std;
class Minheap
{
    int heap[1000];
    int nodeCount;
public:
    Minheap()
    {
        for(int i=0; i<1000; i++)
        {
            heap[i]=-1;
        }
        nodeCount=0;
    }
    void iheapify(int A[],int i)
    {
        int p=(i-1)/2;
        if(p>=0)
        {
            if(A[i]<A[p])
            {
                swap(A[i],A[p]);
                iheapify(A,p);

            }
        }
    }
    void rheapify(int A[],int i)
    {

        int l=(2*i)+1;
        int r=(2*i)+2;
        if(l<=nodeCount && r<=nodeCount)
        {

            if(A[l]<A[r])
            {
                swap(A[l],A[i]);
                rheapify(A,l);
            }
            else
            {
                swap(A[r],A[i]);
                rheapify(A,r);

            }
        }
    }
    void insert(int n)
    {
        heap[nodeCount]=n;
        nodeCount++;
        iheapify(heap,nodeCount-1);

    }
    void remove(int n)
    {
        int flag=0;
        int index;
        for(int i=0; i<nodeCount; i++)
        {
            if(heap[i]==n)///Linear Searching
            {
                flag=1;
                index=i;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Element not found"<<endl;
        }
        else
        {
            heap[index]=heap[nodeCount-1];
            nodeCount--;
            rheapify(heap,index);

        }

    }
    int height()
    {
        return log2(nodeCount);
    }
    void printheap()
    {
        for(int i=0; i<nodeCount; i++)
        {
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
    int findMin()
    {
        return heap[0];
    }
    int findMax()
    {
       int Max=heap[nodeCount/2];
        for(int i=nodeCount/2; i<nodeCount; i++)
        {
            if(heap[i]>Max)
            {
                Max=heap[i];
            }
        }
        return Max;
    }
    void extractMin(){
        int Min=findMin();
        remove(Min);
    }

};
// int main()
// {
//     Minheap H;
//     H.printheap();
//     H.insert(19);
//     H.insert(27);
//     H.insert(42);
//     H.insert(10);
//     H.insert(13);
//     H.insert(8);
//     H.insert(7);
//     H.insert(8);
//     H.insert(2);
//     H.insert(3);
//     H.insert(4);
//     H.insert(5);
//     H.insert(6);
//     H.insert(1);
//     H.insert(5);
//     H.insert(6);
//     H.insert(7);
//     H.insert(4);
//     H.printheap();
//     H.remove(10);
//     H.printheap();
//     cout<<H.height()<<endl;
//     cout<<H.findMax()<<endl;
//     cout<<H.findMin()<<endl;
//     H.extractMin();
//     H.printheap();
//     H.remove(42);
//     H.printheap();

// }
