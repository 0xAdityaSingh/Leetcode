class Solution {
public:
    bool dfs(TreeNode* root,long long minNode, long long maxNode){
        if(!root) return true;
        if(root->val<=minNode || root->val>=maxNode){
            return false;
        }
        if(root==NULL || (root->left==nullptr && root->right==nullptr)){
            return true;
        }
        return (dfs(root->left,minNode,root->val) && dfs(root->right,root->val,maxNode));
        
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,LLONG_MIN,LLONG_MAX);
    }
};