class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        bool flag=false;
        if(n==1){
            return s[0];
        }
        string s1="";
       for(int i=0;i<s[0].size();i++){
           for(int j=1;j<n;j++){
            if(s[0][i]==s[j][i]){
                flag=true;
            }
            else{
                return s1;
               }
           }
           if(flag){
               s1+=s[0][i];
           }
           
       }
        return s1;
    }
};