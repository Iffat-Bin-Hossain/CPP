#include <bits/stdc++.h>
using namespace std;
class book
{
public:
    int m;
    string skill;

    book()
    {
    }
    book(int m, string skill)
    {
        this->m = m;
        this->skill = skill;
    }
};
void sort(vector<book> &skillN)
{
    int l = skillN.size();
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (skillN.at(j).m < skillN.at(i).m)
            {
                swap(skillN.at(j), skillN.at(i));
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        book b[n];
        for (int j = 0; j < n; j++)
        {
            int m;
            string s;
            cin >> m >> s;
            book books(m, s);
            b[j] = books;
        }
        vector<book> skill1, skill2, skill3;

        for (int k = 0; k < n; k++)
        {
            if (b[k].skill == "10")
            {
                skill1.push_back(b[k]);
            }
            else if (b[k].skill == "01")
            {
                skill2.push_back(b[k]);
            }
            else if (b[k].skill == "11")
            {
                skill3.push_back(b[k]);
            }
        }
        int min1 = INT_MAX;
        if (skill1.size() != 0)
        {
            for (int l = 0; l < skill1.size(); l++)
            {
                min1 = min(skill1[l].m, min1);
            }
        }
        else
        {
            min1 = 0;
        }
        int min2 = INT_MAX;
        if (skill2.size() != 0)
        {
            for (int l = 0; l < skill2.size(); l++)
            {
                min2 = min(skill2[l].m, min2);
            }
        }
        else
        {
            min2 = 0;
        }
        int min3 = INT_MAX;
        if (skill3.size() != 0)
        {
            for (int l = 0; l < skill3.size(); l++)
            {
                min3 = min(skill3[l].m, min3);
            }
        }
        else
        {
            min3 = 0;
        }
        if (skill1.size() != 0 && skill2.size() != 0 && skill3.size() != 0)
        {
            if (min1 + min2 < min3)
            {
                cout <<min1 + min2 << endl;
            }
            else
            {
                cout << min3 << endl;
            }
        }
       else if (skill3.size() == 0 && (skill2.size() == 0 || skill1.size() == 0))
        {
            cout << -1 << endl;
        }
        else if (skill3.size() == 0 && (skill2.size() != 0 && skill1.size() != 0))
        {
            cout << min1+min2 << endl;
        }
        else if (skill3.size() != 0 && (skill2.size() == 0 || skill1.size() == 0))
        {
            cout << min3 << endl;
        }
        else if (skill3.size() == 0 && (skill2.size() == 0 && skill1.size() == 0))
        {
            cout << -1 << endl;
        }
    }
}