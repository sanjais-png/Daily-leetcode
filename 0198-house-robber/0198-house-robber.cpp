class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, prev1 = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int curr = max(prev1 , prev + nums[i]);
            prev = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};