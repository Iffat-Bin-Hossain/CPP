#include<iostream>
#include<cmath>
#include<fstream>
#include<cstring>
#include<sstream>
using namespace std;
ofstream fout;
class MinHeap
{
    int *heap,nodeCount,capacity;
public:
    MinHeap()
    {
        capacity=50;
        heap=new int[capacity];
        for(int i=0; i<capacity; i++)
        {
            heap[i]=-1;
        }
        nodeCount=0;
    }
    int FindMin()
    {
        return heap[0];
    }
    int ExtractMin()
    {
        if(nodeCount==0)
        {
            return heap[0];
        }
        int Min=heap[0];
        heap[0]=heap[nodeCount-1];
        heap[nodeCount-1]=-1;
        nodeCount--;
        DelHeapify(0);
        return Min;
    }
    void Heapify(int i)
    {
        int p=(i-1)/2;//finding parents index
        if(p>=0)
        {
            if(heap[i]<heap[p])
            {
                swap(heap[i],heap[p]);
                Heapify(p);
            }
        }
    }
    void Insert(int n)
    {
        if(nodeCount==capacity)
        {
            int *temp=heap;
            heap=new int[2*capacity];
            for(int i=0; i<nodeCount; i++)
            {
                heap[i]=temp[i];
            }
        }
        heap[nodeCount++]=n;
        Heapify(nodeCount-1);
    }
    void DelHeapify(int i)
    {
        int l=(2*i)+1;
        int r=(2*i)+2;

        if(l<nodeCount && heap[l]<heap[r])
        {
            swap(heap[l],heap[i]);
            DelHeapify(l);
        }
        else if(r<nodeCount && heap[l]>heap[r])
        {
            swap(heap[r],heap[i]);
            DelHeapify(r);
        }
        else if(l<nodeCount && r>=nodeCount){
                if(heap[l]<heap[i]){
                   swap(heap[l],heap[i]);
                }
        }

    }
    void DecreaseKey(int prevKey,int newKey)
    {
        int flag=0, index;
        for(int i=0; i<nodeCount; i++)
        {
            if(heap[i]==prevKey)///Linear Searching
            {
                flag=1;
                index=i;
                break;
            }
        }
        if(flag==0)
        {
            fout<<"Element not found"<<endl;
        }
        else
        {
            heap[index]=newKey;
            Heapify(index);
            fout<<prevKey<<" decreased to "<<newKey<<endl;
        }
    }
    void Print()
    {
        int level=log2(nodeCount);
        int index=0;
        for(int i=0; i<=level; i++)
        {
            fout<<"level "<<i<<": ";
            for(int j=0; j<pow(2,i); j++)
            {
                if(heap[index]==-1)
                {
                    fout<<endl;
                    return;
                }
                fout<<heap[index++]<<" ";
            }
            fout<<endl;
        }
    }
    ~MinHeap(){
        delete[] heap;
    }
};
int main()
{
    ifstream fin;
    fin.open("heapInput.txt");
    fout.open("heapOutput.txt");
    MinHeap h;
    if(!fin)
    {
        cout<<"File cannot be opened";
        exit(1);
    }
    if(!fout)
    {
        cout<<"File cannot be opened";
        exit(1);
    }
    while(!fin.eof())
    {
        string line,operation;
        int key,prevKey,newKey;
        getline(fin,line);
        stringstream sso(line);
        sso>>operation;
        if(operation=="INS")
        {
            sso>>key;
            h.Insert(key);
            fout<<"INSERTED "<<key<<endl;
        }
        else if(operation=="FIN")
        {
            fout<<"FindMin returned "<<h.FindMin()<<endl;
        }
        else if(operation=="DEC")
        {
            sso>>prevKey>>newKey;
            h.DecreaseKey(prevKey,newKey);

        }
        else if(operation=="PRI")
        {
            fout<<"Printing the binary heap ..."<<endl;
            fout<<"- - - - - - - - - - - - - - - - - - - -"<<endl;
            h.Print();
            fout<<"- - - - - - - - - - - - - - - - - - - -"<<endl;
        }
        else if(operation=="EXT")
        {
            fout<<"ExtractMin returned "<<h.ExtractMin()<<endl;
        }
        else
        {
            fout<<"Invalid Operation"<<endl;
        }
    }
}
