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

    fin.open("day9Input.txt");

    vector<string> s;

    while (getline(fin, line)) 
    {
        int id = 0;

        for(int i = 0; i < line.size(); i++)
        {
            
            for(int j = 0; j < (line[i]-'0'); j++)
            {
                if(i%2 == 0)
                {
                    s.push_back(to_string(id));
                }
                else
                {
                    s.push_back(".");
                }
            }
            
            if(i%2 == 0)
            {
                id++;
            }
        }
    }

    int j = s.size()-1;

    while(s[j] == ".")
    {
        j--;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(i < j && s[i] == ".")
        {
            swap(s[i], s[j]);
            while(s[j] == ".")
            {
                j--;
            }
        }
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ".")
        {
            break;
        }

        int n = 0;
        int j = 0;
        while(j < s[i].size())
        {
            n = n*10 + s[i][j]-'0';
            j++;
        }

        ans = ans + (i*n);
    }

    cout<<ans;
 
    fin.close();
    return 0;
}