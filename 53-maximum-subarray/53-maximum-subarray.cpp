class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans(INT_MIN), curr(0);
        for(auto num:nums){
            curr+=num;
            ans=max(ans,curr);
            if(curr < 0) curr=0;   
        }
        return ans;
    }
};