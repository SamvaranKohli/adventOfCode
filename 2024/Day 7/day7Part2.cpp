#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

bool rec(int i, vector<long long> num, long long target, long long val)
{
    if(val > target)
    {
        return false;
    }

    if(i == num.size())
    {
        if(val == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool sum = rec(i+1, num, target, val+num[i]);
    bool mul = rec(i+1, num, target, val*num[i]);

    int l = to_string(num[i]).size();
    long long calc = val * pow(10, l);
    calc += num[i];

    bool combine = rec(i+1, num, target, calc);

    return sum || mul || combine;
}

int main()
{
    ifstream fin;
    string line;

    long long ans = 0;

    fin.open("day7Input.txt");

    vector<vector<long long>> mp;
    vector<long long> target;

    int x, y;
 
    while (getline(fin, line)) 
    {
        int i = 0;
        long long t = 0;

        while(line[i] != ':')
        {
            t = t*10 + line[i]-'0';
            i++;
        }

        target.push_back(t);
        i += 2;

        vector<long long> temp;

        while(i < line.size())
        {
            int n = 0;

            while(i < line.size() && line[i] != ' ')
            {
                n = n*10 + line[i]-'0';
                i++;
            }

            i++;

            temp.push_back(n);
        }

        mp.push_back(temp);

    }

    for(int i = 0; i < mp.size(); i++)
    {
        if(rec(1, mp[i], target[i], mp[i][0]))
        {
            ans += target[i];
        }
    }

    cout<<ans;
 
    fin.close();
    return 0;
}