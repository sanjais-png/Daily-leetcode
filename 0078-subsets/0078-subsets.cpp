class Solution {
public:
    vector<vector<int>>ans;
    void rec(vector<int>& nums ,vector<int>&curr, int n , int index){
        if(index == n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        rec(nums , curr , n , index+1);
        curr.pop_back();
        rec(nums , curr , n , index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        rec(nums , curr , n , 0);
        return ans;
    }
};