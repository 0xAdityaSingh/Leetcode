class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            
            last[s[i]-'a']=i;
        }
        vector<int>ans;
        int j=0,k=0;
        for(int i=0;i<n;i++){
            j=max(j,last[s[i]-'a']);
            if(i==j){
                ans.push_back(j-k+1);
                k=i+1;
            }
        }
        return ans;
        
    }
};