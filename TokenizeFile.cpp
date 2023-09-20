#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("BinomialHeapInput.txt", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        cout << "Line: " << line << endl;

        stringstream ss(line);
        int number;
        string word;
        ss >> word;
        cout<<"Word: " << word << endl;
        while (ss >> number)
        {
            cout << "Number: " << number << endl;
        }
    }
}
