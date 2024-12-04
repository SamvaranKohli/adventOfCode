#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

int ans = 0;

void transpose(vector<vector<char>> &input)
{
    vector<vector<char>> input2;

    for(int i = 0; i < input[0].size(); i++)
    {
        vector<char> temp;

        for(int j = 0; j < input.size(); j++)
        {
            temp.push_back(input[j][i]);
        }

       input2.push_back(temp);
    }

    input = input2;
}

void printArray(vector<vector<char>> input)
{
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[i].size(); j++)
        {
            cout<<input[i][j];
        }

        cout<<"\n";
    }

    cout<<"\n";
}

void addRow(vector<vector<char>> &input)
{
    for(int i = 0; i < input.size(); i++)
    {
        bool allEmpty = true;

        for(int j = 0; j < input[i].size(); j++)
        {
            if(input[i][j] != '.')
                allEmpty = false;
        }

        if(allEmpty)
        {

            vector<char> temp(input[i].size(), '.');
            input.insert(input.begin()+i, temp);
            i++;


        }
    }
}

void countMinOfPairs(vector<vector<char>> input)
{
    vector<pair<int, int>> pairs;

    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[i].size(); j++)
        {
            if(input[i][j] == '#')
            {
                pairs.push_back({i, j});
            }
        }
    }

    for(int i = 0; i < pairs.size(); i++)
    {
        cout<<pairs[i].first<<" "<<pairs[i].second<<"\n";
    }

    for(int i = 0; i < pairs.size()-1; i++)
    {
        int min_ = INT_MAX;

        for(int j = i+1; j < pairs.size(); j++)
        {
            int ith = abs(pairs[j].first-pairs[i].first);
            int jth = abs(pairs[j].second-pairs[i].second);

            ans += ith+jth;
        }
    }
}

int main()
{
    ifstream fin;
    string line;

    fin.open("day11Input.txt");

    vector<vector<char>> input;

    while (getline(fin, line))
    {
        vector<char> temp;

        for(int i = 0; i < line.length(); i++)
        {
            temp.push_back(line[i]);
        }

        input.push_back(temp);
    }

    addRow(input);
    transpose(input);
    addRow(input);
    transpose(input);

    printArray(input);

    countMinOfPairs(input);

    cout<<ans;
}