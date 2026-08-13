class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int>freq;
        int ans = -1 , j = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
            while(freq[nums[i]] > k){
                freq[nums[j]]--;
                j++;
            }
            int count = i-j+1;
            cout<<count<<" ";
            ans = max(ans , count);
        }
        return ans;
    }
};