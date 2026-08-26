class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count = INT_MAX;
        string ans ="";
        int a = -1, b = -1;
        int j = 0 , current = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                current++;
            }
            while(current == k){
                int current_len = i - j + 1;
                if(count > current_len){
                    ans = s.substr(j, current_len);
                    count = current_len;
                } 
                else if(count == current_len){
                    string temp = s.substr(j, current_len);
                    if(temp < ans){
                        ans = temp;
                    }
                }
                
                if(s[j] == '1'){
                    current--;
                }
                j++;
            }
        }
        return ans;
    }
};