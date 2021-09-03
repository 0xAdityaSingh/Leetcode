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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        queue<TreeNode*> curr,temp;
        curr.push(root);
        while(!curr.empty()){
            vector<int> inner_vec;
            while(!curr.empty()){
                TreeNode* num=curr.front();
                if(num!=nullptr)
                    inner_vec.push_back(num->val);
                curr.pop();
                if(num!=nullptr && num->left!=nullptr){
                    temp.push(num->left);
                }
                if(num!=nullptr && num->right!=nullptr){
                    temp.push(num->right);
                }
            }
            if(inner_vec.size()>0)
                vec.push_back(inner_vec);
            swap(temp,curr);
        }
        return vec;
    }
};