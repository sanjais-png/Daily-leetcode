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
    int count = 0;
    void rec(TreeNode* root , int targetSum ,long long sum){
        if(root == nullptr){return;}
        sum += root->val;
        if(targetSum == sum){
            count++;
        }
        
        rec(root->left , targetSum , sum);
        rec(root->right , targetSum , sum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){return 0;}
        rec(root , targetSum , 0);

        pathSum(root->left , targetSum);
        pathSum(root->right , targetSum);
        return count;
    }
};