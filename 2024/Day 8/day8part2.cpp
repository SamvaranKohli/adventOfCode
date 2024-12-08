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

    fin.open("day8Input.txt");

    unordered_map<char, vector<pair<int, int>>> mp;

    int i = 0;

    int col = 0;
    int row = 0;

    while (getline(fin, line)) 
    {
        col = line.size();

        for(int j = 0; j < line.size(); j++)
        {
            if(line[j] != '.')
            {
                mp[line[j]].push_back({i, j});
            }
        }

        i++;
    }

    row = i;

    vector<vector<int>> anti(row, vector<int> (col, 0));

    for (auto it = mp.begin(); it != mp.end(); it++) 
    {
        char key = it->first;
        vector<pair<int, int>> value = it->second;

        for(i = 0; i < value.size(); i++)
        {
            anti[value[i].first][value[i].second] = 1;
            for(int j = i+1; j < value.size(); j++)
            {
                int x = value[j].first - value[i].first;
                int y = value[j].second - value[i].second;

                int x_new = value[j].first + x;
                int y_new = value[j].second + y;

                while(x_new >= 0 && x_new < row && y_new >= 0 && y_new < col)
                {
                    anti[x_new][y_new] = 1;
                    x_new += x;
                    y_new += y;
                }

                x = value[i].first - value[j].first;
                y = value[i].second - value[j].second;

                x_new = value[i].first + x;
                y_new = value[i].second + y;

                while(x_new >= 0 && x_new < row && y_new >= 0 && y_new < col)
                {
                    anti[x_new][y_new] = 1;
                    x_new += x;
                    y_new += y;
                }
            }
        }

    }

    for(int i = 0; i < anti.size(); i++)
    {
        for(int j = 0; j < anti[0].size(); j++)
        {
            if(anti[i][j] == 1)
            {
                ans++;
            }
        }
    }

    cout<<ans;
 
    fin.close();
    return 0;
}