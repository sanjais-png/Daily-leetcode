class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0 , high = matrix.size()-1;
        int l1 = -1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(matrix[mid][0] <= target){
                if(matrix[mid][0] == target){return true;}
                l1 = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        if(l1 == -1){return false;}
        low = 0 , high = matrix[l1].size()-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(matrix[l1][mid] == target){return true;}
            else if(matrix[l1][mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};