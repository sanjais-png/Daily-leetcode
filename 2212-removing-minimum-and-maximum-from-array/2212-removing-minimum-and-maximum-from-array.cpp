class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minimum = INT_MAX , maximum = INT_MIN , minIndex = -1 , maxIndex = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(minimum > nums[i]){
                minimum = nums[i];
                minIndex = i;
            }
            if(maximum < nums[i]){
                maximum = nums[i];
                maxIndex = i;
            }
        }
        //cout<<maxIndex<<" "<<minIndex<<endl;
        int ans = INT_MAX;   
        if(minIndex > maxIndex){
            int temp = (maxIndex+1) + (nums.size()-minIndex);
            ans = min(ans , temp);
            //cout<<ans<<" ";
            ans = min(ans , minIndex+1);
            //cout<<ans<<" ";
            temp = nums.size() - maxIndex;
            ans = min(ans , temp);
        }
        if(maxIndex > minIndex){
            int temp = (minIndex+1) + (nums.size()-maxIndex);
            ans = min(ans , temp);
            //cout<<ans<<" ";
            ans = min(ans , maxIndex+1);
            //cout<<ans<<" ";
            temp = nums.size() - minIndex;
            ans = min(ans , temp);
        }
        if(ans == INT_MAX){return 1;}
        return ans;
    }
};