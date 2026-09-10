class Solution {
public:
    int climbStairs(int n) {
        vector<int> fact(n+1, 0);
        fact[0] = 1;
        fact[1] = 1;
        for(int  i = 2 ; i <= n ; i++){
            fact[i] = fact[i-1] + fact[i-2];
        }
        return fact[n];
    }
};