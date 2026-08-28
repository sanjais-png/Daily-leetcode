class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while(n > 0){
            if(prev == (n&1)){
                return false;
            }
            if(n & 1){
                prev = 1;
            }else{
                prev = 0;
            }
            n = n >> 1;
        }
        return true;
    }
};