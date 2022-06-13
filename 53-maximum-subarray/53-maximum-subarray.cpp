class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans(INT_MIN), curr(0);
        for(auto num:nums){
            curr+=num;
            if(curr < 0) curr=0;
            ans=max(ans,curr);
        }
        int maxnum=INT_MIN;
        for(auto num:nums){
            maxnum=max(maxnum,num);
        }
        if(maxnum<0) return maxnum;
        return ans;
    }
};