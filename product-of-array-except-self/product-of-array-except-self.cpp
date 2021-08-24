class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long total=1,t_zero(1);
        int c=0,n=nums.size();
        for(int i=0;i<n;i++){
            total*=nums[i];
            if(nums[i]!=0){
                t_zero*=nums[i];
            }
            else c++;
        }
        vector<int> ans;
        if(c>1){
            vector<int> ans2(n,0);
            return ans2;
        }
        else if(c==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                ans.push_back(t_zero);
                }
                else{
                    ans.push_back(0);
                }
                
            }    
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(total/nums[i]);
            }
        }
        return ans;
        
    }
};