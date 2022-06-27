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
    int sum=0;
    void dfs(TreeNode* curr,TreeNode* par, TreeNode* gpar){
        if(!curr) return;
        if(gpar!=nullptr and gpar->val%2==0){
            sum+=curr->val;
        }
        dfs(curr->left,curr,par);
        dfs(curr->right,curr,par);
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root,nullptr,nullptr);
        return sum;
    }
};