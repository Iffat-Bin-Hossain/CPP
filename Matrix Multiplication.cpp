#include<iostream>
using namespace std;
int main()
{
    int M1[10][10],M2[10][10],M3[10][10],r1,r2,c1,c2,i,j,k,S=0;
    cout<<"Enter the row and column of first matrix : ";
    cin>>r1>>c1;
    cout<<"Enter the row and column of second matrix : ";
    cin>>r2>>c2;
    while(c1!=r2)
    {
        cout<<"Error!!!.Matrix can not be multiplicated"<<endl;
        cout<<"Enter the row and column of first matrix : ";
        cin>>r1>>c1;
        cout<<"Enter the row and column of second matrix : ";
        cin>>r2>>c2;
    }
cout<<"First Matrix :"<<endl;
    for(i=0;i<r1;i++)
    {
      for(j=0;j<c1;j++)
      {
          printf("Enter M1[%d][%d] : ",i,j);
          cin>>M1[i][j];
      }
    }

cout<<"Second Matrix :"<<endl;
    for(i=0;i<r2;i++)
    {
      for(j=0;j<c2;j++)
      {
          printf("Enter M2[%d][%d] : ",i,j);
          cin>>M2[i][j];
      }
    }
  cout<<"First Matrix :"<<endl;
    for(i=0;i<r1;i++)
    {
      for(j=0;j<c1;j++)
      {

          cout<<M1[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<"Second Matrix :"<<endl;
    for(i=0;i<r2;i++)
    {
      for(j=0;j<c2;j++)
      {

          cout<<M2[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<"Multiplicated Matrix :"<<endl;
    for(i=0;i<r1;i++)
    {
      for(j=0;j<c2;j++)
      {
      for(k=0;k<c1;k++)
          {
              S+=M1[i][k]*M2[k][j];
          }
          M3[i][j]=S;
          S=0;

      }
    }

    for(i=0;i<r1;i++)
    {
      for(j=0;j<c2;j++)
      {
          cout<<M3[i][j]<<"  ";
      }
      cout<<endl;
    }
}
