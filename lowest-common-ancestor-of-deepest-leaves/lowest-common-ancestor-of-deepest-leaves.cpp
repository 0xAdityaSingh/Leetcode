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
    unordered_map<TreeNode*, int> mp;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return NULL;
        int l = countDepth(root->left);
        int r = countDepth(root->right);
        if(l == r)
            return root;
        else if(l < r)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
    
    int countDepth(TreeNode* root){
        if(!root)
            return 0;
        if(!mp.count(root))
            mp[root] = 1 + max(countDepth(root->left), countDepth(root->right));
        return mp[root];
    }
};