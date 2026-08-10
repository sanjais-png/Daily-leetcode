class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int t=0;
            t=target-nums[i];
            if(m.find(t)!=m.end()){
                return {m[t],i};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};