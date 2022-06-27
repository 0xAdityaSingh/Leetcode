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
    void func(TreeNode* node, int &c){
        if(!node) return;
        func(node->right,c);
        node->val+=c;
        c=node->val;
        func(node->left,c);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int c=0;
        func(root,c);
        return root;
    }
};