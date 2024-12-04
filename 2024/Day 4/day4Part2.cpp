#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ifstream fin;
    string line;

    int ans = 0;

    fin.open("day4Input.txt");

    vector<vector<char>> m;
 
    while (getline(fin, line)) 
    {
        vector<char> t;

        for(int i = 0; i < line.size(); i++)
        {
            t.push_back(line[i]);
        }

        m.push_back(t);
    }

    for(int i = 1; i < m.size()-1; i++)
    {
        for(int j = 1; j < m[0].size()-1; j++)
        {

            string s1 = "";
            string s2 = "";

            s1 += m[i-1][j-1];
            s1 += m[i][j];
            s1 += m[i+1][j+1];

            s2 += m[i-1][j+1];
            s2 += m[i][j];
            s2 += m[i+1][j-1];

            if((s1 == "MAS" || s1 == "SAM") && (s2 == "MAS" || s2 == "SAM"))
            {
                ans++;
            }
        }

    }

    cout<<ans;
 
    fin.close();
    return 0;
}