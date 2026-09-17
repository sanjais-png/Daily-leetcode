class Solution {
public:
    string sortSentence(string s) {
        int cur = 1;
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            int x = s[i] - '0';
            if(x == cur){
                int j = i-1;
                cur++;
                string temp;
                while(j >= 0 && s[j] != ' '){
                    string a = "";
                    a += s[j];
                    a += temp;
                    temp = a;
                    j--;
                }
                ans += temp;
                ans += " ";
                i = 0;
            }
        }
        return ans.substr(0,ans.size()-1);
    }
};