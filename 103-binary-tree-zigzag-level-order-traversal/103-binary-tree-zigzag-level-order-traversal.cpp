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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {        
        vector<vector<int>>outputArr;
        if(!root)return outputArr;
        vector<int>tempArr;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        int checkNum=0;
        while(!q1.empty()){
            TreeNode* node=q1.front();
            q1.pop();
            tempArr.push_back(node->val);
            if(node!=NULL and (node->left!=nullptr || node->right!=nullptr)){
                if(node->left!=nullptr){
                    q2.push(node->left);
                }
                if(node->right!=nullptr){
                    q2.push(node->right);
                }
            }
            if(q1.empty()){
                if(checkNum%2==0){
                    outputArr.push_back(tempArr);
                }
                else{
                    reverse(tempArr.begin(),tempArr.end());
                    outputArr.push_back(tempArr);
                }
                tempArr.clear();
                swap(q1,q2);
                checkNum++;
            }
        }
        return outputArr;
    }
};