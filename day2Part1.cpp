#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>

using namespace std;

int main()
{
    ifstream fin;
    string line;

    fin.open("day2Input.txt");

    unordered_map<string, int> mp;

    mp["red"] = 0;
    mp["blue"] = 0;
    mp["green"] = 0;

    int r = 12, g = 13, b = 14;

    int id = 1;
    int ans = 0;

    while (getline(fin, line)) 
    {
        int pos = line.find(":");
        line = line.substr(pos + 2);

        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        line += ";";

        cout<<line<<"\n";

        int i = 0;
        bool allGood = true;

        int num = 0;
        string color = "";
        string numS = "";

        while(i < line.length())
        {
            mp["red"] = 0;
            mp["blue"] = 0;
            mp["green"] = 0;

            while(i < line.length())
            {
                num = 0;
                color = "";
                numS = "";

                while(isdigit(line[i]))
                {
                    numS += line[i];
                    i++;
                }

                num = stoi(numS);
                
                while(line[i] != ',' && line[i] != ';')
                {
                    color += line[i];
                    i++;
                }

                i++;
                mp[color] = num;

                if(mp["red"] > r || mp["blue"] > b || mp["green"] > g)
                {
                    allGood = false;
                }
            }

            i++;
        }
        
        if(allGood)
        {
            ans += id;
        }

        id++;
    }

    cout<<ans;
}