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

    // loop through the input
    for(int i = 1; i < input.size()-1; i++)
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

                // to check if there is any other element that '.'
                bool AllGood = false;

                // loop through the adjancent indexes of the number
                for(int k = left; k <= right; k++)
                {
                    if(input[i-1][k] != '.')
                    {
                        AllGood = true;
                        break;
                    }

                    if(input[i+1][k] != '.')
                    {
                        AllGood = true;
                        break;
                    }

                    if(input[i][left] != '.')
                    {
                        AllGood = true;
                        break;
                    }

                    if(input[i][right] != '.')
                    {
                        AllGood = true;
                        break;
                    }
                }

                // if any other element exist than '.' add the num to the answer
                if(AllGood)
                {
                    ans += num;
                }

                // reset the number
                numS = "";
            }
        }
    }

    cout<<ans;

    return 0;
}