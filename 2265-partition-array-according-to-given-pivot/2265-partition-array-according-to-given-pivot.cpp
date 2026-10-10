class Solution {
public:

    void debug(vector<int>a){
        for(int i = 0 ; i < a.size() ; i++){
            cout<<a[i]<<" ";
        }
        cout << endl;
    }

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>smaller;
        vector<int>larger;
        vector<int>equal;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(nums[i] < pivot){
                smaller.push_back(nums[i]);
            }else if(nums[i] > pivot){
                larger.push_back(nums[i]);
            }else{
                equal.push_back(nums[i]);
            }
        }

        
        debug(smaller); debug(larger);
        int index = 0 , i = 0, x = 0, j = 0;
        
        while(i < smaller.size()){
            nums[index] = smaller[i];
            index++;
            i++;
        }

        while(x < equal.size()){
            nums[index] = equal[x];
            index++;
            x++;
        }

        while(j < larger.size()){
            nums[index] = larger[j];
            index++;
            j++;
        }
        return nums;
    }
};