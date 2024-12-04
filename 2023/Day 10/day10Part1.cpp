#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

int startX = 0, startY = 0;

void startPoint(vector<vector<char>> input)
{
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[i].size(); j++)
        {
            if(input[i][j] == 'S')
            {
                startX = i;
                startY = j;
                return;
            }
        }
    }
}

void traverse(vector<vector<char>> input, int i, int j,  unordered_map<int, pair<int, int>> &path)
{
    int prevI = startX;
    int prevJ = startY;

    int a = 1;

    while(input[i][j] != 'S')
    {
        path[a++] = {i, j};

        if(input[i][j] == '|')
        {
            if(i+1 == prevI)
            {
                prevI = i;
                prevJ = j;
                i -= 1;
            }
            else if(i-1 == prevI)
            {
                prevI = i;
                prevJ = j;
                i += 1;
            }
        }
        else if(input[i][j] == '-')
        {
            if(j+1 == prevJ)
            {
                prevI = i;
                prevJ = j;
                j -= 1;
            }
            else if(j-1 == prevJ)
            {
                prevI = i;
                prevJ = j;
                j += 1;
            }
        }
        else if(input[i][j] == 'L')
        {
            if(i-1 == prevI)
            {
                prevI = i;
                prevJ = j;
                j += 1;
            }
            else if(j+1 == prevJ)
            {
                prevI = i;
                prevJ = j;
                i -= 1;
            }
        }
        else if(input[i][j] == 'J')
        {
            if(i-1 == prevI)
            {
                prevI = i;
                prevJ = j;
                j -= 1;
            }
            else if(j-1 == prevJ)
            {
                prevI = i;
                prevJ = j;
                i -= 1;
            }
        }
        else if(input[i][j] == '7')
        {
            if(j-1 == prevJ)
            {
                prevI = i;
                prevJ = j;
                i += 1;
            }
            else if(i+1 == prevI)
            {
                prevI = i;
                prevJ = j;
                j -= 1;
            }
        }
        else if(input[i][j] == 'F')
        {
            if(i+1 == prevI)
            {
                prevI = i;
                prevJ = j;
                j += 1;
            }
            else if(j+1 == prevJ)
            {
                prevI = i;
                prevJ = j;
                i += 1;
            }
        }
        else if(input[i][j] == '.')
        {
            break;
        }

    }

    // for(auto it : path)
    // {
    //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<"\n";
    // }

}

int main()
{
    ifstream fin;
    string line;

    fin.open("day10Input.txt");

    vector<vector<char>> input;

    while (getline(fin, line))
    {
        vector<char> temp;

        for(int i = 0; i < line.size(); i++)
        {
            temp.push_back(line[i]);
        }

        input.push_back(temp);
    }

    startPoint(input);

    unordered_map<int, pair<int, int>> path1;
    unordered_map<int, pair<int, int>> path2;

    traverse(input, startX, startY+1, path1);
    traverse(input, startX, startY-1, path2);

    for(auto it : path1)
    {
        int index = it.first;

        if(path1[index].first == path2[index].first && path1[index].second == path2[index].second)
        {
            cout<<index;
            break;
        }
    }

    return 0;
}