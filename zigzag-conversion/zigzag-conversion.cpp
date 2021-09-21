class Solution {
public:
    string convert(string s, int n) {
        vector<vector<char>>vec(n);
        cout<<s.size()<<endl;
        for(int i=0;i<s.size();){
            
            for(int j=0;j<n;j++){
                if(i>=s.size()) break;
                if(s[i]>='A'|| s[i]<='Z')
                {    vec[j].push_back(s[i]);
                // cout<<s[i]<<" "<<"s[i]" <<endl;
                }
                
                i++;
            }
            for(int j=n-2;j>0;j--){
                if(i>=s.size()) break;
                if(s[i]>='A'|| s[i]<='Z'){
                    vec[j].push_back(s[i]);
                // cout<<s[i]<<" "<<"diag[i]" <<endl; 
                }
                    
                i++;
            }
        }
        string ans="";
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size();j++){               
                    ans+=vec[i][j];
            }
        }
        return ans;
    }
};