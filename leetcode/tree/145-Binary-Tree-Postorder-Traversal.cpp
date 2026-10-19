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

    // Left -> Right -> Root ;

    vector<int> ans ;

    void recurse(TreeNode* node){
        if(node == NULL){
            return;
        }

        recurse(node->left);
        recurse(node->right);
        ans.push_back(node->val);
    }


    vector<int> postorderTraversal(TreeNode* root) {
        recurse(root);
        return ans;
    }
};