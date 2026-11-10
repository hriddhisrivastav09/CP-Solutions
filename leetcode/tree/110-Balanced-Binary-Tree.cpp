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
    bool isBal = true ;
    int height(TreeNode* root){
        if(!root){
            return 0 ;
        }

        int h_left = height(root->left);
        int h_right = height(root->right);

        if(abs(h_left - h_right) > 1){
            isBal = false ;
        }

        return 1 + max(h_left,h_right);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return isBal;
    }
};