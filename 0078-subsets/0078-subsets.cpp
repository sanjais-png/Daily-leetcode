class Solution {
public:
    vector<vector<int>>ans;
    void rec(vector<int>& nums ,vector<int>curr, int n , int index){
        if(index >= n){
            return;
        }
        vector<int>take = curr;
        take.push_back(nums[index]);
        ans.push_back(take);
        rec(nums , take , n , index+1);
        rec(nums , curr , n , index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        ans.push_back({});
        rec(nums , {} , n , 0);
        return ans;
    }
};