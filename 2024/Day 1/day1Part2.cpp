#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ifstream fin;
    string line;

    int ans = 0;

    vector<int> a;

    unordered_map<int, int> mp;

    fin.open("day1Input.txt");
 
    while (getline(fin, line)) 
    {
        int num = 0;
        int i = 0;

        while(line[i] != ' ')
        {
            num = num*10 + line[i]-'0';
            i++;
        }

        i += 3;

        a.push_back(num);
        num = 0;

        while(i < line.size())
        {
            num = num*10 + line[i]-'0';
            i++;
        }

        mp[num]++;
    }

    for(int i = 0; i < a.size(); i++)
    {
        ans += a[i]*mp[a[i]];
    }

    cout<<ans;
 
    fin.close();
    return 0;
}