#include<iostream>
#include<fstream>
#include<unordered_set>
#include<string>

using namespace std;

int main()
{
    ifstream fin;
    string line;

    int ans = 0;

    fin.open("day4Input.txt");

    unordered_set<int> winning;

    while (getline(fin, line)) 
    {
        int pos = line.find(":");
        line = line.substr(pos + 2);
        int points = 0;

        //cout<<line<<"\n";

        int num = 0;
        int i = 0;

        while(line[i] != '|')
        {
            string numS = "";

            while(line[i] != ' ')
            {
                numS += line[i];
                i++;
            }

            if(numS != "")
            {
                num = stoi(numS);
                winning.insert(num);
            }

            while(line[i] == ' ')
                i++;

        }

        // for(auto it : winning)
        // {
        //     cout<<it<<" ";
        // }

        // cout<<"\n";

        i += 2;

        while(i < line.length())
        {
            string numS = "";

            while(line[i] != ' ')
            {
                numS += line[i];
                i++;
            }

            if(numS != "")
            {
                num = stoi(numS);

                if(winning.find(num) != winning.end())
                    points++;
            }

            while(line[i] == ' ')
                i++;

        }

        ans += pow(2, points-1);

        winning.clear();

    }

    cout<<ans;

    return 0;
}