#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
class Product
{
public:
    int weight,price;
    Product()
    {
        weight=0;
        price=0;
    }
    Product(int w,int p)
    {
        weight=w;
        price=p;
    }
};
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("KnapsackInput.txt");
    fout.open("KnapSackOutput.txt");
    if(!fin)
    {
        cout<<"Input file can not be opened"<<endl;
        exit(1);
    }
    if(!fout)
    {
        cout<<"Output file can not be opened"<<endl;
        exit(1);
    }
    int capacity,weight,price,numberOfProduct;;
    string s;
    
    getline(fin,s);
    istringstream sso2(s);
    sso2>>numberOfProduct;
    Product *prod;
    prod=new Product[numberOfProduct];
    for(int i=0; i<numberOfProduct; i++)
    {
        getline(fin,s);
        istringstream sso3(s);
        sso3>>weight>>price;
        Product p(weight,price);
        prod[i]=p;
    }
    getline(fin,s);
    istringstream sso1(s);
    sso1>>capacity;
    //Table Making
    int **Table;
    Table=new int*[numberOfProduct+1];
    for(int i=0;i<=numberOfProduct;i++){
        Table[i]=new int[capacity+1];
    }
    for(int i=0;i<numberOfProduct+1;i++){
        for(int j=0;j<capacity+1;j++){
            Table[i][j]=0;
        }
    }
    for(int i=1;i<=numberOfProduct;i++){
        for(int j=1;j<=capacity;j++){
            if(j>=prod[i-1].weight){
                Table[i][j]=max(Table[i-1][j],Table[i-1][j-prod[i-1].weight]+prod[i-1].price);
        }
        else{
           Table[i][j]=Table[i-1][j];
        }
    }
    }
    fout<<Table[numberOfProduct][capacity]<<endl;
    int result = Table[numberOfProduct][capacity];
    vector<Product> takenItem;
    int remainingWeight = capacity;
    for (int i = numberOfProduct; i > 0 && result > 0; i--) {

        if (result == Table[i - 1][remainingWeight]){
            continue;
        }
        else {
            takenItem.push_back(prod[i-1]);
            result = result - prod[i-1].price;
            remainingWeight =remainingWeight - prod[i-1].weight;
        }
    }
    for(int i=takenItem.size()-1;i>=0;i--){
        fout<<takenItem.at(i).weight<<"  ";
        }
}