#include <bits/stdc++.h>
using namespace std;
int main()
{
    // string ->int
    map<string, int> marksMap;
    marksMap["Ahon"] = 95;
    marksMap["Nabil"] = 50;
    marksMap["Sadi"] = 100;
    for (auto i = marksMap.begin(); i != marksMap.end(); i++)
    {
        cout << (*i).first << "--> " << (*i).second << endl;
    }
    cout << marksMap["Sadi"] << endl;
    //pair->int
    map<pair<int,int>,int> pointMap;
    pointMap[{0,0}]=0;
    pointMap[{1,2}]=1;
    pointMap[{3,8}]=2;
    pointMap[{6,10}]=3;
    for (auto i = pointMap.begin(); i != pointMap.end(); i++)
    {
        cout <<"(" <<(*i).first.first<<","<< (*i).first.second<<")"<< "--> " << (*i).second << endl;
    }
    cout<<pointMap[{1,2}]<<endl;
}