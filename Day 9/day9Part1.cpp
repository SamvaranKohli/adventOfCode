#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

// store the answer
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

// calculate the answer for each line
void historyValue(vector<long long int> report)
{
    vector<vector<long long int>> input;

    // check if we have reached all zero or not
    bool allZero = false;

    input.push_back(report);

    // run till it is not all zero
    while(!allZero)
    {
        vector<long long int> temp;
        allZero = true;

        // loop throuh, subtract the two adjacent values and store it in a vector
        for(int i = 0; i < report.size()-1; i++)
        {
            int t = report[i+1] - report[i];
            temp.push_back(t);
        }

        // check if zeros or not
        for(int i = 0; i < temp.size(); i++)
        {
            if(temp[i] != 0)
                allZero = false;
        }

        // insert it into the 2d vector(that store all the steps)
        input.push_back(temp);
        report = temp;
    }

    // simply add the last value of the ith and ith+1 vector
    int n = input.size();

    input[n-1].push_back(0);

    for(int i = n-2; i >= 0; i--)
    {
        int s = input[i].size()-1;

        input[i].push_back(input[i][s]+input[i+1][s]);
    }

    // add the last value of the 0th vector to the answer
    ans += input[0][input[0].size()-1];

}

int main()
{
    ifstream fin;
    string line;

    fin.open("day9Input.txt");

    vector<vector<long long int>> input;

    // extract input
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

    /// run for all the lines
    for(int i = 0; i < input.size(); i++)
    {
        historyValue(input[i]);
    }

    cout<<ans;

}