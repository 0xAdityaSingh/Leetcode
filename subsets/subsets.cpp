class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> distinctSubsets;
        int N = nums.size(), total = pow(2,N);
        for(int i=0; i<total; i++){
            vector<int>SET;
            for(int j=0; j<N; j++){
                if(1 & (i>>j)){       
                    SET.push_back(nums[j]);
                }
            }   
            distinctSubsets.insert(SET);
        }
        return vector<vector<int>>(distinctSubsets.begin(),distinctSubsets.end());
    }
};