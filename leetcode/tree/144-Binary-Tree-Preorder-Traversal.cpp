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

    // Root -> Left -> Right 

    vector<int> ans ;

    void recurse(TreeNode* node){
        if(node == NULL){
            return;
        }

        ans.push_back(node -> val);

        recurse(node->left);
        recurse(node->right);
    }


    vector<int> preorderTraversal(TreeNode* root) {
        recurse(root);
        return ans ;
    }
};