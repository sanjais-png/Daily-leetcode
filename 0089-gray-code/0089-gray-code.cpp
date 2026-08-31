class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        long long size = pow(2,n);
        for(int i = 0 ; i < size; i++){
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};