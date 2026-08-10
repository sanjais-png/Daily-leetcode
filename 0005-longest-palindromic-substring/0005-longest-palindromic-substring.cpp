class Solution {
public:
    string longestPalindrome(string s) {
        
        string ans="";
        if(s==string(s.rbegin(),s.rend()))return s;
        for(int i=0;i<s.size();i++){
            for(int j=s.size()-1;j>=i;j--)
            {
                string sub="";
                if(s[i]==s[j]){
                    sub=s.substr(i,j-i+1);
                    string a=string(sub.rbegin(),sub.rend());
                    if(sub==a)
                    {
                        if(ans.size()<sub.size())
                        ans=sub;
                    }
                }
            }
        }
        if(ans.size()==0)ans=s[0];
        return ans;

    }
};