#include<iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    string line;

    int ans = 0;

    fin.open("sample.txt");
 
    while (getline(fin, line)) 
    {
        int s, e;
        
        for(int i = 0; i < line.length(); i++)
        {
            if(isdigit(line[i]))
            {
                s = line[i] - '0';
                s *= 10;
                break;
            }
        }

        for(int i = line.length()-1; i >= 0; i--)
        {
            if(isdigit(line[i]))
            {
                e = line[i] - '0';
                break;
            }
        }

        ans += s+e;

        cout<<s+e<<"\n";
    }

    cout<<ans;
 
    fin.close();
    return 0;
}