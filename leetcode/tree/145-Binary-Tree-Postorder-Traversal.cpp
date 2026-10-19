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

    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st_node;
        stack<int> st_order;
        vector<int>ans;

        if(root == NULL){
            return ans;
        }
        st_node.push(root);

        while(!st_node.empty()){
            TreeNode* node = st_node.top();
            st_order.push(node->val);

            st_node.pop();
            if(node->left!=NULL){
                st_node.push(node->left);
            }
            if(node->right!=NULL){
                st_node.push(node->right);
            }
        }

        while(!st_order.empty()){
            ans.push_back(st_order.top());
            st_order.pop();
        }

        return ans;
    }
};