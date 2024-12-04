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

    // store the number of cards for each card
    vector<int> totalCards(212, 1);

    int currLine = 0;

    while (getline(fin, line)) 
    {
        int pos = line.find(":");
        line = line.substr(pos + 2);
        int points = 0;

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

        // loop through the number of cards depending upon the numbe of points
        for(int j = 1; j <= points; j++)
        {
            // add the current number of cards to the next n (points) cards
            totalCards[currLine+j] += totalCards[currLine];
        }

        winning.clear();
        currLine++;

    }

    // get the total number of cards
    for(int i = 0; i < totalCards.size(); i++)
    {
        ans += totalCards[i];
    }

    cout<<ans;

    return 0;
}