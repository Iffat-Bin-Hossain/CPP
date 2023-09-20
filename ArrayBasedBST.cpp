#include<iostream>
using namespace std;
class BST
{
    int *A;
    int totalNode;
public:
    BST()
    {
        A=new int[3];
        totalNode=0;
    }
    BST(const BST & bst)
    {
        this->totalNode=bst.totalNode;
        this->A=new int[totalNode+1];
        for(int i=0; i<totalNode; i++)
        {
            this->A[i]=bst.A[i];
        }
    }


};
