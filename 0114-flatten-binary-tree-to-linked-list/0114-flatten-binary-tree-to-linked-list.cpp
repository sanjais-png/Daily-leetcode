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
    vector<int>traverse;
    void preOrder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        traverse.push_back(root -> val);
        preOrder(root -> left);
        preOrder(root -> right);
    }
    void flatten(TreeNode* root) {
        if(root != nullptr){
            preOrder(root);
            TreeNode* temp = root;
            root->right = nullptr;
            root->left = nullptr;
            for(int i = 1 ; i < traverse.size() ; i++){
                root->right = new TreeNode(traverse[i]);
                root = root->right;
            }
            root = temp;
        }

    }
};