class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        int count1 = 0, count2 = 0;
        int x = 0;
        while(x < nums1.size()){
            if(nums1[x] & 1){
                count1++;
            }else{
                count2++;
            }
            x++;
        }
        if(count1 == nums1.size()){return true;}
        if(count2 == nums1.size()){return true;}
        for(int i = 0; i < nums1.size() ; i++){
                mini = min(nums1[i] , mini);
        }
        if(mini & 1){
            return true;
        }
        return false;
    }
};