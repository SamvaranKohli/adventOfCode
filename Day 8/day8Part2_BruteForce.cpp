#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

// Brute force method
// this will take a long time to get the answer

int main()
{
    ifstream fin;
    string line;

    fin.open("day8Input.txt");

    string movement = "";
    bool pairs = false;

    unordered_map<string, pair<string, string>> mp;

    while (getline(fin, line))
    {
        if(!pairs && line != "")
        {
            movement += line;
            continue;
        }

        if(line == "")
        {
            pairs = true;
            continue;
        }

        int i = 0;

        string startNode = "";
        string left = "";
        string right = "";

        while(line[i] != ' ')
        {
            startNode += line[i];
            i++;
        }

        i += 4;

        while(line[i] != ',')
        {
            left += line[i];
            i++;
        }

        i+=2;

        while(line[i] != ')')
        {
            right += line[i];
            i++;
        }

        mp[startNode] = {left, right};

    }

    long long int ans = 0;

    // store all the starting nodes
    vector<string> startNodes;

    // store the nodes that end in 'A'
    for(auto it : mp)
    {
        if(it.first[2] == 'A')
            startNodes.push_back(it.first);
    }
    
    bool exitOutOfLoop = false;

    while(!exitOutOfLoop)
    {
        // for each movement
        for(int i = 0; i < movement.length(); i++)
        {
            // loop through all the nodes
            // and same logic as part 1
            for(int j = 0; j < startNodes.size(); j++)
            {
                if(movement[i] == 'L')
                {
                    startNodes[j] = mp[startNodes[j]].first;
                }
                else if(movement[i] == 'R')
                {
                    startNodes[j] = mp[startNodes[j]].second;
                }
            }
            ans++;

            // check if all nodes have 'Z' as the last char
            // to check if we have reached the end
            bool reached = true;

            for(int j = 0; j < startNodes.size(); j++)
            {
                if(startNodes[j][2] != 'Z')
                {
                    reached = false;
                    break;
                }
            }

            if(reached)
            {
                exitOutOfLoop = true;
                break;
            }
        }
    }

    cout<<ans;

    return 0;
}