class Solution {
public:
    void ps(TreeNode* root, int sum, vector<int> path, vector<vector<int>> &res){
        if (!root){
            return;
        }else{
            path.push_back(root->val);
            if (!root->left && !root->right && sum==root->val){
                res.push_back(path);
                path.clear();
            }
            ps(root->left, sum - root->val, path, res);
            ps(root->right, sum - root->val, path, res);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int>path;
        ps(root, sum, path, res);
        return res;
    }
};
