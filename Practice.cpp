#include<iostream>
using namespace std;
class Matrix
{
    int **M;
    int Row,Column;
public:
//Constructor
    Matrix(int r,int c)
    {
        Row=r;
        Column=c;
        M=(int **)malloc(r*sizeof(int *));
        //if(M!=NULL)  cout<<"Memory for "<<r<<" row is allocated"<<endl;
        for(int i=0; i<r; i++)
        {
            M[i]=(int *)malloc(c*sizeof(int));
            //if(M[i]!=NULL)  cout<<"Memory for "<<i<<"th column is allocated"<<endl;
        }
    }
//Destructor
    ~Matrix()
    {
        for(int i=0; i<Row; i++)
        {
            free(M[i]);
        }
        free(M);
    }
    void print()
    {
        for(int i=0; i<Row; i++)
        {
            for(int j=0; j<Column; j++)
            {
                cout<<M[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void set(int r,int c,int v)
    {
        M[r][c]=v;
    }
    int get(int r, int c)
    {
        return M[r][c];
    }
    void add(int num)
    {
        for(int i=0; i<Row; i++)
        {
            for(int j=0; j<Column; j++)
            {
                M[i][j]+=num;
            }

        }
    }
    int add()
    {
        int Sum=0;
        for(int i=0; i<Row; i++)
        {
            for(int j=0; j<Column; j++)
            {
                Sum+=M[i][j];
            }
        }
        return Sum;
    }
    Matrix *add(int r,int c,Matrix &m)
    {
        Matrix* R = new Matrix(r, c);

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                R->M[i][j] = M[i][j]+ m.M[i][j];
            }
        }
        return R;

    }

};

int main()
{

    cout<<"Hello World"<<endl;
    Matrix m1(3,3);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            m1.set(i,j,i+j);
        }
    }
    m1.print();
    cout<<m1.get(0,0)<<'\n';
    m1.set(0,0,100);
    cout<<m1.get(0,0)<<'\n';
    m1.add(100);
    m1.print();
    cout<<m1.add()<<'\n';

    Matrix m2(3,3);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            m2.set(i,j,i+j);
        }
    }
    cout<<"Adding two Matrix:"<<endl;
    Matrix *Result= m2.add(3,3,m1);
    Result->print();
    return 0;
}

