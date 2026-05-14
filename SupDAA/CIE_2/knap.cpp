#include<iostream>
using namespace std;

int main()
{
    int wt[] = {3,5,6,2};
    int val[] = {10,4,9,11};
    int W = 7;
    int n = 4;

    int dp[n+1][W+1];

    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(wt[i-1] <= w)
            {
                int include = val[i-1] + dp[i-1][w-wt[i-1]];
                int exclude = dp[i-1][w];

                if(include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Maximum Profit = " << dp[n][W];

    return 0;
}