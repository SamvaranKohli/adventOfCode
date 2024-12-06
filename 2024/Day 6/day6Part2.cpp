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

    int x1, y1;
 
    while (getline(fin, line)) 
    {
        vector<char> t;

        for(int i = 0; i < line.size(); i++)
        {
            t.push_back(line[i]);

            if(line[i] == '^')
            {
                x1 = mp.size();
                y1 = i;
            }
        }

        mp.push_back(t);
    }


    for(int k = 0; k < mp.size(); k++)
    {
        for(int l = 0; l < mp[0].size(); l++)
        {
            if(mp[k][l] == '#')
            {
                continue;
            }

            mp[k][l] = '#';

            vector<vector<pair<int, char>>> visited(mp.size(), vector<pair<int, char>> (mp[0].size()));

            char direction = 'U';

            int x = x1;
            int y = y1;

            while(true)
            {
                if(direction == 'U')
                {
                    while(x != 0 && mp[x-1][y] != '#')
                    {
                        if(visited[x][y].first == 1 && visited[x][y].second == 'U')
                        {
                            ans++;
                            x = 0;
                            break;
                        }
                        else
                        {
                            visited[x][y].first = 1;
                            visited[x][y].second = 'U';
                            x--;
                        }
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

                        if(visited[x][y].first == 1 && visited[x][y].second == 'R')
                        {
                            ans++;
                            y = mp[0].size()-1;
                            break;
                        }
                        else
                        {
                            visited[x][y].first = 1;
                            visited[x][y].second = 'R';
                            y++;
                        }
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
                        if(visited[x][y].first == 1 && visited[x][y].second == 'D')
                        {
                            ans++;
                            x = mp.size()-1;
                            break;
                        }
                        else
                        {
                            visited[x][y].first = 1;
                            visited[x][y].second = 'D';
                            x++;
                        }
                        
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
                        if(visited[x][y].first == 1 && visited[x][y].second == 'L')
                        {
                            ans++;
                            y = 0;
                            break;
                        }
                        else
                        {
                            visited[x][y].first = 1;
                            visited[x][y].second = 'L';
                            y--;
                        }
                    }

                    direction = 'U';

                    if(y == 0)
                    {
                        break;
                    }
                }
            }

            mp[k][l] = '.';
        }
    }

    cout<<ans;
 
    fin.close();
    return 0;
}