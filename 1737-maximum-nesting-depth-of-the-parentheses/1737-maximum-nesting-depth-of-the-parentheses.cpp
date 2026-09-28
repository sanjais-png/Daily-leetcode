class Solution {
public:
    int maxDepth(string s) {
        int current = 0 , maxi = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '(') {
                current++;
                maxi = max(maxi, current);
            } else if (s[i] == ')') {
                current--;
            }
        }
        return maxi;
    }
};
