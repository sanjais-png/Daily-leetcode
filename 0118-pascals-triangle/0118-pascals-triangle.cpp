class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp(numRows);
        dp[0] = {1};
        if(numRows > 1){
        dp[1] = {1,1};
        }
        for(int i = 2 ; i < numRows ; i++){
            for(int j = 0 ; j <= i ; j++){
                if(j == 0 || j == i){
                    dp[i].push_back(1);
                }else{
                    dp[i].push_back(dp[i-1][j] + dp[i-1][j-1]);
                }
            }
        }
        return dp;
    }
};