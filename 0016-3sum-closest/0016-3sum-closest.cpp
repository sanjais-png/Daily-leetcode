class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX ,deviation = INT_MAX;
        for(int x = 0; x <= nums.size() - 2; x++) {
            int i = x + 1, j = nums.size() - 1;
            while(i < j) {
                int sum = nums[x] + nums[i] + nums[j];
                int current = abs(sum - target);
                if(deviation > current){
                    ans = sum;
                    deviation = current;
                }
                if(sum >= target) {
                    j--;
                }else {
                    i++;
                }
            }
        }
        return ans;
    }
};