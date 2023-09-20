#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class Customer
{
public:
    int arrivalTime,departureTime;
    Customer()
    {
        arrivalTime=0;
        departureTime=0;
    }
    Customer(int a,int d)
    {
        arrivalTime=a;
        departureTime=d;
    }
};
Customer* maxCustomerWithGreedyApproach(Customer cust[],int Size)
{
    Customer *maxCustomer;
    for(int i=0; i<Size; i++)
    {
        for(int j=i; j<Size; j++)
        {
            if(cust[i].departureTime>cust[j].departureTime)
            {
                swap(cust[i],cust[j]);
            }
        }
    }
    int len=0;
    maxCustomer=new Customer[1];
    maxCustomer[0]=cust[0];
    len++;

    for(int i=1; i<Size; i++)
    {
        if(cust[i].arrivalTime>=maxCustomer[len-1].departureTime)
        {
            len++;
            Customer *temp_data=maxCustomer;
            maxCustomer=new Customer[len];
            for(int j=0;j<len;j++){
                maxCustomer[j]=temp_data[j];
            }
            delete temp_data;
            maxCustomer[len-1]=cust[i];
        }
    }
    return maxCustomer;
}
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("greedyInput.txt");
    fout.open("greedyOutput.txt");
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
    int n,arrTime,depTime;
    string s;
    getline(fin,s);
    istringstream sso1(s);
    sso1>>n;
    Customer *customer;
    customer=new Customer[n];
    for(int i=0; i<n; i++)
    {
        getline(fin,s);
        istringstream sso2(s);
        sso2>>arrTime>>depTime;
        Customer c(arrTime,depTime);
        customer[i]=c;
    }
    Customer *maxCustomerList=maxCustomerWithGreedyApproach(customer,n);
    int maxNumber=sizeof(maxCustomerList);
    fout<<maxNumber<<endl;
    for(int i=0; i<maxNumber; i++)
    {
        fout<<maxCustomerList[i].arrivalTime<<"  "<<maxCustomerList[i].departureTime<<endl;
    }

}
