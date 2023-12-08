#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

// optimized using LCM
// why does it work ?

// test input

// LR
// 11A = (11B, XXX)
// 11B = (XXX, 11Z)
// 11Z = (11B, XXX)
// 22A = (22B, XXX)
// 22B = (22C, 22C)
// 22C = (22Z, 22Z)
// 22Z = (22B, 22B)
// XXX = (XXX, XXX)

// for 11A
// the cycle of reaching the z values repeates itself
// it will go to 11A -> [11B -> 11Z] -> [11B -> 11Z] and so on...
// the steps which are repeated = 2

// similary for 11B
// it will go from -> 11B -> [22B -> 22C -> 22Z] -> [22B -> 22C -> 22Z] and so on...
// the steps which are repeated = 3

// so the point at which they will meet will be the LCM of both [2, 3] = 6
// therefore the LCM solution works


// functions to calculate the lcm
long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

long long int findlcm(vector<long long int> arr)
{
    long long int ans = arr[0];
    int n = arr.size();
 
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
 
    return ans;
}

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

    vector<string> startNodes;

    for(auto it : mp)
    {
        if(it.first[2] == 'A')
            startNodes.push_back(it.first);
    }

    // store the repated steps for each starting node
    vector<long long int> lcm_;

    // loop through all the starting nodes
    for(int j = 0; j < startNodes.size(); j++)
    {
        long long int i = 0;
        long long int steps = 0;
        bool reached = false;

        // till we find the z we keep on going
        while(!reached)
        {
            // loop through the movements
            for(int i = 0; i < movement.size(); i++)
            {
                // same logic as part 1
                if(movement[i] == 'L')
                {
                    startNodes[j] = mp[startNodes[j]].first;
                }
                else if(movement[i] == 'R')
                {
                    startNodes[j] = mp[startNodes[j]].second;
                }

                // increase the steps
                steps++;

                // if we find 'Z' just push the steps for LCM and move to the next node
                if(startNodes[j][2] == 'Z')
                {
                    lcm_.push_back(steps);
                    reached = true;
                    break;
                }
            }

        }
    }

    ans = findlcm(lcm_);

    cout<<ans;

    return 0;
}