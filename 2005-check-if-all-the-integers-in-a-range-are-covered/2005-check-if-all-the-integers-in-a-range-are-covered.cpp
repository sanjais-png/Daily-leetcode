class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {


        for(int k = left ; k <= right ; k++){
            bool flag = false;
            for(int i = 0 ; i < ranges.size() ; i++){
                if(ranges[i][0] <= k && ranges[i][1] >= k){
                    flag = true;
                }
            }
            if(!flag){
                return false;
            }
        }
        return true;
    }
};