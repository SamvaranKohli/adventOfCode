#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>

using namespace std;

int main()
{
    ifstream fin;
    string line;

    int ans = 0;

    fin.open("sample.txt");

    unordered_map<string, int> mp;

    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
    mp["four"] = 4;
    mp["five"] = 5;
    mp["six"] = 6;
    mp["seven"] = 7;
    mp["eight"] = 8;
    mp["nine"] = 9;

    int g = 1;
 
    while (getline(fin, line)) 
    {
        int s, e;
        
        int j = 0;
        bool foundS = false;
        bool foundE = false;

        string s2 = "";

        for(int i = 0; i < line.length(); i++)
        {
            s2 += line[i];

            if(isdigit(line[i]))
            {
                s = line[i] - '0';
                s *= 10;
                break;
            }
            else
            {
                bool didNotFindAtAll = true;

                while(s2 != "")
                {
                    didNotFindAtAll = true;

                    for(auto it = mp.begin(); it != mp.end(); it++)
                    {
                        string temp = s2;

                        if (it->first.find(temp) != string::npos) 
                        {
                            didNotFindAtAll = false;

                            if(it->first == temp)
                            {
                                s = it->second*10;
                                foundS = true;
                                s2 = "";
                            }

                            s2 = temp;

                            break;
                        }

                    }

                    if(!didNotFindAtAll)
                        break;
                    else
                    {
                        s2.erase(0, 1);
                    }
                }

                if(foundS)
                    break;
            }
        }

        s2 = "";

        for(int i = line.length(); i >= 0; i--)
        {
            s2 += line[i];

            if(isdigit(line[i]))
            {
                e = line[i] - '0';
                break;
            }
            else
            {

                bool didNotFindAtAll = true;

                while(s2 != "")
                {
                    didNotFindAtAll = true;

                    for(auto it = mp.begin(); it != mp.end(); it++)
                    {
                        string temp = s2;
                        reverse(temp.begin(), temp.end());

                        if (it->first.find(temp) != string::npos) 
                        {
                            didNotFindAtAll = false;

                            if(it->first == temp)
                            {
                                e = it->second;
                                foundE = true;
                                s2 = "";
                            }

                            reverse(temp.begin(), temp.end());
                            s2 = temp;

                            break;
                        }

                    }

                    if(!didNotFindAtAll)
                        break;
                    else
                    {
                        s2.erase(0, 1);
                    }
                }

                if(foundE)
                    break;
            }
        }

        ans += s+e;
        cout<<g<<" "<<s+e<<"\n";
        g++;
    }

    cout<<ans;
 
    fin.close();
    return 0;
}