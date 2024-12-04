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

    vector<int> a;
    vector<int> b;

    fin.open("day2Input.txt");
 
    while (getline(fin, line)) 
    {
        bool safe = true;

        vector<int> a;

        int n = 0;
        int i = 0;

        while(i < line.size())
        {
            n = 0;

            while(i < line.size() && line[i] != ' ')
            {
                n = n*10 + line[i]-'0';
                i++;
            }

            i++;

            a.push_back(n);
        }

        int s = 0;

        if(a[0] < a[1])
        {
            s = 1;
        }

        bool once = true;

        for(i = 0; i < a.size()-1; i++)
        {
            if(s == 1)
            {
                int diff = a[i+1] - a[i];

                //cout<<diff<<" ";

                if(diff > 3 || diff <= 0)
                {
                    if(once)
                    {
                        once = false;
                        continue;
                    }

                    safe = false;
                    break;
                }
            }
            else
            {
                int diff = a[i] - a[i+1];

                //cout<<diff<<" ";

                if(diff > 3 || diff <= 0)
                {
                    if(once)
                    {
                        once = false;
                        continue;
                    }
                    
                    safe = false;
                    break;
                }
            }
        }

        //cout<<"\n";

        if(safe)
        {
            ans++;
        }
    }

    cout<<ans;
 
    fin.close();
    return 0;
}