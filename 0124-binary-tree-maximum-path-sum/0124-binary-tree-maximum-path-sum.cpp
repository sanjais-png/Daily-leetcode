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

    int maxSum = 0;
    int rec(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = max(rec(root->left), 0);
        int right =max(rec(root->right) , 0);
        maxSum = max(maxSum , left+right+root->val);
        return max(left,right)+root->val;
        
    }

    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        rec(root);
        return maxSum;
    }
};