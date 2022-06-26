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
    
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>s;
        s.push(root);
        int tot=1,temp=0,ans=0;
        while(!s.empty()){
            int temp_ans=0;
            while(tot){
                TreeNode* node=s.front();
                s.pop();
                temp_ans+=node->val;
                tot--;
                if(node->left){
                    temp++;
                    s.push(node->left);
                }
                if(node->right){
                    temp++;
                    s.push(node->right);
                }
            }
            swap(temp,tot);
            ans=temp_ans;
        }
        return ans;
    }
};