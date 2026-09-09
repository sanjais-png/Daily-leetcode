class Solution {
public:

    string lcs(string s , string t){
        int n = s.size() , m = t.size();
        if(n == 0 || m == 0){
            return "";
        }
        vector<vector<int>>dp(n+1 , vector<int>(m+1,0));
        int end = 0 , maxLen = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(n-j == i-dp[i][j] && maxLen < dp[i][j]){
                        maxLen = dp[i][j];
                        end = i;
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        int start = end - maxLen;
        return s.substr(start,maxLen);
    }

    string longestPalindrome(string s) {
        string rev = string(s.rbegin() , s.rend());
        return lcs(s,rev);
    }
};