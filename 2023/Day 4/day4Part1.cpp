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
        // remove the card num : from each line
        int pos = line.find(":");
        line = line.substr(pos + 2);
        int points = 0;

        // store the number
        int num = 0;
        int i = 0;

        // loop through the winning numbers
        while(line[i] != '|')
        {
            // get the numbers
            string numS = "";

            while(line[i] != ' ')
            {
                numS += line[i];
                i++;
            }

            // store the winning numbers in the set
            if(numS != "")
            {
                num = stoi(numS);
                winning.insert(num);
            }

            while(line[i] == ' ')
                i++;

        }

        i += 2;

        // loop through my numbers in the line
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

                // find if number exist in the winning set
                if(winning.find(num) != winning.end())
                    points++;
            }

            while(line[i] == ' ')
                i++;

        }

        // calculate ans for each line
        ans += pow(2, points-1);

        winning.clear();

    }

    cout<<ans;

    return 0;
}