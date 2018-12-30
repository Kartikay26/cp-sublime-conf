#include <bits/stdc++.h>
using namespace std;

int maxSubsetSum(vector<int> arr) {
    int n = arr.size();
    int dp[n];
    dp[0] = max(0,arr[0]);
    dp[1] = max(0,max(arr[0],arr[1]));
    for(int i = 2; i < n; i++){
        dp[i] = max(arr[i], max(dp[i-2]+arr[i], dp[i-1]));
    }
    return dp[n-1];
}

int maxSubsetSum_2(vector<int> arr) {
    int n = arr.size();
    int dp[n][2];
    // dp[i][0] -- not taken, dp[i][1] -- taken
    dp[0][1] = arr[0]; dp[0][0] = 0;
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + arr[i];
    }
    return max(dp[n-1][0], dp[n-1][1]);
}

