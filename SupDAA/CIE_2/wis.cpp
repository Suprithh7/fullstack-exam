#include<iostream>
using namespace std;

struct Job
{
    int start, finish, value;
};

int main()
{
    Job jobs[] = {
        {1,2,100},
        {2,5,200},
        {3,6,300},
        {4,8,400},
        {5,9,500},
        {6,10,100}
    };

    int n = 6;
    int dp[6];

    dp[0] = jobs[0].value;

    for(int i=1;i<n;i++)
    {
        int include = jobs[i].value;

        for(int j=i-1;j>=0;j--)
        {
            if(jobs[j].finish <= jobs[i].start)
            {
                include += dp[j];
                break;
            }
        }

        if(include > dp[i-1])
            dp[i] = include;
        else
            dp[i] = dp[i-1];
    }

    cout << "Maximum Profit = " << dp[n-1];

    return 0;
}