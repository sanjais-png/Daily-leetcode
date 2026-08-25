class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>arr;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % k == 0){
                arr.insert(nums[i]);
            }
        }

        if(arr.size() == 0){
            return k;
        }
        int add = k;
        bool flag = true;
        for(auto i : arr){
            if(flag){
                if(i != k){
                    return k;
                }
                flag = false;
                continue;
            }
            if(i != k+add){
                return k+add;
            }

            k += add;
            cout<<k;
        }

        return k+add;
    }
};