class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=1,mmax=nums[0],mmin=nums[0];i<n;i++){
            if(nums[i]<0){
                swap(mmax,mmin);
            }
            mmax=max(nums[i],mmax*nums[i]);
            mmin=min(nums[i],mmin*nums[i]);
            
            ans=max(ans,mmax);
        }
        return ans;
    }
};