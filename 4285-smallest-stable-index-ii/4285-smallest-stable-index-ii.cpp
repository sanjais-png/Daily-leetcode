class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        int leftMax = INT_MIN, rightMin = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            leftMax = max(leftMax ,nums[i]);
            left[i] = leftMax;
        }   
        for(int  i = n-1 ; i >= 0 ; i--){
            rightMin = min(rightMin , nums[i]);
            right[i] = rightMin;
        }

        for(int i = 0 ; i < n ; i++){
            if(left[i] - right[i] <= k){
                return i;
            }
        } 
        return -1;
    }
};