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
    int ans=0;
    void sum(TreeNode* root,int par){
        if(!root) return;
        if(root->left==nullptr && root->right==nullptr){
            ans+=((par*10)+root->val);
            return;
        }
        par=(par*10)+root->val;
        sum(root->left,par);
        sum(root->right,par);
    }
    int sumNumbers(TreeNode* root) {
        sum(root,0);
        return ans;
    }
};
