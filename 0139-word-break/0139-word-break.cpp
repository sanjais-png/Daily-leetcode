class Solution {
public:

    class Trie{
        public:
        vector<Trie*>children;
        bool isEnd;

        Trie():
            children(26,nullptr),isEnd(false){}

        void insert(string s){
            Trie* a = this;
            for(int i = 0 ; i < s.size() ; i++){
                int index = s[i] - 'a';
                if(a->children[index] == nullptr){
                    a->children[index] = new Trie();
                }
                a = a->children[index];
            }
            a->isEnd = true;
        }
    };
    Trie root;
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie a;
        for(int i = 0 ; i < wordDict.size() ; i++){
            a.insert(wordDict[i]);
        }

        vector<bool>dp(s.size()+1 , false);
        dp[0] = true;
        for(int i = 0 ; i < s.size() ; i++){
            if(!dp[i]){
                continue;
            }

            Trie* current = &a;
            for(int j = i ; j < s.size() ; j++){
                int index = s[j] - 'a';
                if(current->children[index] == nullptr){
                    break;
                }
                current = current->children[index];
                if(current->isEnd){
                    dp[j+1] = true;
                }
            }
        }
        return dp[s.size()];
    }
};