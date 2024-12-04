#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ifstream fin;
    string line;

    int ans = 0;

    fin.open("day3Input.txt");
 
    while (getline(fin, line)) 
    {
        bool safe = true;

        vector<int> a;

        int n = 0;
        int i = 0;

        string s = "mul(";
        string s1 = "do()";
        string s2 = "don't()";

        bool do_ = true;

        while(i < line.size())
        {

            //cout<<line[i]<<" "<<do_<<"\n";

            int k = i;
            int j = 0;
            int l = 0;
            int m = 0;

            while(line[k] == s2[m])
            {
                k++;
                m++;
            }

            k = i;

            while(line[k] == s1[l])
            {
                k++;
                l++;
            }

            k = i;

            while(line[k] == s[j])
            {
                k++;
                j++;
            }
    
            if(m == 7)
            {
                //cout<<"dont";
                do_ = false;
                i += 6;
            }

            if(l == 4)
            {
                //cout<<"Hello";
                do_ = true;
                i += 3;
            }

            if(j == 4)
            {
                i += 4;

                int n1 = 0;
                int n2 = 0;

                while(line[i] >= '0' && line[i] <= '9')
                {
                    n1 = n1*10 + line[i]-'0';
                    i++;
                }

                //cout<<n1<<" ";

                if(line[i] == ',')
                {
                    i++;
                }

                while(line[i] >= '0' && line[i] <= '9')
                {
                    n2 = n2*10 + line[i]-'0';
                    i++;
                }

                //cout<<n1<<" "<<n2;

                if(line[i] == ')')
                {
                    //cout<<"YES";
                    if(do_)
                    {
                        //cout<<"YES";
                        ans += n1*n2;
                    }
                }
            }

            i++;
        }

    }

    cout<<ans;
 
    fin.close();
    return 0;
}