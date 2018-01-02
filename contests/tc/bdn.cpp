#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
int donations[] =   { 1, 7, 9 };
int N = sizeof(donations)/ sizeof(donations[0]);
int dp[50];

int main(int argc, char const *argv[])
{

    memset(dp, 0, sizeof(dp));
    dp[0] = donations[0];

    for (int i = 2; i < N-1; ++i)
    {
        dp[i] = max(dp[i-2] + donations[i], dp[i-1]);
    }

    int ans1 = dp[N-2];

    memset(dp, 0, sizeof(dp));
    dp[1] = donations[1];

    for (int i = 2; i < N; ++i)
    {
        dp[i] = max(dp[i-2] + donations[i], dp[i-1]);
    }
    int ans2 = dp[N-1];

    cout << max(ans1, ans2);
    cout << endl;
    return 0;
}
