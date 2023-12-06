#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>

using namespace std;

void mapValues(vector<vector<long long int>> values, vector<long long int> &seeds)
{
    // loop through all the seeds
    for(int k = 0; k < seeds.size(); k++)
    {
        // loop through all the mapping values
        for(int i = 0; i < values.size(); i++)
        { 
            // get the source, destination and count at each line
            long long int source = values[i][1];
            long long int destination = values[i][0];
            long long int count = values[i][2];

            // if that seed can exist from [source - source+count]
            // then map it and get out
            if(seeds[k] >= source && seeds[k] <= source+count)
            {
                seeds[k] = destination + (seeds[k] - source);
                break;
            }

        }
    }
}

int main()
{
    ifstream fin;
    string line;

    fin.open("day5Input.txt");

    vector<vector<long long int>> values;

    // seeds input
    vector<long long int> seeds = {763445965, 78570222, 1693788857, 146680070, 1157620425, 535920936, 3187993807, 180072493, 1047354752, 20193861, 2130924847, 274042257, 20816377, 596708258, 950268560, 11451287, 3503767450, 182465951, 3760349291, 265669041};

    // loop through and get the mapping values
    while (getline(fin, line))
    {
        if(line == "")
            continue;

        if (line.find("seeds:") != string::npos) 
        {   
            continue;
        }

        if(line == "seed-to-soil map:")
            continue;
            
        // means new mapping is about to start and calculate the result for the current stored mapping
        if(line == "soil-to-fertilizer map:" || line == "fertilizer-to-water map:" || line == "water-to-light map:" || 
            line == "light-to-temperature map:" || line == "temperature-to-humidity map:" || line == "humidity-to-location map:")
        {
            mapValues(values, seeds);
            values.clear();
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

    mapValues(values, seeds);

    long long int ans = LLONG_MAX;

    // calculate the minimum value from all the seeds
    for(long long int i = 0; i < seeds.size(); i++)
    {
        ans = min(ans, seeds[i]);
    }

    cout<<ans;
}