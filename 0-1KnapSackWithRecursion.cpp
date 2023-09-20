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


//With Recursion(T(n)=O(2^n))
int RecursiveZeroOneKnapSack(Product prod[],int totalProduct,int capacity){
if(totalProduct==0 || capacity==0){
    return 0;
}
if(prod[totalProduct-1].weight>capacity){
    return RecursiveZeroOneKnapSack(prod,totalProduct-1,capacity);
}
else{
    return max(RecursiveZeroOneKnapSack(prod,totalProduct-1,capacity),prod[totalProduct-1].price+RecursiveZeroOneKnapSack(prod,totalProduct-1,capacity-prod[totalProduct-1].weight));
}
}


int maxProfitWithRecursion(Product prod[],int totalProduct,int capacity){
int Profit=RecursiveZeroOneKnapSack(prod,totalProduct,capacity);
return Profit;
}

int ZeroOneKnapSackWithDP(Product prod[],int item,int capacity,int ** Table){
    if(item==0 || capacity==0){
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
        Table[item][capacity]= max(ZeroOneKnapSackWithDP(prod,item-1,capacity,Table),prod[item-1].price+ZeroOneKnapSackWithDP(prod,item-1,capacity-prod[item-1].weight,Table));
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
return profit;
}

vector<Product> maxProfitWithGreedyApproach(Product prod[],int totalProduct,int capacity)
{
    vector<Product> maxProfit;
    for(int i=0; i<totalProduct; i++)
    {
        for(int j=i; j<totalProduct; j++)
        {
            float pricePerWeight1=float(prod[i].price)/prod[i].weight;
            float pricePerWeight2=float(prod[j].price)/prod[j].weight;
            if(pricePerWeight1<=pricePerWeight2)
            {
                if(pricePerWeight1==pricePerWeight2)
                {
                    if(prod[i].weight<prod[j].weight)
                    {
                        swap(prod[i],prod[j]);
                    }
                }
                else
                {
                    swap(prod[i],prod[j]);
                }
            }
        }
    }
    int len=0;
    int currentWeight=0;
    for(int i=0; i<totalProduct; i++)
    {
        if(currentWeight<capacity)
        {
            if(currentWeight+prod[i].weight>capacity)
            {
                continue;
            }

            len++;
            currentWeight=currentWeight+prod[i].weight;
            maxProfit.push_back(prod[i]);
        }

    }
    return maxProfit;
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
   int maxProfit=maxProfitWithRecursion(prod,numberOfProduct,capacity);
   cout<<"MaxProfit got through Recursive Approach:"<<maxProfit<<endl;
   maxProfit=0;
    vector<Product> maxProfitProductList=maxProfitWithGreedyApproach(prod,numberOfProduct,capacity);
    int l=maxProfitProductList.size();
   for(int i=0; i<l; i++)
    {
        maxProfit+=maxProfitProductList[i].price;
    }
    cout<<"Maximum Profit got through Greedy method :"<<maxProfit<<endl;
    maxProfit=maxProfitWithDynamicProgramming(prod,numberOfProduct,capacity);
    cout<<"Maximum Profit got through Dynamic Programming :"<<maxProfit<<endl;
}
