class Solution {
public:

    vector<vector<int>>ans;
    void rec(vector<int>&candidates, vector<int>&curr ,int target , int index , int n , int sum){
        if(index >= n || sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        curr.push_back(candidates[index]);
        rec(candidates,curr,target,index,n,sum+candidates[index]);
        curr.pop_back();
        rec(candidates,curr,target,index+1,n,sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();   
        vector<int>temp;
        rec(candidates,temp,target,0,n,0);
        return ans; 
    }
};