class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; i++) {
            int curr = max(dp[i], dp[i - 1] + nums[i]);
            dp[i+1] = curr;
        }
        return dp[n];
    }
};