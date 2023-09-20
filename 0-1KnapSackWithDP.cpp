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
void PrintTable(int** table,int c,int p){
    for(int i=0;i<p+1;i++){
        for(int j=0;j<c+1;j++){
            cout<<table[i][j]<<"   ";
        }
        cout<<endl;
    }
}
vector<Product> knapSackItem;
int ZeroOneKnapSackWithDP(Product prod[],int item,int capacity,int ** Table){
    if(item==0 || capacity==0){
        Table[item][capacity]=0;
        return 0;
    }
    if(Table[item][capacity]!=-1){
        return Table[item][capacity];
    }
    if(prod[item-1].weight>capacity){
        Table[item][capacity]=ZeroOneKnapSackWithDP(prod,item-1,capacity,Table);
        return Table[item][capacity];
    }
    else{
        int notTaken=ZeroOneKnapSackWithDP(prod,item-1,capacity,Table);
        int taken=prod[item-1].price+ZeroOneKnapSackWithDP(prod,item-1,capacity-prod[item-1].weight,Table);
        Table[item][capacity]= max(taken,notTaken);
        return Table[item][capacity];
    }

}
int maxProfitWithDynamicProgramming(Product prod[],int totalProduct,int capacity){
    int **Table;
    Table=new int*[totalProduct+1];
    for(int i=0;i<=totalProduct;i++){
        Table[i]=new int[capacity+1];
    }
    for(int i=0;i<totalProduct+1;i++){
        for(int j=0;j<capacity+1;j++){
    Table[i][j]=-1;
        }
    }
    int profit=ZeroOneKnapSackWithDP(prod,totalProduct,capacity,Table);
    cout<<"Table in Recursive approach:"<<endl;
    PrintTable(Table,capacity,totalProduct);
    return profit;
}
int main()
{
    ifstream fin;
    fin.open("Knapsack.txt");
    if(!fin)
    {
        cout<<"Input file can not be opened"<<endl;
        exit(1);
    }
    int capacity,weight,price,numberOfProduct;;
    string s;
    getline(fin,s);
    istringstream sso1(s);
    sso1>>capacity;
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
    int maxProfit=maxProfitWithDynamicProgramming(prod,numberOfProduct,capacity);
    cout<<"Maximum Profit got through Dynamic Programming :"<<maxProfit<<endl;
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
    cout<<"Table in Pure Tabular Approach:"<<endl;
    PrintTable(Table,capacity,numberOfProduct);
    cout<<"Items taken in the Knapsack:"<<endl;
    int result = Table[numberOfProduct][capacity];

    int remainingWeight = capacity;
    for (int i = numberOfProduct; i > 0 && result > 0; i--) {

        if (result == Table[i - 1][remainingWeight])
            continue;
        else {
            cout<<"("<<prod[i-1].weight <<","<<prod[i-1].price<<")"<<endl;
            result = result - prod[i-1].price;
           remainingWeight =remainingWeight - prod[i-1].weight;
        }
    }
}
