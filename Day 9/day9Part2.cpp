#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

// same logic as part 1
// just subract values (ith - ith + 1) and then add it to the front of the vector

long long int ans = 0;

void printArray(vector<vector<long long int>> input)
{
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[i].size(); j++)
        {
            cout<<input[i][j]<<" ";
        }

        cout<<"\n";
    }

    cout<<"\n";
}

void historyValue(vector<long long int> report)
{
    vector<vector<long long int>> input;

    bool allZero = false;

    input.push_back(report);

    while(!allZero)
    {
        vector<long long int> temp;
        allZero = true;

        for(int i = 0; i < report.size()-1; i++)
        {
            int t = report[i+1] - report[i];
            temp.push_back(t);
        }

        for(int i = 0; i < temp.size(); i++)
        {
            if(temp[i] != 0)
                allZero = false;
        }

        input.push_back(temp);
        report = temp;
    }

    int n = input.size();

    input[n-1].insert(input[n-1].begin(), 0);

    for(int i = n-2; i >= 0; i--)
    {
        input[i].insert(input[i].begin(),  input[i][0]-input[i+1][0]);
    }

    ans += input[0][0];

}

int main()
{
    ifstream fin;
    string line;

    fin.open("day9Input.txt");

    vector<vector<long long int>> input;

    while (getline(fin, line))
    {
        vector<long long int> temp;

        int i = 0;

        while(i < line.length())
        {
            string numS = "";

            while(i < line.length() && line[i] != ' ')
            {
                numS += line[i];
                i++;
            }

            temp.push_back(stoi(numS));
            i++;
        }

        input.push_back(temp);
    }

    for(int i = 0; i < input.size(); i++)
    {
        historyValue(input[i]);
    }

    cout<<ans;

}