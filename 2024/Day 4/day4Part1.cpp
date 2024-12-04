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

    for(int i = 0; i < m.size(); i++)
    {
        for(int j = 0; j < m[0].size(); j++)
        {

            string s = "";

            if(j < m[0].size()-3)
            {
                s += m[i][j];
                s += m[i][j+1];
                s += m[i][j+2];
                s += m[i][j+3];

                if(s == "XMAS" || s == "SAMX")
                {
                    ans++;
                }
            }

            s = "";

            if(i < m.size()-3)
            {
                s += m[i][j];
                s += m[i+1][j];
                s += m[i+2][j];
                s += m[i+3][j];

                if(s == "XMAS" || s == "SAMX")
                {
                    ans++;
                }
            }

            s = "";

            if(j < m[0].size()-3 && i < m.size()-3)
            {
                s += m[i][j];
                s += m[i+1][j+1];
                s += m[i+2][j+2];
                s += m[i+3][j+3];

                if(s == "XMAS" || s == "SAMX")
                {
                    ans++;
                }
            }

            s = "";

            if(j >= 3 && i < m.size()-3)
            {
                s += m[i][j];
                s += m[i+1][j-1];
                s += m[i+2][j-2];
                s += m[i+3][j-3];

                if(s == "XMAS" || s == "SAMX")
                {
                    ans++;
                }

            }
        }

    }

    cout<<ans;
 
    fin.close();
    return 0;
}