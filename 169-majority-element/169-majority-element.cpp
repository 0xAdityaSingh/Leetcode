class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans=nums[0],maxx=0;
        for(auto it:mp){
            if(maxx<it.second){
                maxx=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};