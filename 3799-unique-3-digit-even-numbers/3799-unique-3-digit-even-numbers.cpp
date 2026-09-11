class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> combinations;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j) {
                            int val = (digits[i]*100)+(digits[j]*10)+digits[k];
                            if (val % 2 == 0 && digits[i] != 0) {
                                combinations.insert(val);
                            }
                        }
                    }
                }
            }
        }
        return combinations.size();
    }
};