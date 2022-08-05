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
    bool findPath(TreeNode* root, TreeNode* val,vector<TreeNode*>& vec){
        if(root==NULL) return false;
        vec.push_back(root);
        if(root==val) return true;
        else if(findPath(root->left,val,vec)||findPath(root->right,val,vec)) return true;
        vec.pop_back();
        return false;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pPath,qPath;
        findPath(root,p,pPath);
        findPath(root,q,qPath);
        TreeNode* ans;
        for(int i=0;i<min(pPath.size(),qPath.size());i++){
            if(pPath[i]==qPath[i]){
                ans=pPath[i];
            }
            else break;
        }
        return ans;
    }
};