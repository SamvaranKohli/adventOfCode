#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

void rec(vector<vector<int>> &mp, int i, int j, int prev, vector<vector<int>> &visited)
{
    // cout<<i<<" "<<j<<"\n";

    if(prev == 9)
    {
        visited[i][j] = 1;
        return;
    }

    vector<int> delta_x = {0, 1, 0, -1};
    vector<int> delta_y = {1, 0, -1, 0};

    int sum = 0;

    for(int k = 0; k < 4; k++)
    {
        int x = i + delta_x[k];
        int y = j + delta_y[k];

        if(x >= 0 && y >= 0 && x < mp.size() && y < mp[0].size() && mp[x][y] == (prev+1))
        {
            rec(mp, x, y, prev+1, visited);
        }

    }

}

int main()
{
    ifstream fin;
    string line;

    long long ans = 0;

    fin.open("day10Input.txt");

    vector<vector<int>> mp;

    while (getline(fin, line)) 
    {
        vector<int> t;

        for(int i = 0; i < line.size(); i++)
        {
            t.push_back((line[i]-'0'));
        }

        mp.push_back(t);
    }

    for(int i = 0; i < mp.size(); i++)
    {
        for(int j = 0; j < mp[0].size(); j++)
        {
            if(mp[i][j] == 0)
            {
                vector<vector<int>> visited(mp.size(), vector<int> (mp[0].size(), 0));
                rec(mp, i, j, 0, visited);
                for(int m = 0; m < mp.size(); m++)
                {
                    for(int n = 0; n < mp[0].size(); n++)
                    {
                        if(visited[m][n] == 1)
                        {
                            ans++;
                        }
                    }
                }

            }
        }
    }
    
    cout<<ans;
 
    fin.close();
    return 0;
}