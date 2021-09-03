/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getpath(TreeNode* root,vector<TreeNode*> &vec, TreeNode* x){
        if(root==nullptr) return false;
        vec.push_back(root);
        if(root->val==x->val) return true;
        if(getpath(root->left,vec,x)||getpath(root->right,vec,x)) return true;
        vec.pop_back();
        return false;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p,path_q;
        getpath(root,path_p,p);
        getpath(root,path_q,q);
        TreeNode* ans;
        for(int i=0;i<min(path_p.size(),path_q.size());i++){
            if(path_p[i]->val==path_q[i]->val) ans=path_p[i];
        }
        return ans;
    }
};