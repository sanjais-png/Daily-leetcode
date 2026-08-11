class Solution {
public:
    int missingInteger(vector<int>& nums) {

        if(nums.size() == 1){return nums[0]+1;}

        vector<int>sequence;
        int temp = nums[0];
        int sum = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]-1 == temp){
                sum += nums[i];
                temp = nums[i];
            }else{
                break;
            }
        }

        int ans = -1;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == sum){
                sum += 1;
                ans = nums[i];
            }
        }
        if(ans != -1){
            return ans+1;
        }return sum;
    }
};