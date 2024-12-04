#include <iostream>
#include<vector>
using namespace std;

// logic is same as part 1

int main() {
    
    long long int time = 44707080;
    long long int distance = 283113411341491;
    
    long long int ans = 0;
    
    for(long long int i = 0; i <= time; i++)
    {
        long long int speed = i;
        long long int timeleft = time-i;
        
        long long int dis = speed*timeleft;
        
        if(dis > distance)
            ans++;
    }

    cout<<ans;
    
    return 0;
}