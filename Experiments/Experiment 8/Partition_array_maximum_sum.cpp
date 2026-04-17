class Solution {
public:
    int solve(vector<int>& arr, int i, int k, vector<int>& dp) {
        if (i >= arr.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int maxElem = 0;
        int maxSum = 0;

        for (int len = 1; len <= k && i + len <= arr.size(); len++) {
            maxElem = max(maxElem, arr[i + len - 1]);
            int sum = maxElem * len + solve(arr, i + len, k, dp);
            maxSum = max(maxSum, sum);
        }

        return dp[i] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return solve(arr, 0, k, dp);
    }
};
