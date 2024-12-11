#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

int main()
{
    ifstream fin;
    string line;

    long long ans = 0;

    fin.open("day11Input.txt");

    unordered_map<long long, int> mp;

    while (getline(fin, line)) 
    {
        int i = 0;

        while(i < line.size())
        {
            long long n = 0;

            while(i < line.size() && line[i] != ' ')
            {
                n = n*10 + line[i]-'0';
                i++;
            }

            i++;
            mp[n] = 1;
        }  
    }

    for(int i = 0; i < 75; i++)
    {
        //cout<<i<<" ";

        unordered_map<long long, int> temp;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->first == 0)
            {
                temp[1] += it->second;
            }
            else
            {
                string t = to_string(it->first);

                if(t.size() % 2 == 0)
                {
                    int n1 = 0;
                    int n2 = 0;

                    for(int k = 0; k < t.size()/2; k++)
                    {
                        n1 = n1*10 + t[k]-'0';
                    }

                    temp[n1] += it->second;

                    for(int k = t.size()/2; k < t.size(); k++)
                    {
                        n2 = n2*10 + t[k]-'0';
                    }

                    temp[n2] += it->second;

                }
                else
                {
                    temp[(it->first*2024)] += it->second;
                }
            }
        }

        mp = temp;

    }
    
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        ans += it->second;
    }

    cout<<ans;
 
    fin.close();
    return 0;
}