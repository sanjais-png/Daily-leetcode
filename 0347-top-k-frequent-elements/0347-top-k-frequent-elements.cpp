class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>frequency(mp.begin() , mp.end());
        sort(frequency.begin() , frequency.end() , [](const auto &a, const auto &b){
            return a.second > b.second;
        });

        vector<int>ans;
        for(auto& i : frequency){
            if(k == 0){break;}
            ans.push_back(i.first);
            k--;
        }
        return ans;
    }
};