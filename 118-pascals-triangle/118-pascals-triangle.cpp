class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(n==1) return ans;
        ans.push_back({1,1});
        if(n==2) return ans;
        int idx=3;
        while(idx<=n){
            vector<int>temp= ans.back();
            vector<int>temp2;
            for(int i=0;i<=temp.size();i++){
                if(i==0 || i==temp.size()) temp2.push_back(1);
                else{
                    temp2.push_back(temp[i-1]+temp[i]);
                }
            }
            ans.push_back(temp2);
            idx++;
        }
        return ans;
    }
};