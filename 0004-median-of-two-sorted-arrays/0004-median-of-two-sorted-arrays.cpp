class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        int m=nums1.size();
        int n=nums2.size();
        vector<int>nums3;
        for(int i=0;i<m;i++)
        {
            nums3.push_back(nums1[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            nums3.push_back(nums2[i]);
        }
        sort(nums3.begin(),nums3.end());
        int median=nums3.size();
        if(median%2==0)
        {
            ans=(nums3[median/2]+nums3[median/2-1])/2.00;
        }
        else
        {
            ans=nums3[median/2];
        }
        return ans;
    }
};