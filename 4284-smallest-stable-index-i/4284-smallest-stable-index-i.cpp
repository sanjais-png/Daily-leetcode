class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n); 
        int curMax = INT_MIN , curMin = INT_MAX;
        for(int  i = 0 ; i < n ; i++){
            curMax = max(curMax , nums[i]);
            left[i] = curMax;
        }
        for(int i = n-1 ; i >= 0 ; i--){
            curMin = min(curMin , nums[i]);
            right[i] = curMin;
        }
        for(int i = 0 ; i < n ; i++){
            if((left[i] - right[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};