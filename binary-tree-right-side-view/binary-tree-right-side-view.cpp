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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> curr,pre;
        vector<int> ans;
        curr.push(root);
        while(!curr.empty()){
            while(!curr.empty()){
                TreeNode *temp=curr.front();
                curr.pop();
                if(temp!=nullptr && curr.size()==0){
                    ans.push_back(temp->val);
                }
                if(temp!=nullptr && temp->left!=nullptr){
                    pre.push(temp->left);
                }
                if(temp!=nullptr && temp->right!=nullptr){
                    pre.push(temp->right);
                }
            }
            swap(pre,curr);
        }
        
        return ans;
    }
};