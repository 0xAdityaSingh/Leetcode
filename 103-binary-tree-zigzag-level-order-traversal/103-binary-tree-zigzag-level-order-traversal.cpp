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
    
    void func(TreeNode* root, vector<vector<int>> &ans){
        if(!root) return;
        int evenorodd=0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        queue<TreeNode*> q1;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            temp.push_back(node->val);
            if(node!=NULL and (node->left!=nullptr || node->right!=nullptr)){
                if(node->left!=nullptr){
                    q1.push(node->left);
                }
                if(node->right!=nullptr){
                    q1.push(node->right);
                }
            }
            if(q.empty()){
                swap(q,q1);
                evenorodd++;
                if(evenorodd%2==0){
                    reverse(temp.begin(),temp.end());
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
        return;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        func(root,ans);
        return ans;
    }
};