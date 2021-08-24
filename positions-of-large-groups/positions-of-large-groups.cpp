class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int f(0),e(0),n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) e++;
            else{
                if(e-f>=2){
                    ans.push_back({f,e});
                }
                f=i;
                e=i;
            }
        }
        if(e-f>=2) ans.push_back({f,e});
        return ans;
    }
};