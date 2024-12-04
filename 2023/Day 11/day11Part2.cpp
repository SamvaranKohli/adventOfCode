#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

long long int ans = 0;

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

void addRow(vector<vector<char>> &input, vector<int> &row)
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
            row.push_back(i);
    }
}

void changePairValue(vector<pair<long long int, long long int>> &pairs, vector<int> rows, vector<int> cols)
{
    long long int greaterThan = 0;
    long long int n = 1000000-1;

    for(int i = 0; i < rows.size(); i++)
    {
        bool inc = false;
        for(int j = 0; j < pairs.size(); j++)
        {
            if(pairs[j].first > rows[i]+greaterThan)
            {
                pairs[j].first += n;
                inc = true;
            }
        }

        if(inc)
            greaterThan += n;
    }

    greaterThan = 0;

    for(int i = 0; i < cols.size(); i++)
    {
        bool inc = false;
        for(int j = 0; j < pairs.size(); j++)
        {
            if(pairs[j].second > cols[i]+greaterThan)
            {
                pairs[j].second += n;
                inc = true;
            }
        }

        if(inc)
            greaterThan += n;
    }
}

void countMinOfPairs(vector<vector<char>> input, vector<int> rows, vector<int> cols)
{
    vector<pair<long long int, long long int>> pairs;

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

    changePairValue(pairs, rows, cols);

    for(int i = 0; i < pairs.size()-1; i++)
    {
        int min_ = INT_MAX;

        for(int j = i+1; j < pairs.size(); j++)
        {
            long long int ith = abs(pairs[j].first-pairs[i].first);
            long long int jth = abs(pairs[j].second-pairs[i].second);

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

    vector<int> rows;
    vector<int> cols;

    addRow(input, rows);
    transpose(input);
    addRow(input, cols);
    transpose(input);

    for(int i = 0; i < rows.size(); i++)
        cout<<rows[i]<<" ";

    cout<<"\n";

    for(int i = 0; i < cols.size(); i++)
        cout<<cols[i]<<" ";

    cout<<"\n";

    printArray(input);

    countMinOfPairs(input, rows, cols);

    cout<<ans;
}