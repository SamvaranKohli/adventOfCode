#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int main()
{
    ifstream fin;
    string line;

    int ans = 0;

    fin.open("day5Input1.txt");

    unordered_map<int, vector<int>> adj;
    unordered_set<int> v;
 
    while (getline(fin, line)) 
    {
        int i = 0;
        int n1 = 0;
        int n2 = 0;

        while(line[i] != '|')
        {
            n1 = n1*10 + line[i]-'0';
            i++;
        }

        i++;

        while(i < line.size())
        {
            n2 = n2*10 + line[i]-'0';
            i++;
        }

        adj[n1].push_back(n2);
        v.insert(n1);
        v.insert(n2);
    }

    fin.close();

    unordered_map<int, int> degree;
    vector<int> updates;
    queue<int> q;

    for (auto it = v.begin(); it != v.end(); it++) 
    {
        //cout << "Key: " << it->first << " Values: ";

        for (int value : adj[*it]) 
        {
            degree[value]++;
        }
    }

    for (auto it = v.begin(); it != v.end(); it++) 
    {
        if(degree[*it] == 0)
        {
            q.push(*it);
        }
    }

    while(!q.empty())
    {
        int front = q.front();
        updates.push_back(front);
        q.pop();

        for(auto it : adj[front])
        {
            degree[it]--;

            if(degree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    fin.open("day5Input2.txt");

    while (getline(fin, line)) 
    {
        int i = 0;
        int index = 0;

        vector<int> lineValues;

        while(i < line.size())
        {
            int n1 = 0;

            while(i < line.size() && line[i] != ',')
            {
                n1 = n1*10 + line[i]-'0';
                i++;
            }

            i++;

            lineValues.push_back(n1);
        }

        bool is_sorted = std::is_sorted(lineValues.begin(), lineValues.end(), [&](int x, int y) 
        {
            return std::distance(updates.begin(), std::find(updates.begin(), updates.end(), x)) < std::distance(updates.begin(), std::find(updates.begin(), updates.end(), y));
        });

        if(!is_sorted)
        {
            sort(lineValues.begin(), lineValues.end(), [&](int x, int y) 
            {
                return std::find(updates.begin(), updates.end(), x) < std::find(updates.begin(), updates.end(), y);
            });

            ans += lineValues[lineValues.size()/2];

        }
    }

    cout<<ans;
 
    fin.close();
    return 0;
}