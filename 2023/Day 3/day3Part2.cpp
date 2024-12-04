#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int main()
{
    ifstream fin;
    string line;

    fin.open("day3Input.txt");

    vector<vector<char>> input;

    int ans = 0;

    // add the input to a 2d array
    while (getline(fin, line))
    {
        vector<char> temp;
        int i  = 0;

        // add this to the start and end to solve out of bounds error
        temp.push_back('.');

        while(i < line.length())
        {
            temp.push_back(line[i]);
            i++;
        }

        temp.push_back('.');

        input.push_back(temp);
    }

    // add two rows to the top and bottom to solve out of bounds error
    int len = input[0].size();

    vector<char> temp(len, '.');

    input.insert(input.begin(), temp);
    input.push_back(temp);

    // input2 array to store the numbers at each gear '*'
    vector<vector<vector<int>>> input2(input.size(), vector<vector<int>> (input[0].size()));

    // loop through the input
    for(int i = 1; i < input.size(); i++)
    {
        int j  = 1;
        int num = 0;
        string numS = "";

        while(j < input[i].size()-1)
        {
            // if current is not a digit go forward
            while(j < input[i].size() && !isdigit(input[i][j]))
                j++;

            // if a digit comes, calculate the number
            while(j < input[i].size() && isdigit(input[i][j]))
            {
                numS += input[i][j];
                j++;
            }

            // if there is a number in the entire row 
            if(numS != "")
            {
                num = stoi(numS);

                // get the left and right pointer of the number
                int left = j - numS.size() - 1;
                int right = j;

                bool AllGood = false;

                // loop through the adjancent indexes of the number
                for(int k = left; k <= right; k++)
                {
                    // if there is a gear at the number to array at the gear position
                    if(input[i-1][k] == '*')
                    {
                        input2[i-1][k].push_back(num);
                    }

                    if(input[i+1][k] == '*')
                    {
                        input2[i+1][k].push_back(num);
                    }
                }

                if(input[i][left] == '*')
                {
                    input2[i][left].push_back(num);
                }

                if(input[i][right] == '*')
                {
                    input2[i][right].push_back(num);
                }

                numS = "";
            }
        }
    }

    // check the number of numbers stored at each gear location
    for(int i = 0; i < input2.size(); i++)
    {
        for(int j = 0; j < input2[0].size(); j++)
        {
            // if 2 numbers are there, multiply and add to the answer
            if(input2[i][j].size() == 2)
            {
                ans += input2[i][j][0] * input2[i][j][1];
            }
        }
    }

    cout<<ans;

    return 0;
}