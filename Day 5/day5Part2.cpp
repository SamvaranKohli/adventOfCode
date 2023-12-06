#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<stack>

using namespace std;

// logic is same as part 1
// just first take 1 seed and map it till the end i.e location and store the in the ans
// calculate if it is less than the current answer

void mapValues(vector<vector<long long int>> values, long long int start, long long int end, long long int &ans)
{
    for(long long int k = start; k < end; k++)
    {
        int i = 0;
        long long int tempSeed = k;

        while(i < values.size())
        {
            bool changed = false;

            while(values[i].size() != 0)
            {
                long long int source = values[i][1];
                long long int destination = values[i][0];
                long long int count = values[i][2];

                if(!changed && tempSeed >= source && tempSeed <= source+count)
                {
                    tempSeed = destination + (tempSeed - source);
                    changed = true;
                }

                i++;
            }

            i++;
        }

        ans = min(ans, tempSeed);
    }
}

int main()
{
    ifstream fin;
    string line;

    fin.open("day5Input.txt");

    vector<vector<long long int>> values;

    vector<long long int> seeds1 = {763445965, 78570222, 1693788857, 146680070, 1157620425, 535920936, 3187993807, 180072493, 1047354752, 20193861, 2130924847, 274042257, 20816377, 596708258, 950268560, 11451287, 3503767450, 182465951, 3760349291, 265669041};

    vector<pair<long long int, long long int>> seeds2;

    for(int i = 0; i < seeds1.size(); i+=2)
    {
        seeds2.push_back({seeds1[i], seeds1[i] + seeds1[i+1]});
    }

    sort(seeds2.begin(), seeds2.end());
    
        vector<long long int> seeds;

    while (getline(fin, line))
    {
        if(line == "")
            continue;

        if (line.find("seeds:") != string::npos) 
        {
            continue;
        }

        if(line == "seed-to-soil map:")
        {
            continue;
        }
            
        if(line == "soil-to-fertilizer map:" || line == "fertilizer-to-water map:" || line == "water-to-light map:" || 
            line == "light-to-temperature map:" || line == "temperature-to-humidity map:" || line == "humidity-to-location map:")
        {
            vector<long long int> temp;
            values.push_back(temp);

            continue;
        }
        
        long long int i = 0;
        long long int num;

        vector<long long int> temp;

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
                num = stoll(numS);
                temp.push_back(num);
            }

            i++;
        }

        values.push_back(temp);

    }

    vector<long long int> temp;
    values.push_back(temp);

    long long int ans = LLONG_MAX;

    for(int i = seeds2.size()-1; i >= 0; i--)
    {
        long long int seed = seeds2[i].first;
        long long int seedEnd = seeds2[i].second;

        mapValues(values, seed, seedEnd, ans);

    }

    cout<<ans;
    
}