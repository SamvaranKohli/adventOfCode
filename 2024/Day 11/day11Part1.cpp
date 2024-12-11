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

    vector<long long> mp;

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
            mp.push_back(n);
        }  
    }

    for(int i = 0; i < 25; i++)
    {
        //cout<<i<<" ";
        for(int j = 0; j < mp.size(); j++)
        {
            if(mp[j] == 0)
            {
                mp[j] = 1;
            }
            else
            {
                string t = to_string(mp[j]);

                if(t.size() % 2 == 0)
                {
                    int n1 = 0;
                    int n2 = 0;

                    for(int k = 0; k < t.size()/2; k++)
                    {
                        n1 = n1*10 + t[k]-'0';
                    }

                    mp[j] = n1;

                    for(int k = t.size()/2; k < t.size(); k++)
                    {
                        n2 = n2*10 + t[k]-'0';
                    }

                    mp.insert(mp.begin()+j+1, n2);
                    j++;
                }
                else
                {
                    mp[j] *= 2024;
                }
            }
        }
    }
    
    cout<<mp.size();
 
    fin.close();
    return 0;
}