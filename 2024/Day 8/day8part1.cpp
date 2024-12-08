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
            for(int j = i+1; j < value.size(); j++)
            {
                int x = value[i].first - value[j].first;
                int y = value[i].second - value[j].second;

                int x_new = value[i].first + x;
                int y_new = value[i].second + y;

                int x_new2 = value[j].first + (x * -1);
                int y_new2 = value[j].second + (y *- 1);

                if(x_new >= 0 && x_new < row && y_new >= 0 && y_new < col)
                {
                    anti[x_new][y_new] = 1;
                }

                if(x_new2 >= 0 && x_new2 < row && y_new2 >= 0 && y_new2 < col)
                {
                    anti[x_new2][y_new2] = 1;
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