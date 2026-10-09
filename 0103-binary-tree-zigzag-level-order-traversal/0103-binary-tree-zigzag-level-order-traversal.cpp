/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void reverseLevel(vector<int>& current){
        int i = 0 , j = current.size()-1;

        while(i < j){
            int temp = current[i];
            current[i] = current[j];
            current[j] = temp;
            i++; j--;
        }

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        queue<TreeNode*>q;
        vector<vector<int>>ans;

        q.push(root);
        bool level = false;
        while(!q.empty()){
            int size = q.size();
            vector<int>current;

            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();
                current.push_back(node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                }

                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            if(level){
                reverseLevel(current);
                level = false;
            }else{
                level = true;
            }

            ans.push_back(current);

        }
        return ans;
    }
};