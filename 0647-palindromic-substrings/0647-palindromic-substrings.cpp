class Solution {
public:

    
    int rec(string s , int i , int j , vector<vector<int>>&dp){
        if(i == j){
            return 1;
        }
        if(j == i+1 && s[i] == s[j]){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        dp[i][j] = (s[i] == s[j] && rec(s,i+1,j-1,dp));
        return dp[i][j];
    }

    int countSubstrings(string s) {
        int count = 0;
        vector<vector<int>>dp(s.size() , vector<int>(s.size(),-1));
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = i+1 ; j < s.size() ; j++){
                if(rec(s , i , j , dp)){
                    count++;
                }
            }
        }
        return count + s.size();
    }
};