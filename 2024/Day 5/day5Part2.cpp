#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

int main()
{
    ifstream fin;
    string line;

    int ans = 0;

    fin.open("day5Input1.txt");

    unordered_map<int, vector<int>> after;
    unordered_map<int, vector<int>> before;
 
    while (getline(fin, line)) 
    {
        int i = 0;
        int n1 = 0;
        int n2 = 0;

        while(line[i] != '|')
        {
            n1 = n1*10 + line[i]-'0';
            i++;
        }

        i++;

        while(i < line.size())
        {
            n2 = n2*10 + line[i]-'0';
            i++;
        }

        after[n1].push_back(n2);
        before[n2].push_back(n1);
    }

//     for (auto it = before.begin(); it != before.end(); it++) {
//     cout << "Key: " << it->first << " Values: ";
//     for (int value : it->second) {
//         cout << value << " ";
//     }
//     cout << endl;
// }

fin.close();

    fin.open("day5Input2.txt");

    while (getline(fin, line)) 
    {
        unordered_map<int, int> updatesMP;
        vector<int> updates;

        int i = 0;
        int index = 0;

        while(i < line.size())
        {
            int n1 = 0;

            while(i < line.size() && line[i] != ',')
            {
                n1 = n1*10 + line[i]-'0';
                i++;
            }

            i++;

            updatesMP[n1] = index;
            index++;

            updates.push_back(n1);
        }

        bool not_ = true;

        i = 0;

        while(i < updates.size())
        {
            int j = 0;
            bool change = true;

            while(j < before[updates[i]].size())
            {
                //cout<<updates[updatesMP[before[updates[i]][j]]]<<" ";

                if(updatesMP.find(before[updates[i]][j]) != updatesMP.end())
                {
                    if(i < updatesMP[before[updates[i]][j]])
                    {
                        int v = before[updates[i]][j];
                        swap(updates[i], updates[updatesMP[before[updates[i]][j]]]);
                        updatesMP[v] = i;
                        not_ = false;
                        change = false;
                        break;
                    }
                }

                j++;
            }

            j = 0;

            while(j < after[updates[i]].size())
            {
                if(updatesMP.find(after[updates[i]][j]) != updatesMP.end())
                {
                    if(i > updatesMP[after[updates[i]][j]])
                    {
                        int v = after[updates[i]][j];
                        swap(updates[i], updates[updatesMP[after[updates[i]][j]]]);
                        updatesMP[v] = i;
                        not_ = false;
                        change = false;
                        break;
                    }
                }

                j++;
            }

            if(change)
            {
                i++;
            }

            //cout<<k<<"-"<<i<<" ";
        }

        if(!not_)
        {
            ans += updates[updates.size()/2];
        }

    }

    cout<<ans;
 
    fin.close();
    return 0;
}