class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s(0),e(nums.size()),l(-1),r(-1);
        while(s<e){
            int mid=(s+e)/2;
            if(nums[mid]>=target) e=mid;
            else s=mid+1;
        }
        l=s;
        s=0,e=nums.size();
        while(s<e){
            int mid=(s+e)/2;
            if(nums[mid]>target) e=mid;
            else s=mid+1;
        }
        r=s;
        return l==r ? vector<int>{-1,-1}:vector<int>{l,r-1};
    }
};