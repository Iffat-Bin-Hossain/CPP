#include <bits/stdc++.h>
using namespace std;
class Job
{
public:
    int id, profit, deadline;
    Job()
    {
        id = -1;
        profit = 0;
        deadline = 0;
    }
    Job(int profit, int deadline)
    {
        this->profit = profit;
        this->deadline = deadline;
    }
};
int main()
{
    int n;
    cin >> n;
    Job job[n];
    for (int i = 0; i < n; i++)
    {
        int profit, deadline;
        cin >>  deadline>>profit;
        job[i].id = i + 1;
        job[i].profit = profit;
        job[i].deadline = deadline;
    }
    // Sort in basis of profit
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (job[j].profit > job[i].profit)
            {
                swap(job[j], job[i]);
            }
        }
    }
    //Maximum of the deadlines
    int maxSlot = job[0].deadline;
    for (int i = 1; i < n; i++)
    {
        if (job[i].deadline > maxSlot)
        {
            maxSlot = job[i].deadline;
        }
    }
    int selectedJob[maxSlot]={0};
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = job[i].deadline - 1; j >= 0; j--)
        {
            if (selectedJob[j] == 0)
            {
                selectedJob[j] = job[i].id;
                maxProfit += job[i].profit;
                break;
            }
        }
    }
     cout<<maxProfit<<endl;
    for (int i = 0; i < maxSlot; i++)
    {
        cout <<"T"<<selectedJob[i] << "  ";
    }
}