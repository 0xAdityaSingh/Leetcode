class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s(0),e(0);
        while(s<nums.size() && e<nums.size()){
            if(s==e and nums[s]!=0){
                s++;
                e++;}
            else if(s==e) e++;
            else if(nums[e]!=0 and nums[s]==0){
                swap(nums[s],nums[e]);
                    s++;e++;
            }
            else if(nums[s]!=0 and nums[e]!=0){
                s++;
            }
            else if(nums[s]!=0 and nums[e]==0){
                s++;
                e++;
            }
            else{e++;}
        }
    }
};