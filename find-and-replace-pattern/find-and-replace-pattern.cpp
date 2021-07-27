class Solution {
public:
    bool issame(string s1,string s2){
        if(s1.size()!=s2.size()) return false;
        unordered_map<char,char>mp;
        vector<bool>vis(26,false);
        int n=s1.size();
        for(int i=0;i<n;i++){
            char c1=s1[i],c2=s2[i];
            if(mp[c1] && mp[c1]!=c2) return false;
            if(!mp[c1] && vis[c2-'a']) return false;
            mp[c1]=c2;
            vis[c2-'a']=true;
            
        }
        return true;
        
    }
    vector<string> findAndReplacePattern(vector<string>& v, string p) {
        vector<string>ans;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(issame(v[i],p)){
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};