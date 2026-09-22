class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0 ; i < s.size() ; i++){
            int b = s[i];
            int a = 'z';
            sum += ((a - b)+1)*(i+1);
            cout << a <<" "<< b <<a-b<<" "<<endl;
        }
        return sum;
    }
};