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

    int ans = 0;

    fin.open("day6Input.txt");

    vector<vector<char>> mp;

    int x, y;
 
    while (getline(fin, line)) 
    {
        vector<char> t;

        for(int i = 0; i < line.size(); i++)
        {
            t.push_back(line[i]);

            if(line[i] == '^')
            {
                x = mp.size();
                y = i;
            }
        }

        mp.push_back(t);
    }

    vector<vector<int>> visited(mp.size(), vector<int> (mp[0].size(), 0));

    bool exit_ = true;
    char direction = 'U';

    while(true)
    {
        if(direction == 'U')
        {
            while(x != 0 && mp[x-1][y] != '#')
            {
                visited[x][y] = 1;
                x--;
            }

            direction = 'R';

            if(x == 0)
            {
                break;
            }
        }
        else if(direction == 'R')
        {
            while(y != mp[0].size()-1 && mp[x][y+1] != '#')
            {
                visited[x][y] = 1;
                y++;
            }

            direction = 'D';

            if(y == mp[0].size()-1)
            {
                break;
            }
        }
        else if(direction == 'D')
        {
            while(x != mp.size()-1 && mp[x+1][y] != '#')
            {
                visited[x][y] = 1;
                x++;
            }

            direction = 'L';

            if(x == mp.size()-1)
            {
                break;
            }
        }
        else if(direction == 'L')
        {
            while(y != 0 && mp[x][y-1] != '#')
            {
                visited[x][y] = 1;
                y--;
            }

            direction = 'U';

            if(y == 0)
            {
                break;
            }
        }
    }

    for(int i = 0; i < visited.size(); i++)
    {
        for(int j = 0; j < visited[0].size(); j++)
        {
            if(visited[i][j] == 1)
            {
                ans++;
            }
        }
    }

    cout<<ans;
 
    fin.close();
    return 0;
}