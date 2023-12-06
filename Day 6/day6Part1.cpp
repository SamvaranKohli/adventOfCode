#include <iostream>
#include<vector>
using namespace std;

int main() {
    
    vector<int> time = {44, 70, 70, 80};
    vector<int> distance = {283, 1134, 1134, 1491};
    
    long long int ans = 1;

    // loop through all the races [time]
    for(int i = 0; i < time.size(); i++)
    {
        // number of ways to win for each race
        int ways = 0;

        // loop through all the recharge times
        for(int j = 0; j <= time[i]; j++)
        {
            // get the speed = recharge time and timeleft = time left for the race
            long long int speed = j;
            long long int timeleft = time[i]-j;

            // caluclate the distance it can travel
            long long int dis = speed*timeleft;

            // check if record can be broken
            if(dis > distance[i])
                ways++;
        }

        // multiply all the ways together
        ans *= ways;
        
    }

    cout<<ans;
    
    return 0;
}