#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

int main()
{
    ifstream fin;
    string line;

    fin.open("day8Input.txt");

    // store the instructions for the movement
    string movement = "";

    bool pairs = false;

    unordered_map<string, pair<string, string>> mp;

    // read the input and store it in a map [node : {leftNode, rightNode}]
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

    // set the starting node
    string currNode = "AAA";
    int ans = 0;

    // to check if end node is found
    bool reached = false;

    // till we have not reached the end loop through the movements again and agin
    while(!reached)
    {
        // for each movement
        for(int i = 0; i < movement.length(); i++)
        {
            // check if it left or rigth and set the current node accordingly from the map
            // also increment the answer as each iteration counts as a step
            if(movement[i] == 'L')
            {
                currNode = mp[currNode].first;
                ans++;
            }
            else if(movement[i] == 'R')
            {
                currNode = mp[currNode].second;
                ans++;
            }

            // if the curr node is the end node, stop and get out
            if(currNode == "ZZZ")
            {
                reached = true;
                break;
            }

        }
    }

    cout<<ans;

    return 0;
}