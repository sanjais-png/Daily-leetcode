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
    int count = 0 , ans = 0 , sum = 0;
    int traversal(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        traversal(root->left);
        sum += root->val; count += 1;
        traversal(root->right);
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr){return 0;}
        count = 0 , sum = 0;
        traversal(root);

        if(sum / count == root->val){
            ans++;
        }

        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return ans;

    }
};