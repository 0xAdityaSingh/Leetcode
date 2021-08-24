class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        vector<bool> vis(nums.size()+1,false);
        for(auto it:nums){
            vis[it]=true;
        }
        for(int i=1;i<vis.size();i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};