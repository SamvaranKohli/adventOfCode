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

    fin.open("day3Input.txt");
 
    while (getline(fin, line)) 
    {
        bool safe = true;

        vector<int> a;

        int n = 0;
        int i = 0;

        string s = "mul(";
        int j = 0;

        while(i < line.size())
        {
            while(line[i] == s[j])
            {
                i++;
                j++;
            }

            if(j == 4)
            {
                int n1 = 0;
                int n2 = 0;
                while(line[i] >= '0' && line[i] <= '9')
                {
                    n1 = n1*10 + line[i]-'0';
                    i++;
                }

                if(line[i] == ',')
                {
                    i++;
                }

                while(line[i] >= '0' && line[i] <= '9')
                {
                    n2 = n2*10 + line[i]-'0';
                    i++;
                }

                if(line[i] == ')')
                {
                    ans += n1*n2;
                }
            }

            i++;
            j = 0;
        }

    }

    cout<<ans;
 
    fin.close();
    return 0;
}