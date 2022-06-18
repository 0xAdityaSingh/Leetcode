class Solution {
public:
    int func(vector<int>h){
        int n=h.size();
        stack<int>s;
        vector<int>l(n);
        vector<int>r(n);
        for(int i=0;i<n;i++){
            while(!s.empty() and h[s.top()]>=h[i]) s.pop();
            if(s.empty()){
                l[i]=0;
                s.push(i);
            }
            else{
                l[i]=s.top()+1;
                s.push(i);
            }
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and h[s.top()]>=h[i]) s.pop();
            if(s.empty()){
                r[i]=h.size()-1;
                s.push(i);
            }
            else{
                r[i]=s.top()-1;
                s.push(i);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,h[i]*(r[i]-l[i]+1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>vec(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            vec[0][j]=(matrix[0][j] - '0');
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if((matrix[i][j] - '0')==0){
                    vec[i][j]=0;
                }
                else{
                    vec[i][j]=(matrix[i][j]- '0')+(vec[i-1][j]);    
                }
                
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,func(vec[i]));
        }
        return ans;
    }
};