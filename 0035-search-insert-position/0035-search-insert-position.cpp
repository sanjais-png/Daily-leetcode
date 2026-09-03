class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target){
                if(target == nums[mid]){return mid;}
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(ans == -1){
            if(target > nums[nums.size()-1]){return nums.size();}
            else{return 0;}
        }
        return ans;
    }
};