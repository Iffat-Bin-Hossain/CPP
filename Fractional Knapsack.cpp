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
    int currentWeight=0;
    for(int i=0; i<totalProduct; i++)
    {
        if(currentWeight<capacity)
        {
            if(currentWeight+prod[i].weight>capacity)
            {
               int x=capacity-currentWeight;
               currentWeight=capacity;
                float fraction=float(x)/prod[i].weight;
                cout<<fraction<<" of product "<<prod[i].weight<<" "<<prod[i].price<<" is taken"<<endl;
                prod[i].weight=fraction*prod[i].weight;
                prod[i].price=fraction*prod[i].price;
                maxProfit.push_back(prod[i]);

                break;
            }
            currentWeight=currentWeight+prod[i].weight;
            maxProfit.push_back(prod[i]);
        }

    }
    return maxProfit;
}
int main(){
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
    vector<Product> maxProfitProductList=maxProfitWithGreedyApproach(prod,numberOfProduct,capacity);
    int optimumProfit=0;
    int l=maxProfitProductList.size();
    cout<<l<<endl;
    for(int i=0; i<l; i++)
    {
        optimumProfit+=maxProfitProductList[i].price;
        cout<<maxProfitProductList.at(i).weight<<" "<<maxProfitProductList.at(i).price<<endl;
    }
    cout<<"Maximum Profit got through Greedy method :"<<optimumProfit;
}
