class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> c;
        int right=0,left=0;
        int maxlen=0;
        while(right<s.length())
        {
            auto it=find(c.begin(),c.end(),s[right]);
            if(it==c.end())
            {
                c.push_back(s[right]);
                maxlen=max(maxlen,right-left+1);
                right++;
            }
            else
            {
                c.erase(c.begin());
                left++;
            }
        }
        return maxlen;
    }
};