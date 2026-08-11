class Solution {
public:
    bool check(long long mid , vector<int>&weights , int days){
        long long sum = 0 , count = 0;
        for(int i = 0 ; i < weights.size() ; i++){
            sum += weights[i];
            if(sum == mid){
                count +=  1;
                sum = 0;
            }else if(sum > mid){
                count += 1;
                sum = weights[i];
            }
        }
        if(sum != 0)count+=1;
        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long sum = 0 ;
        int low = INT_MIN;
        for(int i = 0 ; i < weights.size() ; i++){
            sum += weights[i];
            low = max(low,weights[i]);
        }
        if(days == 1)return sum;
        long long high = sum , ans = -1;
        while(low <= high){
            long long mid = (low + high)/2;
            if(check(mid , weights , days)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};